#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void main(void)
{    
    Mat src, dst; 
    src = imread("sample.bmp", CV_LOAD_IMAGE_GRAYSCALE);
    if (src.data )  {    
        Mat mask = (Mat_<double>(3,3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
        filter2D(src, dst, src.depth(), mask); 
		// show images
	    imshow( "Source", src );
        imshow( "Destination", dst ); 
        waitKey(0);
    }    
}


