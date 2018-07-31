#include "stdafx.h"
#include <iostream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core.hpp"
#include "C:\Users\Ashok Mehta\Downloads\opencv\build\include\opencv2\core\cudaarithm.hpp"
#include "opencv2/opencv.hpp"
#include <cmath>

using namespace std;
using namespace cv;

int main(int, char**)
{
	Mat src_host = imread("C:/Users/Ashok Mehta/Downloads/rose-grayscale.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	cv::cuda::GpuMat dst, src;
	src.upload(src_host);
	cv::cuda::threshold(src, dst, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	cv::Mat result_host(dst);
	cv::imshow("Result", result_host);
	cv::waitKey(0);
	return 0;


}