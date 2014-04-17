#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void main(void)
{   
	// read image
    Mat src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {
        Mat  dst;
        Mat Channels[3];
		// log processing
        cvtColor(src, dst, CV_BGR2HSV);
        split(dst, Channels);
		Channels[2].convertTo(Channels[2], CV_32FC1, 1/255., 1);
		log(Channels[2], Channels[2]);
		Channels[2] /= log(2.0);
		Channels[2].convertTo(Channels[2], CV_8UC1, 255);
        merge(Channels, 3, dst);
        cvtColor(dst, dst, CV_HSV2BGR);
		// show images
        imshow( "Source", src );
        imshow( "Log", dst );
		imwrite("Log.jpg", dst);
        waitKey(0);
    }
}

