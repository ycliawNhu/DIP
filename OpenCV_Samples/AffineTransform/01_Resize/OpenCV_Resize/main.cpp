#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void main(void)
{    
    Mat image;    
    image = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (!image.empty())  {
        resize(image, image, Size(), 0.5, 0.5, INTER_NEAREST); 
        imshow( "Display window", image ); 
        waitKey(0);
    } else {
        cout <<  "Could not open or find the image" << std::endl ;        
    }    
}
