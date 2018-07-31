#include "stdafx.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include <iostream>
#include "C:\Users\Ashok Mehta\Downloads\opencv\build\include\opencv2\core\cuda.hpp"
#include "C:\Users\Ashok Mehta\Downloads\opencv\build\include\opencv2\core\cudaarithm.hpp"

using namespace cv;

int main(int argc, char* argv[])
{
	
		cv::Mat src_host = cv::imread("C:/Users/Ashok Mehta/Desktop/grayscale.png", IMREAD_GRAYSCALE);
		cv::cuda::GpuMat dst, src;
		src.upload(src_host);

		cv::cuda::threshold(src, dst, 128.0, 255.0, THRESH_BINARY);

		cv::Mat result_host;
		dst.download(result_host);
		cv::imshow("Result", result_host);
		cv::waitKey();
	

	return 0;
}