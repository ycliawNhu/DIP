#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void main(void)
{    
	// read image
    Mat src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {
        Mat  dst;
        dst = Scalar(255, 255, 255) - src;
		// show images
        imshow( "Source", src );
        imshow( "Power", dst );
        waitKey(0);
    }
}

