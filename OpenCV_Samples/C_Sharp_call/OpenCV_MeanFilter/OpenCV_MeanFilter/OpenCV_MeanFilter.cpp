// OpenCV_MeanFilter.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "OpenCV_MeanFilter.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;


// This is an example of an exported function.
OPENCV_MEANFILTER_API void MeanFilter(char *filename, int maskSize)
{
    Mat src, dst; 
    src = imread(filename, CV_LOAD_IMAGE_COLOR);
    if (src.data )  {       
        Mat mask = Mat::ones(maskSize, maskSize, CV_32F)/ (float)(maskSize * maskSize);
        filter2D(src, dst, src.depth(), mask, Point(maskSize/2, maskSize/2)); 
        imshow( "Source", src ); 
        imshow( "Destination", dst ); 
        waitKey(0);
    } 
}


