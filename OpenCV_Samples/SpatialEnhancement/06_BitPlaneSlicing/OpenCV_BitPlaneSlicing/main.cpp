#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void main(void)
{    
    Mat_<uchar> src = imread("sample.bmp", CV_LOAD_IMAGE_GRAYSCALE);
    char Name[] = "Bit ?";
    if (src.data )  {
        int i, j, b;
        Mat_<uchar> dsts[8];
        for (i=0;i<8;i++) {
            dsts[i] = Mat::zeros(src.rows, src.cols, CV_8UC1);
        }
        for (i=0;i<src.rows;i++) {
             for (j=0;j<src.cols;j++) {
                  for (b=0;b<8;b++) {
                       dsts[b](i,j) = ((src(i,j) >> b) & 1) << 7;
                  }
             }
        }
        for (b=0;b<8;b++) {
             Name[4] = '0' + b;
             imshow( Name, dsts[b] );
        }
        waitKey(0);
    }
}