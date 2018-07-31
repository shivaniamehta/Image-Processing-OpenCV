#include "stdafx.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <ctime>  


using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	clock_t ini, fin;
	ini = clock();
	Mat src = imread("C:/Users/Ashok Mehta/Downloads/rose-grayscale.jpg");
	Mat dst;

	//Apply median filter
	medianBlur(src, dst, 15);
	imshow("source", src);
	imshow("result", dst);
	fin = clock();
	cout << "Time required " << (float)(fin - ini) / CLOCKS_PER_SEC;
	waitKey(0);
	return 0;
}