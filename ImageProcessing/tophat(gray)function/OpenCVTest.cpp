#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
int ostu(int *hist);
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst1, dst2, dst3, ostu_before, ostu_after;
	src = imread("rice.png", IMREAD_GRAYSCALE); // Read the file
	dst1 = Mat::zeros(src.size(), src.type());
	dst2 = Mat::zeros(src.size(), src.type());
	dst3 = Mat::zeros(src.size(), src.type());
	ostu_after = Mat::zeros(src.size(), src.type());
	ostu_before = Mat::zeros(src.size(), src.type());
	int min = 10000, max = 0, sum = 0;
	int val;

	int hist[256], T;

	for (int i = 0; i<256; i++)
		hist[i] = 0;

	for (int i = 0; i<256; i++)
		for (int j = 0; j<256; j++)
			hist[src.at<uchar>(i, j)]++;

	T = ostu(hist);

	printf("%d\n", T);
	for (int i = 0; i<256; i++)
		for (int j = 0; j<256; j++)
		{
			if (src.at<uchar>(i, j) < T)
				ostu_before.at<uchar>(i, j) = 0;
			else
				ostu_before.at<uchar>(i, j) = 255;

		}


	for (int i = 0; i<src.size().height; i++)
	{
		for (int j = 0; j < src.size().width; j++)
		{
			for (int mi = -10; mi < 10; mi++)
			{
				for (int mj = -10; mj < 10; mj++)
				{
					if ((i + mi) > -1 && (i + mi) < src.size().height && (j + mj) > -1 && (j + mj) < src.size().width)
					{
						val = src.at<uchar>((i + mi), (j + mj));
						if (min > val)
							min = val;
					}
				}
			}
			dst1.at<uchar>(i, j) = min; // dst1 : erosion한 결과
			min = 1000;
		}
	}

	for (int i = 0; i<src.size().height; i++)
	{
		for (int j = 0; j < src.size().width; j++)
		{
			for (int mi = -10; mi < 10; mi++)
			{
				for (int mj = -10; mj < 10; mj++)
				{
					if ((i + mi) > -1 && (i + mi) < src.size().height && (j + mj) > -1 && (j + mj) < src.size().width)
					{
						val = dst1.at<uchar>((i + mi), (j + mj));
						if (max < val)
							max = val;
					}
				}
			}
			dst2.at<uchar>(i, j) = max; // dst2 : erosion 후 dilation한 결과 -> opening
			if (src.at<uchar>(i, j) > dst2.at<uchar>(i, j))
				dst3.at<uchar>(i, j) = src.at<uchar>(i, j) - dst2.at<uchar>(i, j); // dst3 : tophat (원래영상에서 opening을 빼준 결과
			else
				dst3.at<uchar>(i, j) = 0;
			max = 0;
		}
	}

	for (int i = 0; i<256; i++)
		hist[i] = 0;

	for (int i = 0; i<256; i++)
		for (int j = 0; j<256; j++)
			hist[dst3.at<uchar>(i, j)]++;

	T = ostu(hist);

	printf("%d\n", T);
	for (int i = 0; i<256; i++)
		for (int j = 0; j<256; j++)
		{
			if (dst3.at<uchar>(i, j) < T)
				ostu_after.at<uchar>(i, j) = 0;
			else
				ostu_after.at<uchar>(i, j) = 255;

		}

	namedWindow("ostu_before", WINDOW_AUTOSIZE);
	imshow("ostu_before", ostu_before);  // 원래 이미지에서의 ostu 알고리즘 적용

	namedWindow("source", WINDOW_AUTOSIZE); 
	imshow("source", src);                

	namedWindow("result", WINDOW_AUTOSIZE); 
	imshow("result", dst1);                // dst1 : erosion한 결과

	namedWindow("result2", WINDOW_AUTOSIZE);
	imshow("result2", dst2);                // dst2 : erosion 후 dilation한 결과

	namedWindow("result3", WINDOW_AUTOSIZE); 
	imshow("result3", dst3);               // dst3 : tophat (원래영상에서 opening을 빼준 결과

	namedWindow("ostu_after", WINDOW_AUTOSIZE); 
	imshow("ostu_after", ostu_after);
	imwrite("ostu_after.bmp", ostu_after);	// tophat후 ostu 알고리즘 적용

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}
int ostu(int *hist)
{
	float prob[256];
	float q1, q2, m1, m2, d1, d2, dw;
	float var = 10000000000000.0f;
	int T;

	for (int i = 0; i<256; i++)
		prob[i] = float(hist[i]) / (256 * 256);

	for (int t = 0; t<256; t++)
	{
		q1 = 0.0f;
		q2 = 0.0f;
		m1 = 0.0f;
		m2 = 0.0f;
		d1 = 0.0f;
		d2 = 0.0f;
		for (int i = 0; i<t; i++)
			q1 = q1 + prob[i];
		for (int i = t; i<256; i++)
			q2 = q2 + prob[i];
		if (q1 == 0 || q2 == 0) continue;

		for (int i = 0; i<t; i++)
			m1 = m1 + i * prob[i] / q1;

		for (int i = t; i<256; i++)
			m2 = m2 + i * prob[i] / q2;

		for (int i = 0; i<t; i++)
			d1 = d1 + (i - m1)*(i - m1)*prob[i] / q1;

		for (int i = t; i<256; i++)
			d2 = d2 + (i - m2)*(i - m2)*prob[i] / q2;

		dw = q1 * d1 + q2 * d2;

		if (dw<var)
		{
			T = t;
			var = dw;
		}
	}
	return T;
}