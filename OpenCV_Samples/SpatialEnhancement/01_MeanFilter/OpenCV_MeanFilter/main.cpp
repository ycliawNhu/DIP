#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
#define MASK_SIZE 5
void main(void)
{    
    Mat src, dst; 
    src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {       
        Mat mask = Mat::ones(MASK_SIZE, MASK_SIZE, CV_32F)/ (float)(MASK_SIZE*MASK_SIZE);
        filter2D(src, dst, src.depth(), mask, Point(MASK_SIZE/2, MASK_SIZE/2)); 
        imshow( "Source", src ); 
        imshow( "Destination", dst ); 
        waitKey(0);
    } else {
        cout <<  "Could not open or find the image" << std::endl ;        
    }    
}
