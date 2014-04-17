#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void myDFT(Mat &f, Mat &F);
void swapFreq(Mat &F);
void lowPassFilter(Mat &F);
void myIDFT(Mat &F, Mat &g);
void main(void)
{
    Mat f = imread("sample.bmp", CV_LOAD_IMAGE_GRAYSCALE);
    if (f.data) {
        Mat F, g;
        myDFT(f, F); //DCT
        lowPassFilter(F); //Frequency domain filtering
        myIDFT(F, g); //IDCT
        //show result
        normalize(g, g, 0, 1, CV_MINMAX);
        imshow("Result", g);
        waitKey();
    }
}

void myDFT(Mat &f, Mat &F)
{
    // expand input image to optimal size, and fill zero to the border
    Mat padded;                            
    int m = getOptimalDFTSize(f.rows);
    int n = getOptimalDFTSize(f.cols); 
    copyMakeBorder(f, padded, 0, m - f.rows, 0, n - f.cols,   BORDER_CONSTANT, Scalar::all(0));
    // allocate memory (2 planes, each for real and image parts) for storing fourier data
    Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
    merge(planes, 2, F);         
    // DFT
    dft(F, F);    
}

void myIDFT(Mat &F, Mat &g)
{
    Mat planes[] = { Mat::zeros(F.size(), CV_32F), Mat::zeros(F.size(), CV_32F) };
    idft(F, F, DFT_SCALE); 
    split(F, planes);
    g = planes[0].clone();
}

void swapFreq(Mat &F) 
{
    int cx = F.cols/2;
    int cy = F.rows/2;
    Mat q0(F, Rect(0, 0, cx, cy)); // Top-Left - Create a ROI per quadrant
    Mat q1(F, Rect(cx, 0, cx, cy)); // Top-Right
    Mat q2(F, Rect(0, cy, cx, cy)); // Bottom-Left
    Mat q3(F, Rect(cx, cy, cx, cy)); // Bottom-Right
    Mat tmp; // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp); // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);
}

void lowPassFilter(Mat &F) 
{
    Mat H(F.rows, F.cols, CV_32FC2, Scalar(0, 0));

    swapFreq(F);

	circle(H, Point(H.cols/2, H.rows/2), 200, Scalar::all(1), -1);
	F = F.mul(H);

    swapFreq(F);
}



