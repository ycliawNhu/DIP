#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void main(void)
{    
    Mat src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {
		Mat dst;
		threshold(src, dst, 128, 255, THRESH_BINARY);
        imshow( "Destination", dst ); 
        waitKey(0);
    }
}