#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
#define SLOPE1 0.5
#define SLOPE2 2
#define SLOPE3 0.5
void main(void)
{    
    Mat_<Vec3b> src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {
        int i, j, k, channels = src.channels();
        Mat_<Vec3b> dst = src.clone();
        double val = 0.0;
        uchar table[256];
        for (i=0;i<64;i++) {
             table[i] = (uchar)val;
             if ((val += SLOPE1) > 255) val = 255;
        }
        for (;i<192;i++) {
             table[i] = (uchar)val;
             if ((val += SLOPE2) > 255) val = 255;
        }
        for (;i<256;i++) {
             table[i] = (uchar)val;
             if ((val += SLOPE3) > 255) val = 255;
        }
        for (i=0;i<src.rows;i++) {
             for (j=0;j<src.cols;j++) {
                  for (k=0;k<channels;k++) {
                       dst(i,j)[k] = table[src(i,j)[k]];
                  }
             }
        }
        imshow( "Source", src ); 
        imshow( "Destination", dst );
        waitKey(0);
    }
}

