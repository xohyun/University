#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
int ostu(int *hist);
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("rice.png", IMREAD_GRAYSCALE); // Read the file
	dst = Mat::zeros(src.size() * 3, src.type() * 3);
	
	double i2, j2;
	int m1, m2;
	int a, b, c, d, p;
	double alpha, beta;
	
	for (int i = 0; i < dst.size().height - 1; i++)
	{
		for (int j = 0; j < dst.size().width - 1; j++)
		{
			i2 = (double)i / 3;
			j2 = (double)j / 3;
			
			if (ceil(i2) < src.size().height && ceil(j2) < src.size().width)
			{
				a = src.at<uchar>(floor(i2), floor(j2));
				b = src.at<uchar>(ceil(i2), floor(j2));
				c = src.at<uchar>(floor(i2), ceil(j2));
				d = src.at<uchar>(ceil(i2), ceil(j2));
			}
			
			alpha = (double)i2 - floor(i2);
			m1 = alpha * b + (1 - alpha) * a;
			m2 = alpha * d + (1 - alpha) * c;
			beta = j2 - floor(j2);
			p = beta * m2 + (1 - beta) * m1;
			dst.at<char>(i, j) = p;
		}
	}
	namedWindow("source", WINDOW_AUTOSIZE); 
	imshow("source", src);                

	namedWindow("result", WINDOW_AUTOSIZE); 
	imshow("result", dst);

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}