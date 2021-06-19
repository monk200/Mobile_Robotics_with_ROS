#include "cardriver/comnode.hpp"

void ComNode::testSendCMD(){
  cmd data;
  static int16_t i = 0;
  static int16_t j = 0;
  data.v_left = i;
  data.v_right = j;
  sendCMD(data);
  i++;
  j--;
//  std::vector<uint8_t> prebyte = {'i',0x20,0x0d,0x0a};
//  serialPtr->write(prebyte);
  //std::string result = serialPtr->read(40);
  //std::cout<<"We read: "<< result << std::endl;
}

/*!
 * \brief ComNode::timerCallback
 * timer triggers callback at a rate defined in setting.yaml
 * this function runs one at a time.
 * \param e
 */
void ComNode::timerCallback(const ros::SteadyTimerEvent& e)
{
//  static bool startFlag = false;
//  static bool stopFlag = true;
//  const static uint8_t startByte = (uint8_t)'*';
//  const static uint8_t stopByte = (uint8_t)'#';

//  //static temporary data structs
//  static cmd new_command = {0,0};
//  static id struct_id = NAT;

  static returnT current_values = {{0,0},{0},{0,0,0,0,0},{0,0,0},{0,0,0,0}};
  uint8_t data=0;
  if(serialPtr->read(&data,1))
  {
    id rtStruct = updateData(data,&current_values);
    switch (rtStruct) {
    case cmd_t:
      break;
    case ir_t:
    {
      cardriver::infrared msg;
      msg.left = current_values.irSensor.ir_left;
      msg.middle = current_values.irSensor.ir_middle;
      msg.right = current_values.irSensor.ir_right;
      msg.rearLeft = current_values.irSensor.ir_rear_left;
      msg.rearRight = current_values.irSensor.ir_rear_right;
      irPub.publish(msg);
    }
      break;
    case sw_t:
    {
      std_msgs::UInt8 msg;
      msg.data = current_values.switchSensor.switches;
      swPub.publish(msg);
    }
      break;
    case imu_t:
    {
      sensor_msgs::Imu msg;
      msg.orientation.x = current_values.imuSensor.roll;
      msg.orientation.y = current_values.imuSensor.pitch;
      msg.orientation.z = current_values.imuSensor.yaw;
      imuPub.publish(msg);
    }
    case encoder_t:
    {
      cardriver::encoder msg;
      msg.left = current_values.encoderSensor.left;
      msg.right = current_values.encoderSensor.right;
      msg.leftPos = current_values.encoderSensor.leftPos;
      msg.rightPos = current_values.encoderSensor.rightPos;
      encoderPub.publish(msg);
    }
      break;
    default:
      break;
    }
  }
}

/*!
 * \brief ComNode::ComNode
 * constructor, requires nodehandle passed from main function.
 * \param nh
 * \param r
 */
ComNode::ComNode(ros::NodeHandle &nh)
{
  try {
    // try to initialize parameter
    initParameter(nh);
    // setup serial communication
    initSerial();
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    return;
  }

  initROS(nh);
}

ComNode::~ComNode(){
  timer.stop();
  twistSub.shutdown();
  serialPtr->close();
}

/*!
 * \brief ComNode::initParameter
 * get parameter from parameter server and update all relevant variables
 * \param nh
 */
void ComNode::initParameter(ros::NodeHandle &nh)
{
  if(!nh.getParam("timer_rate",timerRate))
    throw exceptionParameterInit();
  if(!nh.getParam("baud_rate",baudRate))
    throw exceptionParameterInit();
  if(!nh.getParam("port",port))
    throw exceptionParameterInit();
  if(!nh.getParam("inter_byte_timeout",inter_byte_timeout))
    throw exceptionParameterInit();
  if(!nh.getParam("read_timeout_constant",read_timeout_constant))
    throw exceptionParameterInit();
  if(!nh.getParam("read_timeout_multiplier",read_timeout_multiplier))
    throw exceptionParameterInit();
  if(!nh.getParam("write_timeout_constant",write_timeout_constant))
    throw exceptionParameterInit();
  if(!nh.getParam("write_timeout_multiplier",write_timeout_multiplier))
    throw exceptionParameterInit();
  if(!nh.getParam("wheel_base_distance",wheel_base_distance))
    throw exceptionParameterInit();
  transRate = (baudRate/8)/timerRate;
}

