#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src, dst;
	int *hist, *sum_of_hist;
	double *p;
	int k, t, sum = 0, bar = 300, smallS=1000;

	//src = imread("citrus.bmp", IMREAD_GRAYSCALE); // Read the file
	//src = imread("Mandrill.bmp", IMREAD_GRAYSCALE); // Read the file
	src = imread("coin.bmp", IMREAD_GRAYSCALE); // Read the file
	dst = Mat::zeros(src.size(), src.type());
	if (src.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	/*
	for (int i = 0; i < src.size().height; i++) //indexing
		for (int j = 0; j < src.size().width; j++)
		{
			dst.at<uchar>(i, j) = src.at<uchar>(i, j) + 30; //output에 집어넣어
		}
	*/

	t = src.size().height * src.size().width; //전체개수 t

	printf("%d %d %d\n", src.size().height, src.size().width, t);
	hist = (int*)malloc(sizeof(int)* t);
	p = (double*)malloc(sizeof(double)*t);
	sum_of_hist = (int*)malloc(sizeof(int)* t);

	for (int i = 0; i < t; i++)
	{
		hist[i] = 0;
		sum_of_hist[i] = 0;
	}
	for (int i = 0; i < src.size().height; i++)
		for (int j = 0; j < src.size().width; j++)
		{
			k = src.at<uchar>(i, j);
			hist[k] = hist[k] + 1;
		}

	for (int i = 0; i < 256; i++)
	{
		sum = sum + hist[i];
		sum_of_hist[i] = sum;
	}

	for (int i = 0; i < 256; i++)
	{
		p[i] = (double)hist[i] / (double)t;
		//printf("%lf ", p[i]);
	}

	for (int k = 0; k < 256; k++) {
		double w0 = 0, w1 = 0;
		double m0 = 0, m1 = 0;
		double s0 = 0, s1 = 0;
		double s;
		
		for (int i = 0; i < k; i++)
			w0 = w0 + p[i];
		for (int i = k + 1; i < 256; i++)
			w1 = w1 + p[i];

		for (int i = 0; i < k; i++)
			m0 = (double)i * p[i] / w0 + m0;
		for (int i = k + 1; i < 256; i++)
			m1 = (double)i * p[i] / w1 + m1;

		for (int i = 0; i < k; i++)
			s0 = ((double)i - m0)*((double)i - m0) * p[i] / w0 + s0;
		for (int i = k + 1; i < 256; i++)
			s1 = ((double)i - m1)*((double)i - m1) * p[i] / w1 + s1;

		s = (w0 * s0) + (w1 * s1);
		//printf("%lf ", s);
		if (s <= smallS)
		{
			smallS = s;
			bar = k;
		}
		//printf("%d %d\n", smallS, bar);
	}
	printf("%d", bar);

	//bar = 109;
	for (int i = 0; i < src.size().height; i++)
		for (int j = 0; j < src.size().width; j++)
		{
			k = src.at<uchar>(i, j);

			if (k > bar)
				dst.at<uchar>(i, j) = 255;
			else
				dst.at<uchar>(i, j) = 0;
		}


	/*
	printf("%d\n", t);
	a = 256 / double(65536);
	b = 256 / 65536;
	printf("%f\n", a);
	printf("%d\n", b);

	for (int i = 0; i < 256; i++)
	{
	printf("%d: %d \n", i, hist[i]);
	printf("%d: %d \n", i, sum_of_hist[i]);
	}

	printf("%d\n", t);
	*/

	/* 출력 */
	
	namedWindow("source", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("source", src); // Show our image inside it.

	namedWindow("result", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("result", dst); // Show our image inside it. 결정된 값 보여줘
	imwrite("outImage.bmp", dst); //이 이름으로 저장할래.

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}