#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    VideoCapture video_capture(0); // Open the default camera

    if(!video_capture.isOpened()){ // Check if we succeeded
		std::cout << "Bug!!!" << std::endl;
    	return -1;
    }  

    Mat gray_image;

    namedWindow("gray image", 1);



    while(true)
    {
        Mat frame;
        video_capture >> frame; // Get a new frame from camera

        // OpenCV image processing 
        
        cvtColor(frame, gray_image, COLOR_BGR2GRAY);
        
	///////////////////////////////////////////////////////////////////////////
	//////////////////            Your code here            ///////////////////
	///////////////////////////////////////////////////////////////////////////
	

	
	
	///////////////////////////////////////////////////////////////////////////

		// Show processed image
        imshow("gray image", gray_image); 
        
        if(waitKey(30) >= 0) break;
    }

    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
