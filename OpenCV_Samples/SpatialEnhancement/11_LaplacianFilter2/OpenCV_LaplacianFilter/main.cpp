#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void main(void)
{    
    Mat src, dst; 
    src = imread("sample.bmp", CV_LOAD_IMAGE_COLOR);
    if (src.data )  {    
        Mat mask = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
        filter2D(src, dst, src.depth(), mask); 
		// show images
	    imshow( "Source", src );
        imshow( "Destination", dst ); 
        waitKey(0);
    }    
}


