



	
#include "stdafx.h"
#include <iostream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cmath>

	using namespace std;
using namespace cv;

float entropy(Mat seq, Size size, int index)
{

	float entr = 0;
	float total_size = size.height * size.width; //total size of all symbols in an image

	for (int i = 0; i<index; i++)
	{
		float sym_occur = seq.at<float>(0, i); //the number of times a sybmol has occured
		if (sym_occur>0) //log of zero goes to infinity
		{
			//cnt++;
			entr += (sym_occur / total_size)*(log2(total_size / sym_occur));
		}
	}

	return entr;

}

int main(int, char**)
{
	Mat gray = imread("C:/Users/Ashok Mehta/Downloads/rose-grayscale.jpg");
	namedWindow("Gray", 1);    imshow("Gray", gray);

	// Initialize parameters
	int histSize = 256;    // bin size
	float range[] = { 0, 255 };
	const float *ranges[] = { range };

	// Calculate histogram
	Mat hist;
	calcHist(&gray, 1, 0, Mat(), hist, 1, &histSize, &ranges, true, false);

	// Calculate histogram features

	for (int h = 0; h < histSize; h++)
	{
		float binVal = hist.at<float>(h);
		cout << " " << binVal;
	}
	int NM = gray.rows*gray.cols;
	float meang1 = 0.0;
	for (int h = 0; h < histSize; h++)
	{
		float binVal = hist.at<float>(h);
		binVal = binVal / NM;
		binVal = binVal *(float)h;
		meang1 += binVal;
	}
	cout << "Mean: " << meang1 << endl;
	float avgcont = 0.0;
	float skewness = 0.0;
	float kurtosis = 0.0;
	for (int h = 0; h < histSize; h++)
	{
		float binVal = hist.at<float>(h);
		avgcont += pow((h - meang1), 2)*(binVal / NM);
		skewness += pow((h - meang1), 3)*(binVal / NM);
		avgcont += pow((h - meang1), 4)*(binVal / NM) - 3;
	}
	skewness = skewness * pow(avgcont, -3);
	kurtosis = kurtosis * pow(avgcont, -4);
	float energy = 0.0;
		for(int h = 0; h < histSize; h++)
		{
			float binVal = hist.at<float>(h);
			binVal = binVal / NM;
			energy += pow(binVal, 2);
		}
	cout << "entropy: " << entropy(gray, gray.size(), histSize) << endl;
}
