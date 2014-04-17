#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void rotate(Mat& image, Mat &rotated_img, double angle)
{
        angle = 3.14159 * angle / 180.0;
        Mat rotM2 = (Mat_<double>(2,3) << 0.5*cos(angle), -sin(angle), 0, sin(angle), 0.5*cos(angle), 0);
        warpAffine(image, rotated_img, rotM2, Size(image.cols*0.5, image.rows*0.5));
}
void main(void)
{    
    Mat image;    
    image = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (!image.empty())  {
        Mat rotated_img;
        rotate(image, rotated_img, 10);
        imwrite("rotated.jpg", rotated_img);
        imshow( "Rotated image", rotated_img ); 
        waitKey(0);
    }    
}
