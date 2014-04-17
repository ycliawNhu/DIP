#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void main(void)
{    
    Mat src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {
        Mat dst1, dst2, Channels[3];
        split(src, Channels);
        equalizeHist( Channels[0], Channels[0] );
        equalizeHist( Channels[1], Channels[1] );
        equalizeHist( Channels[2], Channels[2] );
        merge(Channels, 3, dst1);
        cvtColor(src, dst2, CV_BGR2HSV);
        split(dst2, Channels);
        equalizeHist( Channels[2], Channels[2] );
        merge(Channels, 3, dst2);
        cvtColor(dst2, dst2, CV_HSV2BGR);
        imshow( "Source", src );
        imshow( "HR-RGB", dst1 );
		imshow( "HR-HSV", dst2 );
        waitKey(0);
    }
}

