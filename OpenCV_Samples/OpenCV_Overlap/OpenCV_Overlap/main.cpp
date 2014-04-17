#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void getAlpha(Mat &img, Mat &alpha)
{   
    Mat bgra[4];
	split(img, bgra);
    bgra[3].copyTo(alpha);
}
void main(void)
{    
    Mat image, imageRoi, symbol, symAlpha, symRGB;

	image = imread("sample.bmp");
	symbol = imread("ball.png", -1); // -1 : Return the loaded image as is (with alpha channel). 
	if (image.data&&symbol.data) {
	    imageRoi = image(Rect(120,120,symbol.cols,symbol.rows));
    	cvtColor(symbol, symRGB, CV_BGRA2BGR);
	    symAlpha.create(symbol.rows, symbol.cols, CV_8UC1);
	    getAlpha(symbol, symAlpha);
	    symRGB.copyTo(imageRoi, symAlpha);
        imshow( "Sample", image); 
	    waitKey(0);
	}
}
