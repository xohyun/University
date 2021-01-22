#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat src, dst, dst2;
	src = imread("na.bmp", IMREAD_COLOR); // Read the file
	dst = Mat::zeros(src.size(), src.type());
	dst2 = Mat::zeros(src.size(), src.type());
	int min = 10000, max = 0, sum = 0;
	//double mask[3][3] = { { 1. / 9, 1. / 9, 1. / 9 },{ 1. / 9, 1. / 9, 1. / 9 },{ 1. / 9, 1. / 9, 1. / 9 } };
	double mask[3][3] = { { 1,1,1 },{ 1,1,1 },{ 1,1,1 } };
	double val;
	int a, b;


	for (int i = 0; i<src.size().height; i++)
	{
		for (int j = 0; j<src.size().width; j++)
		{
			for (int c = 0; c<3; c++)
			{
				val = 0;
				for (int mi = -1; mi<2; mi++)
				{
					for (int mj = -1; mj<2; mj++)
					{
						if (i + mi>-1 && i + mi <src.size().height && j + mj>-1 && j + mj <src.size().width)
						{
							val = double(src.at<Vec3b>((i + mi), (j + mj))[c]) * double(mask[mi + 1][mj + 1]);
							if (max < val)
								max = int(val);

						}
					}
				}
				dst2.at<Vec3b>(i, j)[c] = max;
				max = 0;

			}

		}

	}

	for (int i = 0; i<src.size().height; i++)
	{
		for (int j = 0; j<src.size().width; j++)
		{
			for (int c = 0; c<3; c++)
			{
				val = 0;
				for (int mi = -1; mi<2; mi++)
				{
					for (int mj = -1; mj<2; mj++)
					{
						if (i + mi>-1 && i + mi <src.size().height && j + mj>-1 && j + mj <src.size().width)
						{
							val = double(src.at<Vec3b>((i + mi), (j + mj))[c]) * double(mask[mi + 1][mj + 1]);
							if (min > val)
								min = int(val);
						}
					}
				}
				//dst.at<Vec3b>(i, j)[c] = int(val);
				dst2.at<Vec3b>(i, j)[c] = min;
				a = src.at<Vec3b>(i, j)[c];
				b = dst2.at<Vec3b>(i, j)[c];

				dst.at<Vec3b>(i, j)[c] = a - b;

				min = 1000;
			}

		}

	}
	namedWindow("source", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("source", src);                // Show our image inside it.
	imwrite("lowpass_filtering_3.bmp", src);

	namedWindow("result", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("result", dst);                // Show our image inside it.
	imwrite("lowpass_filtering_3.bmp", dst);

	namedWindow("result2", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("result2", dst2);                // Show our image inside it.
	imwrite("lowpass_filtering_3.bmp", dst2);
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}