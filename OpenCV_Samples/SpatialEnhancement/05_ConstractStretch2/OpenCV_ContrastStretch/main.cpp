#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
#define SLOPE1 0.5
#define SLOPE2 2
#define SLOPE3 0.5
void main(void)
{    
    Mat src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {
        Mat  dst;
        Mat Channels[3];
		int i;
        double val = 0.0;
        Mat_<uchar> table(1,256);
		// generate look-up table
		for (i=0;i<64;i++) {
			table(0,i) = (uchar)val;
			if ((val += SLOPE1) > 255) val = 255;
		}
		for (;i<192;i++) {
			table(0,i) = (uchar)val;
			if ((val += SLOPE2) > 255) val = 255;
		}
		for (;i<256;i++) {
			table(0,i) = (uchar)val;
			if ((val += SLOPE3) > 255) val = 255;
		}
		// mapping process
        split(src, Channels);
		LUT(Channels[0], table, Channels[0]);
		LUT(Channels[1], table, Channels[1]);
		LUT(Channels[2], table, Channels[2]);
        merge(Channels, 3, dst);
        // show images
        imshow( "Source", src ); 
        imshow( "Destination", dst );
        waitKey(0);
    }
}

