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

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	qDebug() << QString::fromLocal8Bit("Output success!	");
	waitKey(0);
	return a.exec();
}
