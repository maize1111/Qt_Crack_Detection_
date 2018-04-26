#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QtGui>
#include <QtWidgets>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <string>
#include <vector>  
#include "cv.h"
#include "highgui.h"
#include "cvaux.h"
#include "cxcore.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setFixedSize(650, 450);
	QImage image = QImage(200, 200, QImage::Format_RGB32);  // 新建图像
	image.fill(qRgb(255, 255, 255));                        // 全白
	ui.imgLabel->setPixmap(QPixmap::fromImage(image));         // 显示图像
	ui.imgLabel->resize(image.width(), image.height());        // 图像与imgLabel同大小
	ui.resLabel->setPixmap(QPixmap::fromImage(image));         // 显示图像
	ui.resLabel->resize(image.width(), image.height());        // 图像与imgLabel同大小
}

MainWindow::~MainWindow() {

}

void MainWindow::on_openButton_clicked()
{
	ui.imgLabel->clear();
	ui.resLabel->clear();
	ui.resBrowser->clear();
	QImage image = QImage(200, 200, QImage::Format_RGB32);  // 新建图像
	image.fill(qRgb(255, 255, 255));                        // 全白
	ui.imgLabel->setPixmap(QPixmap::fromImage(image));         // 显示图像
	ui.imgLabel->resize(image.width(), image.height());        // 图像与imgLabel同大小
	ui.resLabel->setPixmap(QPixmap::fromImage(image));         // 显示图像
	ui.resLabel->resize(image.width(), image.height());        // 图像与imgLabel同大小
	//ui.imgLabel->setScaledContents(false);  // 设置QLabel自动适应图像大小

	QString path = QFileDialog::getOpenFileName(this, tr("选择图像"), ".", tr("Images(*.jpg *.png *.bmp)"));                            // 文件选择框
	if (!path.isEmpty())                                    // 检测当前路径是否正确
	{
		QImage* img = new QImage();
		if (!(img->load(path)))
		{
			QMessageBox::information(this, tr("错误"), tr("打开图像失败！"));
			delete img;
			return;
		}
		src = imread(path.toUtf8().data());
		//imshow("source image", src);
		//cvtColor(src, res, CV_BGR2RGB); 不需要转换啊
		imwrite("ProgramImgs/source.jpg", src);
		img->load("ProgramImgs/source.jpg");
		QPixmap pixmap = QPixmap::fromImage(*img);
		int with = ui.imgLabel->width();
		int height = ui.imgLabel->height();
		QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放  
		ui.imgLabel->setPixmap(fitpixmap);
		//ui.imgLabel->resize(img->width(), img->height());
		currentPath = path;
	}
}

void MainWindow::on_examButton_clicked()
{
	QImage* resImg = new QImage();

	//Algorithm START
	Mat GrayImg;
	cvtColor(src, GrayImg, CV_BGR2GRAY);
	//GrayImg = imread("QueXianTu.jpg", 0);//灰度图
	//imshow("Sorce Image - Gray", GrayImg);

	//HSV颜色空间
	/*
	Mat hsv;
	cvtColor(SorceImg, hsv, CV_BGR2HSV);
	imshow("hsv", hsv);
	*/

	//转换为HLS颜色空间，并取S向量
	//色相:H∈[0, 360]  亮度:L∈[0, 1]  饱和度:S∈[0, 1]
	Mat hls;
	cvtColor(src, hls, CV_BGR2HLS);
	//imshow("2. 转为HLS颜色空间", hls);
	//waitKey(0);
	vector<Mat> channels;
	Mat hls_s_channel;
	split(hls, channels);
	hls_s_channel = channels.at(1);
	//imshow("3. 提取HLS颜色空间的S向量", hls_s_channel);
	//waitKey(0);

	//直方图判断阈值
	/*
	const int channels[1] = { 0 };
	const int histSize[1] = { 256 };
	float hranges[2] = { 0,255 };
	const float* ranges[1] = { hranges };
	MatND hist;
	calcHist(&GrayImg, 1, channels, Mat(), hist, 1, histSize, ranges);
	*/

	//二值图噪声太多，先预处理
	Mat BinaryImg;
	threshold(hls_s_channel, BinaryImg, 200, 255, CV_THRESH_BINARY_INV);//Binary Image
	//imshow("4. 转为二值图", BinaryImg);
	//waitKey(0);

	//Histogram1D h;
	//MatND histo = h.getHistogram(GrayImg);
	//imshow("hist image", h.getHistogramImage(GrayImg));

	//直方图均衡化
	/*
	Mat equa;
	equalizeHist(GrayImg, equa);
	imshow("After equalize", equa);
	Mat BinaryImg;
	threshold(equa, BinaryImg, 110, 255, CV_THRESH_BINARY_INV);//Binary Image
	imshow("Binary Image", BinaryImg);
	*/

	//中值滤波
	Mat img_middle;
	medianBlur(BinaryImg, img_middle, 5);
	//namedWindow("out", 0);
	//imshow("5. 中值滤波去噪", img_middle);
	//waitKey(0);

	//开运算，先腐蚀再膨胀
	Mat eroded;
	Mat dilated;
	erode(img_middle, eroded, Mat());//腐蚀
	 //尝试多次腐蚀膨胀
	dilate(eroded, eroded, Mat());
	erode(eroded, eroded, Mat());
	//imshow("Eorded img", eroded);

	dilate(eroded, dilated, Mat());//膨胀
	//imshow("6. 先腐蚀再膨胀", dilated);
	//waitKey(0);

	//边缘检测
	Mat contours;
	Canny(dilated, contours, 125, 350);//Canny算子
	//imshow("7. Canny算子边缘检测破损位置", contours);
	//waitKey(0);
	//Laplacian(dilated, contours, CV_16S, 3, 1, 0, BORDER_DEFAULT);//Laplacian算子
	//convertScaleAbs(contours,contours);
	//imshow("Laplacian", contours);

	//将破损区域显示在原图中
	vector<vector<Point> > contoursP;
	vector<Vec4i>hierarchy;
	findContours(contours, contoursP, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
	Mat res = src.clone();
	//drawContours(res, contoursP, -1, Scalar(0,0,255), 1, 16);
	for (int i = 0; i < contoursP.size(); i++) {
		Scalar red = Scalar(0, 0, 255);
		drawContours(res, contoursP, i, red, 2, 8, hierarchy, 0, Point());
	}
	//imshow("8. 提取破损位置至原图中", res);

	if (contoursP.size()<1)
	{
		ui.resBrowser->setTextColor(Qt::green);
		ui.resBrowser->setFont(QFont("Microsoft YaHei", 20, 75));
		ui.resBrowser->setText(tr("PASS"));
		ui.resBrowser->setAlignment(Qt::AlignHCenter);
	}
	else
	{
		ui.resBrowser->setTextColor(Qt::red);
		ui.resBrowser->setFont(QFont("Microsoft YaHei", 20, 75));
		ui.resBrowser->setText(tr("FAILED"));
		ui.resBrowser->setAlignment(Qt::AlignHCenter);
	}
	//Algorithm END

	imwrite("ProgramImgs/result.jpg", res);
	resImg->load("ProgramImgs/result.jpg");
	QPixmap pixmap = QPixmap::fromImage(*resImg);
	int with = ui.resLabel->width();
	int height = ui.resLabel->height();
	QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放  
	ui.resLabel->setPixmap(fitpixmap);
}
