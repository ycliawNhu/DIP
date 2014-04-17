// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the OPENCV_MEANFILTER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// OPENCV_MEANFILTER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef OPENCV_MEANFILTER_EXPORTS
#define OPENCV_MEANFILTER_API extern "C" __declspec(dllexport)
#else
#define OPENCV_MEANFILTER_API extern "C" __declspec(dllimport)
#endif

OPENCV_MEANFILTER_API void MeanFilter(char *filename, int MaskSize);
