#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void main(void)
{    
    Mat src, dst; 
    src = imread("sample.bmp", CV_LOAD_IMAGE_GRAYSCALE);
    if (src.data )  {    
        // Compute and normalize the histogram
        int histSize = 256;
        float range[] = { 0, 256 } ;
        const float* histRange = { range };
        Mat hist;
        calcHist( &src, 1, 0, Mat(), hist, 1, &histSize, &histRange, true, false );
        normalize(hist, hist, 0, 389, NORM_MINMAX);
        // Draw the histogram
        int hist_w = 512, hist_h = 400, bin_w = cvRound( (double) hist_w/histSize );
        Mat histImage( hist_h, hist_w, CV_8UC1, Scalar(255) );
        for( int i = 0; i < histSize; i++ ) {
           line( histImage, Point( bin_w * i, 400 ) , Point( bin_w * i, hist_h - (int) hist.at<float>(i)), Scalar(0));
        }
        // Show Histogram
        imshow("Histogram", histImage );
        waitKey(0);
    }    
}
