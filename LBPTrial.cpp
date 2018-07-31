#include "stdafx.h"
#include <iostream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cmath>

using namespace std;
using namespace cv;


int main(int argc, char** argv)
{
	Mat src, dst;

	Mat kernel;
	Point anchor;
	double delta;
	int ddepth;
	int kernel_size;

	src = imread("C:/Users/Ashok Mehta/Downloads/rose-grayscale.jpg");

	if (!src.data)
	{
		return -1;
	}
	namedWindow("Filter Demo", CV_WINDOW_AUTOSIZE);

	anchor = Point(-1, -1);
	delta = 0;
	ddepth = -1;
	kernel_size = 3;
	kernel = (Mat_<float>(3, 3)) << (1, 1, 1, 1, -8, 1, 1, 1, 1);
	/// Apply filter
	filter2D(src, dst, ddepth, kernel, anchor, delta, BORDER_REPLICATE);
	imshow("Filter Demo", dst);
	waitKey(0);




	return 0;
}