#include <stdio.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main( )
{

       Mat image;
       Mat gray_image, unblurred_edge_image, blurred_image, blurred_edge_image;

       // LOAD image
       image = imread("/home/user/catkin_ws/src/se498_lab4/images/tennisball.jpg", CV_LOAD_IMAGE_COLOR);

       if(!image.data)  // Check for invalid input
       {
              cout <<  "Could not open or find the image" << std::endl ;
              return -1;
       }

       //DISPLAY image
       //namedWindow( "window", CV_WINDOW_AUTOSIZE );   // Create a window for display.
       cvtColor(image, gray_image, COLOR_BGR2GRAY);

	///////////////////////////////////////////////////////////////////////////
	//////////////////            Your code here            ///////////////////
	///////////////////////////////////////////////////////////////////////////

	// To create an edge image you will use GaussianBlur() and Canny() function in OpenCV
	     Canny(image, unblurred_edge_image, 100, 200);

       // GaussianBlur(input image, output image, kernel size width & height (must be positive and odd), kernel standard dev in x, kernel standard dev in y)
       // here 11 is the max kernel length
       // based on example at https://docs.opencv.org/3.4/dc/dd3/tutorial_gausian_median_blur_bilateral_filter.html
       for (int i = 1; i < 11; i+=2) GaussianBlur(image, blurred_image, Size(i, i), 0, 0);
       Canny(blurred_image, blurred_edge_image, 100, 200);

	///////////////////////////////////////////////////////////////////////////



       imshow("Gray Image", gray_image); // Show image
       imshow("Edge Image without Gaussian Blur", unblurred_edge_image);
       imshow("Gaussian Blurred Image", blurred_image);
       imshow("Edge Image with Gaussian Blur", blurred_edge_image);

       //SAVE image to "/home/ros/catkin_NETID/src/se498_lab4/images/copy_image.jpg"
       imwrite("/home/user/catkin_ws/src/se498_lab4/images/copy_image.jpg", blurred_edge_image);
       imwrite("/home/user/catkin_ws/src/se498_lab4/images/unblurred_edge_image.jpg", unblurred_edge_image);


       waitKey(0);                       // Wait for a keystroke in the window

       return 0;
}
