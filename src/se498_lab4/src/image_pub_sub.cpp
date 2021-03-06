#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

static const std::string OPENCV_WINDOW = "Image Window";

class ImageConverter
{
	ros::NodeHandle nh_;
	image_transport::ImageTransport it_;
	image_transport::Subscriber image_sub_;
	image_transport::Publisher image_pub_;

	public:

		ImageConverter():it_(nh_) {
			// Subscribe to input video feed and publish output video feed
			image_sub_ = it_.subscribe("/usb_camera_node/image_raw", 1, &ImageConverter::imageCallback, this);
			image_pub_ = it_.advertise("/image_converter/output_video", 1);
			cv::namedWindow(OPENCV_WINDOW);
		}

		~ImageConverter() {
			cv::destroyWindow(OPENCV_WINDOW);
		}

		void imageCallback(const sensor_msgs::ImageConstPtr& msg) {

			cv_bridge::CvImagePtr cv_ptr;

			try
			{
			  cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
			}
			catch (cv_bridge::Exception& e)
			{
			  ROS_ERROR("cv_bridge exception: %s", e.what());
			  return;
			}

			// Draw an example circle on the video stream
			//if (cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60) {
			//  cv::circle(cv_ptr->image, cv::Point(50, 50), 10, CV_RGB(255,0,0));
			//}
			///////////////////////////////////////////////////////////////////////
			///////////////////         Your code here         ////////////////////
			///////////////////////////////////////////////////////////////////////

			cv::Mat temp_image;
			for (int i = 1; i < 3; i+=2) GaussianBlur(cv_ptr->image, temp_image, cv::Size(i, i), 0, 0);
			Canny(temp_image, cv_ptr->image, 100, 200);

			int centerX = cv_ptr->image.cols/2;
			int centerY = cv_ptr->image.rows/2;
			if (cv_ptr->image.rows > 120 && cv_ptr->image.cols > 120)
				cv::rectangle(cv_ptr->image, cv::Point(centerX-50, centerY-50), cv::Point(centerX+50, centerY+50), CV_RGB(255, 255, 255), 2);

			if (cv_ptr->image.rows > 10 && cv_ptr->image.cols > 10) {
				cv::line(cv_ptr->image, cv::Point(centerX-5, centerY), cv::Point(centerX+5, centerY), CV_RGB(255, 255, 255));
				cv::line(cv_ptr->image, cv::Point(centerX, centerY-5), cv::Point(centerX, centerY+5), CV_RGB(255, 255, 255));
			}

			///////////////////////////////////////////////////////////////////////

			// Update GUI Window
			cv::imshow(OPENCV_WINDOW, cv_ptr->image);

			///////////////////////////////////////////////////////////////////////
			///////////  Use the waitKey function to achieve image save  //////////
			///////////////////////////////////////////////////////////////////////
			char c = cv::waitKey(3);
			if (c == 's') imwrite("/home/user/catkin_ws/src/se498_lab4/images/video_still.jpg", cv_ptr->image);


			///////////////////////////////////////////////////////////////////////

			// Output modified video stream
			// Convert this message to a ROS sensor_msgs::Image message.
			image_pub_.publish(cv_ptr->toImageMsg());
		}
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_converter");
  ImageConverter ic;
  ros::spin();
  return 0;
}
