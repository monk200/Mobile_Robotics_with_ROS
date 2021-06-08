#include <stdio.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;
 
int main( )
{
 
       Mat image;
       Mat gray_image;
		
       // LOAD image
       image = imread("/home/user/catkin_ws/src/se498_lab4/images/tennisball.jpg", CV_LOAD_IMAGE_COLOR);  

       if(!image.data)  // Check for invalid input
       {
              cout <<  "Could not open or find the image" << std::endl ;
              return -1;
       }

       //DISPLAY image
       namedWindow( "window", CV_WINDOW_AUTOSIZE );   // Create a window for display.
       cvtColor(image, gray_image, COLOR_BGR2GRAY);

	///////////////////////////////////////////////////////////////////////////
	//////////////////            Your code here            ///////////////////
	///////////////////////////////////////////////////////////////////////////
	
	// To create an edge image you will use GaussianBlur() and Canny() function in OpenCV
	
	
	///////////////////////////////////////////////////////////////////////////


   
       imshow("window", gray_image); // Show image

       //SAVE image to "/home/ros/catkin_NETID/src/se498_lab4/images/copy_image.jpg"



       waitKey(0);                       // Wait for a keystroke in the window
       
       return 0;
}