/*!
 * \brief ComNode::initSerial
 * initialize serial port.
 */
void ComNode::initSerial()
{
  serialPtr.reset(new serial::Serial(port, baudRate,
                                     serial::Timeout(inter_byte_timeout,
                                                              read_timeout_constant,
                                                              read_timeout_multiplier,
                                                              write_timeout_constant,
                                                              write_timeout_multiplier)
                                     ));
  if(!serialPtr->isOpen())
    throw serial::PortNotOpenedException(" at initialization");
}

void ComNode::initROS(ros::NodeHandle &nh){
  // setup timer for steady callback based on timer rate.
  timer = nh.createSteadyTimer(ros::WallDuration(ros::Rate(timerRate)),&ComNode::timerCallback,this);
  twistSub = nh.subscribe("/cartCtrl",10,&ComNode::twistCallback,this );
  swPub = nh.advertise<std_msgs::UInt8>("/switches",1);
  irPub = nh.advertise<cardriver::infrared>("/infrared",1);
  imuPub = nh.advertise<sensor_msgs::Imu>("/imu",1);
  encoderPub = nh.advertise<cardriver::encoder>("/encoder",1);
}

/*!
 * \brief ComNode::twistCallback
 * car default frame is NED frame. therefore forward velocity is linear.x,
 * rotation velocity is angular.z
 * msg in m/s (float)
 * cmd in mm/s (int16_t)
 * \param msg
 */
void ComNode::twistCallback(const geometry_msgs::Twist::ConstPtr& msg){
  float vl = msg->linear.x - (msg->angular.z * wheel_base_distance) / 2.0;
  float vr = msg->linear.x + (msg->angular.z * wheel_base_distance) / 2.0;

  cmd command;
  // abs speed range (100 ~ 2400)
  command.v_left = vl;
  command.v_right = vr;
  //std::cout << "left speed: " << command.v_left << std::endl;
  //std::cout << "right speed: " << command.v_right << std::endl;
  sendCMD(command);
}

/*!
 * \brief ComNode::enumeratePorts
 * enumeratePorts and print ports that are available.
 */
void ComNode::enumeratePorts()
{
  std::vector<serial::PortInfo> devices_found = serial::list_ports();

  std::vector<serial::PortInfo>::iterator iter = devices_found.begin();

  while( iter != devices_found.end() )
  {
    serial::PortInfo device = *iter++;

    printf( "(port name: %s, device description: %s, hardware_id: %s)\n", device.port.c_str(), device.description.c_str(),
            device.hardware_id.c_str() );
  }
}

bool ComNode::sendCMD(cmd &cmd_data)
{
  std::size_t size = sizeof(cmd);
  //const static std::vector<uint8_t> prebyte = {'m',(uint8_t)(cmd_data.v_left >> 8),(uint8_t)(cmd_data.v_left & 0xff),(uint8_t)(cmd_data.v_right >> 8),(uint8_t)(cmd_data.v_right & 0xff)};

  std::vector<uint8_t> prebyte = {'m',(uint8_t)(cmd_data.v_left >> 8),(uint8_t)(cmd_data.v_left & 0xff),(uint8_t)(cmd_data.v_right >> 8),(uint8_t)(cmd_data.v_right & 0xff),0x0d,0x0a};

//  uint8_t data[size];
  std::vector<uint8_t> data(size);
  uint16_t index = 0;
  for(auto&& i : data){
    i = readCMD(&cmd_data,index);
    ++index;
  }

  //std::vector<uint8_t> prebyte_data_post;
  //prebyte_data_post.reserve(prebyte.size()+data.size()+1);
  //prebyte_data_post.insert(prebyte_data_post.end(),prebyte.begin(),prebyte.end());
  //prebyte_data_post.insert(prebyte_data_post.end(),data.begin(),data.end());
  //prebyte_data_post.insert(prebyte_data_post.end(),'#');

  serialPtr->write(prebyte);
  std::string result = serialPtr->read(40);
  std::cout<<"We read: "<< result << std::endl;
  return true;
}
