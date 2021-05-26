/*
 * structs.c
 *
 *  Created on: Dec 6, 2018
 *      Author: jifei
 */
#include "structs.h"

#ifdef __cplusplus
extern "C" {
//#else
//#include "cardriver/include/cardriver/structs.h"
#endif
/* general */

/*  checkSize need to be updated whenever a new structure is defined.
 *
 */
bool checkSize(id type, uint16_t size){
  switch (type) {
  case NAT:
    return (size == 0);
  case cmd_t:
    return (size == 4);
  case sw_t:
    return (size == 1);
  case ir_t:
    return (size == 5);
  case imu_t:
    return (size == 6);
  case encoder_t:
    return (size == 8);
  default:
    return false;
  }
}

/* CMD */
void writeCMD(cmd* p_cmd, uint8_t byte, uint16_t index)
{
  switch (index) {
  case 0: //MS of v_left
    p_cmd->v_left = (p_cmd->v_left & 0x00ff) | ( ((uint16_t)byte) << 8 );
    break;
  case 1: //LS of v_left
    p_cmd->v_left = (p_cmd->v_left & 0xff00) | (uint16_t)byte;
    break;
  case 2: //MS of v_right
    p_cmd->v_right = (p_cmd->v_right & 0x00ff) | ( ((uint16_t)byte) << 8);
    break;
  case 3: //LS of v_right
    p_cmd->v_right = (p_cmd->v_right & 0xff00) | ((uint16_t)byte);
    break;
  default:
    break;
  }
}
uint8_t readCMD(cmd* p_cmd, uint16_t index)
{
  switch (index) {
  case 0: //MS of v_left
    return p_cmd->v_left >> 8;
  case 1: //LS of v_left
    return p_cmd->v_left & 0xff;
  case 2: //MS of v_right
    return p_cmd->v_right >> 8;
  case 3: //LS of v_right
    return p_cmd->v_right & 0xff;
  default:
    return 0;
  }
}

/* SW */
void writeSW(sw* p_sw, uint8_t byte)
{
  p_sw->switches = byte;
}
uint8_t readSW(sw* p_sw)
{
  return p_sw->switches;
}
/* IR */
void writeIR(ir* p_ir, uint8_t byte, uint16_t index)
{
  switch (index) {
  case 0:
    p_ir->ir_left = byte;
    break;
  case 1:
    p_ir->ir_middle = byte;
    break;
  case 2:
    p_ir->ir_right = byte;
    break;
  case 3:
    p_ir->ir_rear_left = byte;
    break;
  case 4:
    p_ir->ir_rear_right = byte;
    break;
  default:
    break;
  }
}
uint8_t readIR(ir* p_ir, uint16_t index)
{
  switch (index) {
  case 0:
    return p_ir->ir_left;
  case 1:
    return p_ir->ir_middle;
  case 2:
    return p_ir->ir_right;
  case 3:
    return p_ir->ir_rear_left;
  case 4:
    return p_ir->ir_rear_right;
  default:
    return 0;
  }
}
/* IMU */
void writeIMU(imu* p_imu, uint8_t byte, uint16_t index)
{
  switch (index) {
  case 0: // MS byte
    p_imu->roll = ( p_imu->roll & 0x00ff) | ( ((uint16_t)byte) << 8 );
    break;
  case 1: // LS byte
    p_imu->roll = ( p_imu->roll & 0xff00) | (uint16_t)byte;
    break;
  case 2:
    p_imu->pitch = ( p_imu->pitch & 0x00ff) | ( ((uint16_t)byte) << 8 );
    break;
  case 3:
    p_imu->pitch = ( p_imu->pitch & 0xff00) | (uint16_t)byte;
    break;
  case 4:
    p_imu->yaw = ( p_imu->yaw & 0x00ff) | ( ((uint16_t)byte) << 8 );
    break;
  case 5:
    p_imu->yaw = ( p_imu->yaw & 0xff00) | (uint16_t)byte;
    break;
  default:
    break;
  }
}
uint8_t readIMU(imu* p_imu, uint16_t index)
{
  switch(index) {
  case 0: // MS byte
    return p_imu->roll >> 8;
  case 1: // LS byte
    return p_imu->roll & 0xff;
  case 2:
    return p_imu->pitch >> 8;
  case 3:
    return p_imu->pitch & 0xff;
  case 4:
    return p_imu->yaw >> 8;
  case 5:
    return p_imu->yaw & 0xff;
  default:
    return 0;
  }
}
/* ENCODER */
void writeEncoder(encoder* p_encoder, uint8_t byte, uint16_t index)
{
  switch (index) {
  case 0: // MS byte
    p_encoder->left = ( p_encoder->left & 0x00ff) | ( ((uint16_t)byte) << 8 );
    break;
  case 1: // LS byte
    p_encoder->left = ( p_encoder->left & 0xff00) | (uint16_t)byte;
    break;
  case 2:
    p_encoder->right = ( p_encoder->right & 0x00ff) | ( ((uint16_t)byte) << 8 );
    break;
  case 3:
    p_encoder->right = ( p_encoder->right & 0xff00) | (uint16_t)byte;
    break;
  case 4:
    p_encoder->leftPos = ( p_encoder->leftPos & 0x00ff) | ( ((uint16_t)byte) << 8 );
    break;
  case 5:
    p_encoder->leftPos = ( p_encoder->leftPos & 0xff00) | (uint16_t)byte;
    break;
  case 6:
    p_encoder->rightPos = ( p_encoder->rightPos & 0x00ff) | ( ((uint16_t)byte) << 8 );
    break;
  case 7:
    p_encoder->rightPos = ( p_encoder->rightPos & 0xff00) | (uint16_t)byte;
    break;
  default:
    break;
  }
}
uint8_t readEncoder(encoder* p_encoder, uint16_t index)
{
  switch(index) {
  case 0: 
    return p_encoder->left >> 8;
  case 1: 
    return p_encoder->left & 0xff;
  case 2:
    return p_encoder->right >> 8;
  case 3:
    return p_encoder->right & 0xff;
  case 4: 
    return p_encoder->leftPos >> 8;
  case 5: 
    return p_encoder->leftPos & 0xff;
  case 6:
    return p_encoder->rightPos >> 8;
  case 7:
    return p_encoder->rightPos & 0xff;
  default:
    return 0;
  }
}

/*!
 * data: [ start_byte, MS_size,LS_size,struct_id,data,...,stop_byte]
 */
id updateData(uint8_t data, returnT* rvalues){
  static bool startFlag = false;
  static bool stopFlag = true;
  const static uint8_t startByte = (uint8_t)START_CHAR;
  const static uint8_t stopByte = (uint8_t)STOP_CHAR;
  static returnT new_rvalues ={ {0,0},{0},{0,0,0,0,0},{0,0,0}, }; //#### more struct, more initializer? { {0,0} }
  static id struct_id = NAT;
  static uint16_t countByte = 0;
  static uint16_t totalByte = 0;
  uint16_t dataIndex;

  //start of a reading sequence
  //printf("data: %c \r\n",data);
  if(data == startByte && stopFlag == true){
    startFlag = true;
    stopFlag = false;
    countByte = 0;
    totalByte = 0;
    new_rvalues = *rvalues;
    // set receiving data structure to current values;
  }
  if(startFlag == true){
    switch (countByte) {
    case 0:
      break;
    case 1:
      totalByte = data << 8;
      break;
    case 2:
      totalByte += (uint16_t)data;
      break;
    case 3:
      struct_id = (id)data;
      if(!checkSize(struct_id,totalByte)){
        startFlag = false;
        stopFlag = true;
      }
      // initialize all the data variable, before updating
      switch (struct_id) {
      case cmd_t:
        new_rvalues.command.v_left =0;
        new_rvalues.command.v_right=0;
        break;
      case sw_t:
        new_rvalues.switchSensor.switches = 0;
        break;
      case ir_t:
        new_rvalues.irSensor.ir_left = 0;
        new_rvalues.irSensor.ir_middle = 0;
        new_rvalues.irSensor.ir_right = 0;
        new_rvalues.irSensor.ir_rear_left = 0;
        new_rvalues.irSensor.ir_rear_right = 0;
        break;
      case imu_t:
        new_rvalues.imuSensor.roll = 0;
        new_rvalues.imuSensor.pitch = 0;
        new_rvalues.imuSensor.yaw = 0;
        break;
      case encoder_t:
        new_rvalues.encoderSensor.left = 0;
        new_rvalues.encoderSensor.right = 0;
        new_rvalues.encoderSensor.leftPos = 0;
        new_rvalues.encoderSensor.rightPos = 0;
        break;
      case NAT:
        break;
      }
      break;
    default:
      dataIndex = countByte-4;
      if(data == stopByte && dataIndex == totalByte){
        startFlag = false;
        stopFlag = true;
        switch (struct_id) {
        case cmd_t:
          rvalues->command = new_rvalues.command;
          break;
        case sw_t:
          rvalues->switchSensor = new_rvalues.switchSensor;
          break;
        case ir_t:
          rvalues->irSensor = new_rvalues.irSensor;
          break;
        case imu_t:
          rvalues->imuSensor = new_rvalues.imuSensor;
        case encoder_t:
          rvalues->encoderSensor = new_rvalues.encoderSensor;
        default:
          break;
        }
        return struct_id;
      }
      else if (dataIndex > totalByte){
        startFlag = false;
        stopFlag = true;
      }
      else{
        switch (struct_id) {
        case cmd_t:
          writeCMD(&new_rvalues.command, data,dataIndex);
          break;
        case sw_t:
          writeSW(&new_rvalues.switchSensor, data);
          break;
        case ir_t:
          writeIR(&new_rvalues.irSensor, data, dataIndex);
          break;
        case imu_t:
          writeIMU(&new_rvalues.imuSensor,data,dataIndex);
          break;
        case encoder_t:
          writeEncoder(&new_rvalues.encoderSensor,data,dataIndex);
        case NAT:
        default:
          break;
        }
      }
      break;
    }
    countByte++;
  }
  return NAT;
}

#ifdef __cplusplus
} // closing brace for extern "C"
#endif
