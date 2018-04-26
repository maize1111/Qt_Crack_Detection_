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
	QImage image = QImage(200, 200, QImage::Format_RGB32);  // �½�ͼ��
	image.fill(qRgb(255, 255, 255));                        // ȫ��
	ui.imgLabel->setPixmap(QPixmap::fromImage(image));         // ��ʾͼ��
	ui.imgLabel->resize(image.width(), image.height());        // ͼ����imgLabelͬ��С
	ui.resLabel->setPixmap(QPixmap::fromImage(image));         // ��ʾͼ��
	ui.resLabel->resize(image.width(), image.height());        // ͼ����imgLabelͬ��С
}

MainWindow::~MainWindow() {

}

void MainWindow::on_openButton_clicked()
{
	ui.imgLabel->clear();
	ui.resLabel->clear();
	ui.resBrowser->clear();
	QImage image = QImage(200, 200, QImage::Format_RGB32);  // �½�ͼ��
	image.fill(qRgb(255, 255, 255));                        // ȫ��
	ui.imgLabel->setPixmap(QPixmap::fromImage(image));         // ��ʾͼ��
	ui.imgLabel->resize(image.width(), image.height());        // ͼ����imgLabelͬ��С
	ui.resLabel->setPixmap(QPixmap::fromImage(image));         // ��ʾͼ��
	ui.resLabel->resize(image.width(), image.height());        // ͼ����imgLabelͬ��С
	//ui.imgLabel->setScaledContents(false);  // ����QLabel�Զ���Ӧͼ���С

	QString path = QFileDialog::getOpenFileName(this, tr("ѡ��ͼ��"), ".", tr("Images(*.jpg *.png *.bmp)"));                            // �ļ�ѡ���
	if (!path.isEmpty())                                    // ��⵱ǰ·���Ƿ���ȷ
	{
		QImage* img = new QImage();
		if (!(img->load(path)))
		{
			QMessageBox::information(this, tr("����"), tr("��ͼ��ʧ�ܣ�"));
			delete img;
			return;
		}
		src = imread(path.toUtf8().data());
		//imshow("source image", src);
		//cvtColor(src, res, CV_BGR2RGB); ����Ҫת����
		imwrite("ProgramImgs/source.jpg", src);
		img->load("ProgramImgs/source.jpg");
		QPixmap pixmap = QPixmap::fromImage(*img);
		int with = ui.imgLabel->width();
		int height = ui.imgLabel->height();
		QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // ����������  
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
	//GrayImg = imread("QueXianTu.jpg", 0);//�Ҷ�ͼ
	//imshow("Sorce Image - Gray", GrayImg);

	//HSV��ɫ�ռ�
	/*
	Mat hsv;
	cvtColor(SorceImg, hsv, CV_BGR2HSV);
	imshow("hsv", hsv);
	*/

	//ת��ΪHLS��ɫ�ռ䣬��ȡS����
	//ɫ��:H��[0, 360]  ����:L��[0, 1]  ���Ͷ�:S��[0, 1]
	Mat hls;
	cvtColor(src, hls, CV_BGR2HLS);
	//imshow("2. תΪHLS��ɫ�ռ�", hls);
	//waitKey(0);
	vector<Mat> channels;
	Mat hls_s_channel;
	split(hls, channels);
	hls_s_channel = channels.at(1);
	//imshow("3. ��ȡHLS��ɫ�ռ��S����", hls_s_channel);
	//waitKey(0);

	//ֱ��ͼ�ж���ֵ
	/*
	const int channels[1] = { 0 };
	const int histSize[1] = { 256 };
	float hranges[2] = { 0,255 };
	const float* ranges[1] = { hranges };
	MatND hist;
	calcHist(&GrayImg, 1, channels, Mat(), hist, 1, histSize, ranges);
	*/

	//��ֵͼ����̫�࣬��Ԥ����
	Mat BinaryImg;
	threshold(hls_s_channel, BinaryImg, 200, 255, CV_THRESH_BINARY_INV);//Binary Image
	//imshow("4. תΪ��ֵͼ", BinaryImg);
	//waitKey(0);

	//Histogram1D h;
	//MatND histo = h.getHistogram(GrayImg);
	//imshow("hist image", h.getHistogramImage(GrayImg));

	//ֱ��ͼ���⻯
	/*
	Mat equa;
	equalizeHist(GrayImg, equa);
	imshow("After equalize", equa);
	Mat BinaryImg;
	threshold(equa, BinaryImg, 110, 255, CV_THRESH_BINARY_INV);//Binary Image
	imshow("Binary Image", BinaryImg);
	*/

	//��ֵ�˲�
	Mat img_middle;
	medianBlur(BinaryImg, img_middle, 5);
	//namedWindow("out", 0);
	//imshow("5. ��ֵ�˲�ȥ��", img_middle);
	//waitKey(0);

	//�����㣬�ȸ�ʴ������
	Mat eroded;
	Mat dilated;
	erode(img_middle, eroded, Mat());//��ʴ
	 //���Զ�θ�ʴ����
	dilate(eroded, eroded, Mat());
	erode(eroded, eroded, Mat());
	//imshow("Eorded img", eroded);

	dilate(eroded, dilated, Mat());//����
	//imshow("6. �ȸ�ʴ������", dilated);
	//waitKey(0);

	//��Ե���
	Mat contours;
	Canny(dilated, contours, 125, 350);//Canny����
	//imshow("7. Canny���ӱ�Ե�������λ��", contours);
	//waitKey(0);
	//Laplacian(dilated, contours, CV_16S, 3, 1, 0, BORDER_DEFAULT);//Laplacian����
	//convertScaleAbs(contours,contours);
	//imshow("Laplacian", contours);

	//������������ʾ��ԭͼ��
	vector<vector<Point> > contoursP;
	vector<Vec4i>hierarchy;
	findContours(contours, contoursP, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
	Mat res = src.clone();
	//drawContours(res, contoursP, -1, Scalar(0,0,255), 1, 16);
	for (int i = 0; i < contoursP.size(); i++) {
		Scalar red = Scalar(0, 0, 255);
		drawContours(res, contoursP, i, red, 2, 8, hierarchy, 0, Point());
	}
	//imshow("8. ��ȡ����λ����ԭͼ��", res);

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
	QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // ����������  
	ui.resLabel->setPixmap(fitpixmap);
}
