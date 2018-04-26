//单通道灰度图直方图类，用于计算单通道灰度图的直方图，绘制直方图
#pragma once
#include <iostream>
#include <string>
#include "cv.h"
#include "highgui.h"
#include "cvaux.h"
#include "cxcore.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"

class Histogram1D
{
public:
	Histogram1D();
	~Histogram1D();
	cv::MatND getHistogram(const cv::Mat &image) {
		cv::MatND hist;
		cv::calcHist(&image,
			1,
			channels,
			cv::Mat(),
			hist,
			1,
			histSize,
			ranges
		);
		return hist;
	}

	cv::Mat getHistogramImage(const cv::Mat& image) {
		cv::MatND hist = getHistogram(image);
		double maxVal = 0;
		double minVal = 0;
		cv::minMaxLoc(hist, &minVal, &maxVal, 0, 0);
		cv::Mat histImg(histSize[0], histSize[0], CV_8U, cv::Scalar(255));
		int hpt = static_cast<int>(0.9*histSize[0]);
		for (int h = 0; h < histSize[0]; h++) {
			float binVal = hist.at<float>(h);
			int intensity = static_cast<int>(binVal*hpt / maxVal);
			line(histImg, cv::Point(h, histSize[0]), cv::Point(h, histSize[0] - intensity), cv::Scalar::all(0));
		}
		return histImg;
	}

private:
	int histSize[1];
	float hranges[2];
	const float*ranges[1];
	int channels[1];
};

Histogram1D::Histogram1D()
{
	histSize[0] = 256;
	hranges[0] = 0.0;
	hranges[1] = 255.0;
	ranges[0] = hranges;
	channels[0] = 0;//默认在直方图观察0通道
}

Histogram1D::~Histogram1D()
{
}