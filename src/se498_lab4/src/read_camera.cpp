#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    VideoCapture video_capture(0); // Open the default camera

    if(!video_capture.isOpened()){ // Check if we succeeded
		std::cout << "Bug!!!" << std::endl;
    	return -1;
    }

    Mat gray_image, blurred_image, edge_image;

    //namedWindow("gray image", 1);



    while(true)
    {
        Mat frame;
        video_capture >> frame; // Get a new frame from camera

        // OpenCV image processing

        cvtColor(frame, gray_image, COLOR_BGR2GRAY);

	///////////////////////////////////////////////////////////////////////////
	//////////////////            Your code here            ///////////////////
	///////////////////////////////////////////////////////////////////////////
        for (int i = 1; i < 3; i+=2) GaussianBlur(frame, blurred_image, Size(i, i), 0, 0);
        Canny(blurred_image, edge_image, 100, 200);



	///////////////////////////////////////////////////////////////////////////

		// Show processed image
        //imshow("gray image", gray_image);
        imshow("Edge Image", edge_image);

        if(waitKey(30) >= 0) break;
    }

    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
