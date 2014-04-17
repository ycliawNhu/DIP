#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
#define PERCENT 1
void main(void)
{    
    Mat src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {
		// add salt and pepper noise
		Mat noise = Mat::zeros(src.rows, src.cols, CV_8U);
		randu(noise, 0, 255);
		Mat black = noise < 2.55*PERCENT;
		Mat white = noise > 255-2.55*PERCENT;
		Mat noiseImg = src.clone();
		noiseImg.setTo(255,white);
		noiseImg.setTo(0,black);
		// show images
        imshow( "Source", src );
        imshow( "Noise Image", noiseImg );
        waitKey(0);
    }
}

