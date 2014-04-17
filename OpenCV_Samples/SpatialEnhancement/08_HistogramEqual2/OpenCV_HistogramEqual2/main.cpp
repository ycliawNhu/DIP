#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void main(void)
{    
    Mat src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {
        Mat  dst;
        Mat Channels[3];
        cvtColor(src, dst, CV_BGR2HSV);
        split(dst, Channels);
        equalizeHist( Channels[2], Channels[2] );
        merge(Channels, 3, dst);
        cvtColor(dst, dst, CV_HSV2BGR);
        imshow( "Source", src );
        imshow( "Destination", dst );
        waitKey(0);
    }
}

