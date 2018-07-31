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
	Mat src, dst;

	//char* source_window = "Source image";
	//char* equalized_window = "Equalized Image";

	/// Load image
	src = imread("C:/Users/Ashok Mehta/Downloads/rose-grayscale.jpg");

	if (!src.data)
	{
		cout << "Usage: ./Histogram_Demo <path_to_image>" << endl;
		return -1;
	}

	/// Convert to grayscale
	cvtColor(src, src, CV_BGR2GRAY);

	/// Apply Histogram Equalization
	equalizeHist(src, dst);

	/// Display results
	namedWindow("Source image", CV_WINDOW_AUTOSIZE);
	namedWindow("Equilized image", CV_WINDOW_AUTOSIZE);

	imshow("Source image", src);
	imshow("Equilized image", dst);
	fin = clock();
	cout << "Time required " << (float)(fin - ini) / CLOCKS_PER_SEC;
	/// Wait until user exits the program
	waitKey(0);

	return 0;
}