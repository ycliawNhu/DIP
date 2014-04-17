#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void main(void)
{    
    Mat_<Vec3b> src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {
        int i, j, k, channels = src.channels();
        Mat_<Vec3b> dst = src.clone();
        double val;
        for (i=0;i<src.rows;i++) {
                for (j=0;j<src.cols;j++) {
                        for (k=0;k<channels;k++) {
                              val = src(i,j)[k] / 255.0;
                              val = (log(1 + val) / log(2.0)) * 255;
                              if (val > 255) dst(i,j)[k] = 255;
                              else dst(i,j)[k] = (uchar) val;
                        }
                }
        }
		imshow( "Source", src);
        imshow( "Destination", dst );
        waitKey(0);
    }
}

