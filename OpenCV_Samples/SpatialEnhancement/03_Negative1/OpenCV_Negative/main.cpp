#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void main(void)
{    
    Mat_<Vec3b> src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {
        int i, j, k, channels = src.channels();
        Mat_<Vec3b> dst = src.clone();
        for (i=0;i<src.rows;i++) {
             for (j=0;j<src.cols;j++) {
                  for (k=0;k<channels;k++) {
                       dst(i,j)[k] = 256 - 1 - src(i,j)[k];
                  }
             }
        }
        imshow( "Destination", dst ); 
        waitKey(0);
    }
}


