#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
#define C 1.2
#define GAMMA 0.5
void main(void)
{    
	// read image
    Mat src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {
        Mat  dst;
        Mat Channels[3];
		// pow law processing
        cvtColor(src, dst, CV_BGR2HSV);
        split(dst, Channels);
		Channels[2].convertTo(Channels[2], CV_32FC1, 1/255., 0);

		pow(Channels[2], GAMMA, Channels[2]);
		Channels[2] *= C;

		Channels[2].convertTo(Channels[2], CV_8UC1, 255, 0);
        merge(Channels, 3, dst);
        cvtColor(dst, dst, CV_HSV2BGR);
		// show images
        imshow( "Source", src );
        imshow( "Power", dst );
        waitKey(0);
    }
}

