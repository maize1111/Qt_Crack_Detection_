#pragma once

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

using namespace std;
using namespace cv;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
	QLabel *imgLabel;
	QLabel *resLabel;
	//QDockWidget *dock_Image;
	Mat src;
	Mat res;
	QImage img;
	QImage resImg;
	QString currentPath;

private slots:
	void on_openButton_clicked();
	void on_examButton_clicked();
};
