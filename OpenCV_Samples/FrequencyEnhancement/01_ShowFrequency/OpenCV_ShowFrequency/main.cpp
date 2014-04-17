#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void myDFT(Mat &f, Mat &F);
void swapFreq(Mat &F);
void main(void)
{
    Mat f = imread("sample.bmp", CV_LOAD_IMAGE_GRAYSCALE);
    if (f.data) {
        Mat F;
        myDFT(f, F);
        swapFreq(F);
        // compute the magnitude and switch to logarithmic scale, log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
        Mat planes[] = { Mat::zeros(F.size(), CV_32F), Mat::zeros(F.size(), CV_32F) };
        split(F, planes); // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
        magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
        planes[0] += Scalar::all(1); // switch to logarithmic scale
        log(planes[0], planes[0]);
        //show result
        normalize(planes[0], planes[0], 0, 1, CV_MINMAX);
        imshow("Result", planes[0]);
        normalize(planes[0], planes[0], 0, 255, CV_MINMAX);
        imwrite("ppp.bmp",planes[0]);
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


