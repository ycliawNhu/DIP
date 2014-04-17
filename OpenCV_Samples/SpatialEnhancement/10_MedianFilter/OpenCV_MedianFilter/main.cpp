#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
#define K_SIZE 3
void main(void)
{    
    Mat src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {
        Mat  dst;
		// median filter
		medianBlur(src, dst, K_SIZE);
		// shw images
        imshow( "Source", src );
        imshow( "Destination", dst );
        waitKey(0);
    }
}

