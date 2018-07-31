#include "stdafx.h"
#include <iostream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cmath>

using namespace std;
using namespace cv;

int main(int, char**)
{
	Mat src = imread("C:/Users/Ashok Mehta/Downloads/rose-grayscale.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst;
	cvtColor(src, src, CV_BGR2GRAY);
	cv::threshold(src, dst, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
	imshow("Result", dst);
	waitKey(0);
	return 0;
	
}