#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src, dst;
	src = imread("citrus.bmp", IMREAD_GRAYSCALE); // Read the file
	dst = Mat::zeros(src.size(), src.type());
	if (src.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	for (int i = 0; i<src.size().height; i++)
		for (int j = 0; j<src.size().width; j++)
		{
			dst.at<uchar>(i, j) = src.at<uchar>(i, j)+30;
		}
		
		
	namedWindow("source", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("source", src); // Show our image inside it.

	namedWindow("result", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("result", dst); // Show our image inside it.
	imwrite("outImage.bmp", dst);

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}