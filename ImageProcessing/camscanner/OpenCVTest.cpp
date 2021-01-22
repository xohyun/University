#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
int ostu(int *hist);
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("scan.bmp", IMREAD_GRAYSCALE); // Read the file
	dst = Mat::zeros(src.size(), src.type());
	int i2, j2;
	
	for (int i = 0; i < src.size().height; i++)
	{
		for (int j = 0; j < src.size().width; j++)
		{
			j2 = (-53.9 * j + 7.5291 * i - 4002.5 * 1) / (-0.0063 * j + 0.0569 * i - 81.6835);
			i2 = (-0.7606 * j - 48.8250 * i - 1388.6 * 1) / (-0.0063 * j + 0.0569 * i - 81.6835);
			dst.at<char>(i, j) = src.at<char>(i2, j2);
		}
	}
	namedWindow("source", WINDOW_AUTOSIZE); 
	imshow("source", src);                

	namedWindow("result", WINDOW_AUTOSIZE); 
	imshow("result", dst);

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}