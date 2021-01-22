#include "stdafx.h"
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <math.h>
#define PI 3.14159265
using namespace std;
using namespace cv;
int main(int argc, char* argv[])
{
	Mat src, dst, dst2;
	src = imread("edge.png", IMREAD_GRAYSCALE); // Read the file
	dst = Mat::zeros(256 * 2 + 1, 100, src.type());

	if (src.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	int cm[256 * 2 + 1][100];
	double rho, theta;
	int r;
	int lx, rx, ty, by;

	printf("%d %d\n\n", src.size().width, src.size().height);

	for (int i = 0; i<256 * 2 + 1; i++)
		for (int j = 0; j<100; j++)
			cm[i][j] = 0;

	for (int i = 0; i<src.size().height; i++)
		for (int j = 0; j < src.size().width; j++)
		{
			if (src.at<uchar>(i, j) == 255)
			{
				//printf("%d,%d \n", i, j);
				for (int t = 0; t<100; t++)
				{
					theta = PI / 100 * t;
					rho = double(j)*cos(theta) + double(i)*sin(theta);
					r = 256 - int(rho + 0.5);
					cm[r][t] = cm[r][t] + 1;
					//printf("%d ", r);
					dst.at<uchar>(r, t) = 255;

				}
			}
		}

	int max_num = 0;
	int r_loc;
	int t_loc;
	for (int i = 0; i<256 * 2 + 1; i++)
		for (int j = 0; j<100; j++)
			if (cm[i][j]>max_num)
			{
				max_num = cm[i][j];
				r_loc = i;
				t_loc = j;
				//printf("%d, ",cm[i][j]);
			}
	theta = PI / 100 * t_loc;
	//r = 256 - int(rho + 0.5);
	rho = 256 - r_loc;
	//rho = r_loc;
	printf("%d \n", max_num);
	printf("%f, %f, %f, %f", theta, rho, -cos(theta) / sin(theta), rho / sin(theta));

	int y;
	for (int j = 0; j<src.size().width; j++)
	{
		y = -cos(theta) / sin(theta)*j + rho / sin(theta);
		if (int(y + 0.5) > 0 && int(y + 0.5) < 256)
			src.at<uchar>(int(y + 0.5), j) = 255;
	}

	namedWindow("result0", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("result0", src); // Show our image inside it.

	namedWindow("result", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("result", dst); // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}