#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <time.h>
using namespace cv;
using namespace std;
void imageProcess(Mat &src);
int main( int argc, char** argv )
{
	// Create a VideoCapture object to read frames from a video file
    VideoCapture inStream("sample.avi");
    if (inStream.isOpened())
    {
		// create a VideoWriter object to write frames to a video file
        int ex = static_cast<int>(inStream.get(CV_CAP_PROP_FOURCC));     
        Size S = Size((int) inStream.get(CV_CAP_PROP_FRAME_WIDTH), (int) inStream.get(CV_CAP_PROP_FRAME_HEIGHT));
		VideoWriter outStream("out.avi", ex, inStream.get(CV_CAP_PROP_FPS), S, true);
		if (outStream.isOpened()) {
            Mat source;
			while(1) { 
				//read a frame
				inStream >> source;
				if(!source.empty()) {
					//process the frame
					imageProcess(source);
					//write the processed frame
					outStream << source;
					//show the processed frame on screen
					imshow("Source", source);
 				    waitKey(1);
				} else {
					break;
				}
			}
		} else cout  << "Fail to open the output stream." << endl;
	} else cout << "Fail to open the input stream." << endl;
}

void SaltAndPepperNoise(Mat &src)
{
		Mat noise = Mat::zeros(src.rows, src.cols, CV_8U);
		randu(noise, 0, 255);
		Mat black = noise < 2;
		Mat white = noise > 253;
		src.setTo(255,white);
		src.setTo(0,black);
}

#define MASK_SIZE 5
void imageProcess(Mat &src)
{
    Mat  dst;
    Mat Channels[3];

    cvtColor(src, src, CV_BGR2GRAY);
    SaltAndPepperNoise(src);
    Mat mask = Mat::ones(MASK_SIZE, MASK_SIZE, CV_32F)/ (float)(MASK_SIZE*MASK_SIZE);
    filter2D(src, src, src.depth(), mask, Point(MASK_SIZE/2, MASK_SIZE/2)); 
	cvtColor(src, src, CV_GRAY2BGR);
}
