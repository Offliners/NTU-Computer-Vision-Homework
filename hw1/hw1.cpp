#include<iostream>
#include<cmath>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	// read image 
	Mat img = imread("lena.bmp", CV_8UC1);

	// sample code : Lomo Effect
	int center_i = img.rows / 2;
	int center_j = img.cols / 2;
	double max_dist = sqrt(center_i*center_i + center_j*center_j);

	for (int i = 0; i < img.rows; i++) 
		for (int j = 0; j < img.cols; j++)
		{
			double dx = i - center_i;
			double dy = j - center_j;
			double dist = sqrt(dx*dx + dy*dy) / max_dist;
			img.at<uchar>(i, j) *= (1-dist)*(1 - dist);
		}
	
	// show image
	imshow("Lomo Effect", img);

	// write image 
	imwrite("lomoEffectLena.jpg", img);

	waitKey(0);
	return 0;
}