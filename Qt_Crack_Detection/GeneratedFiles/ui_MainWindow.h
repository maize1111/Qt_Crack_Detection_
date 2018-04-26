/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *openButton;
    QPushButton *examButton;
    QLabel *imgLabel;
    QLabel *resLabel;
    QTextBrowser *srcImgBrowser;
    QTextBrowser *resImgBrowse;
    QTextBrowser *resBrowser;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(650, 450);
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/809284-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowClass->setWindowIcon(icon);
        MainWindowClass->setStyleSheet(QString::fromUtf8("\n"
"*{  \n"
"  font-size:13px;  \n"
"  color:white;  \n"
"  font-family:\"\345\256\213\344\275\223\";  \n"
"}  \n"
"CallWidget QLineEdit#telEdt  \n"
"{  \n"
"  font-size:24px;  \n"
"}  \n"
"QMainWindow,QDialog{  \n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #1B2534, stop: 0.4 #010101,  \n"
"                                 stop: 0.5 #000101, stop: 1.0 #1F2B3C);  \n"
"}  \n"
"QWidget{  \n"
"    background:#121922;  \n"
"}  \n"
"QLabel{  \n"
"   background:transparent;  \n"
"}  \n"
"DailForm QLineEdit#phoneLineEdt{  \n"
"  font-size:36px;  \n"
"  font-weight: bold;  \n"
"}  \n"
"QPushButton,QToolButton{  \n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #5B5F5F, stop: 0.5 #0C2436,  \n"
"                                 stop: 1.0 #27405A);  \n"
"    border-style: outset;  \n"
"    border-width: 1px;  \n"
"    border-radius: 5px;  \n"
"    border-color: #11223F;  \n"
"    padding: 1px; "
                        " \n"
"}  \n"
"QPushButton::hover,QToolButton::hover{  \n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #758385, stop: 0.5 #122C39,  \n"
"                                 stop: 1.0 #0E7788);  \n"
"    border-color: #11505C;  \n"
"}  \n"
"QPushButton::pressed,QToolButton::pressed{  \n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #969B9C, stop: 0.5 #16354B,  \n"
"                                 stop: 1.0 #244F76);  \n"
"    border-color: #11505C;  \n"
"}  \n"
"QPushButton::disabled,QToolButton::disabled{  \n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #282B2C, stop: 0.5 #09121A,  \n"
"                                 stop: 1.0 #111D29);  \n"
"    border-color: #0A1320;  \n"
"    color:#6A6864;  \n"
"}  \n"
"QDialog QPushButton,QDialog QToolButton{  \n"
"  min-width:30px;  \n"
"  min-height:23px;  \n"
"}  \n"
"QToolButton[ob"
                        "jectName=\"minimizeToolBtn\"] {  \n"
"    background: transparent;  \n"
"    border:none;  \n"
"    image:url(qss/minimize.png)  \n"
"}  \n"
"QToolButton[objectName=\"minimizeToolBtn\"]:hover,QToolButton[objectName=\"minimizeToolBtn\"]:pressed {  \n"
"    image:url(qss/minimize_hover.png)  \n"
"}  \n"
"QToolButton[objectName=\"maximizeToolBtn\"] {  \n"
"    background: transparent;  \n"
"    border:none;  \n"
"    image:url(qss/maximize.png)  \n"
"}  \n"
"QToolButton[objectName=\"maximizeToolBtn\"]:hover,QToolButton[objectName=\"maximizeToolBtn\"]:pressed {  \n"
"    image:url(qss/maximize_hover.png)  \n"
"}  \n"
"QToolButton[objectName=\"closeToolBtn\"],QToolButton[objectName=\"customCloseWindow\"] {  \n"
"    background: transparent;  \n"
"    border:none;  \n"
"    image:url(qss/close.png)  \n"
"}  \n"
"QToolButton[objectName=\"closeToolBtn\"]:hover,QToolButton[objectName=\"closeToolBtn\"]:pressed{  \n"
"    image:url(qss/close_hover.png)  \n"
"}  \n"
"QToolButton[objectName=\"customCloseWindow\"]:hover,QTo"
                        "olButton[objectName=\"customCloseWindow\"]:pressed{  \n"
"    image:url(qss/close_hover.png)  \n"
"}  \n"
"QToolButton[objectName=\"titleSetUpToolBtn\"]{  \n"
"    background: transparent;  \n"
"    border:none;  \n"
"    image:url(qss/setup.png)  \n"
"}  \n"
"DailForm QToolButton#oneToolBtn,QToolButton#OneToolBtn,QToolButton#twoToolBtn,QToolButton#threeToolBtn,  \n"
"         QToolButton#fourToolBtn,QToolButton#fiveToolBtn,QToolButton#sixToolBtn,  \n"
"         QToolButton#sevenToolBtn,QToolButton#eightToolBtn,QToolButton#nineToolBtn,  \n"
"         QToolButton#starToolBtn,QToolButton#zeroToolBtn,QToolButton#sharpToolBtn {  \n"
"    font-size:36px;  \n"
"    border-radius: 10px;  \n"
"}  \n"
"DailForm QToolButton#delToolBtn{  \n"
"    border-radius: 10px;  \n"
"}  \n"
"QFrame{  \n"
"    border-color:#32435E;  \n"
"    border-width:1px;  \n"
"    border-radius: 3px;  \n"
"}  \n"
"QLineEdit,QTextEdit {  \n"
"    border: 1px solid #32435E;  \n"
"    border-radius: 3px;  \n"
"    /* padding: 0 8px; */  \n"
"    b"
                        "ackground: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #080B10,  \n"
"                                 stop: 1.0 #212C3F);  \n"
"    selection-background-color: #0A246A;  \n"
"}  \n"
"QLineEdit::hover{  \n"
"  border-color:#5D8B9E;  \n"
"}  \n"
"QLineEdit[echoMode=\"3\"] {  \n"
"     lineedit-password-character: 9679;  \n"
"}  \n"
"#QLineEdit:read-only {  \n"
"     background: #543F7C;  \n"
"}  \n"
"QTabWidget::pane { /* The tab widget frame */  \n"
"     border: 0px solid #32435E;  \n"
"     position: absolute;  \n"
"     left: -0.1em;  \n"
"}  \n"
"QTabWidget#MainTabWidget::tab-bar {  \n"
"     left: -3px; /* move to the right by 5px */  \n"
"}  \n"
"QTabWidget#MainTabWidget QTabBar::tab {  \n"
"     height: 14ex;  \n"
"     width: 14ex;  \n"
"}  \n"
"QTabBar::tab {  \n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #292F31, stop: 1 #0C131E);  \n"
"}  \n"
"QTabBar::tab:selected{  \n"
"     background"
                        ": qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #113845,  stop: 1.0 #15A8FF);  \n"
"}  \n"
"QTabBar::tab:hover {  \n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #113845,  stop: 1.0 #0E6F80);  \n"
"}  \n"
"#QTabBar::tab:selected {  \n"
"     border-color: #32435E;  \n"
"     border-right-color: #32435E; /* same as pane color */  \n"
"}  \n"
"#QTabBar::tab:!selected {  \n"
"     margin-left: 2px; /* make non-selected tabs look smaller */  \n"
"}  \n"
"#QTabBar:tab:first:selected {  \n"
"    margin-top: 0;  \n"
"}  \n"
"QTabBar:tab:last:selected {  \n"
"    margin-right: 0;  \n"
"}  \n"
"QTabBar:tab:only-one {  \n"
"     margin: 0;  \n"
"}  \n"
"QListWidget{  \n"
"    border: 1px solid #32435E;  \n"
"    background:#050609;  \n"
"}  \n"
"QListWidget::item:selected {  \n"
"     /*border: 0px solid #33CCFF;*/  \n"
"     border:none;  \n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
" "
                        "                                stop: 0 #6A848C,  stop: 1.0 #0F9EAF);  \n"
"     padding:0px;  \n"
"     margin:0px;  \n"
"}  \n"
"#QListWidget::item:selected:!active {  \n"
"     border-width: 0px ;  \n"
"}  \n"
"#QListWidget::item:selected:active {  \n"
"     border-width: 1px;  \n"
"}  \n"
"  \n"
"QComboBox {  \n"
"     border: 1px solid #32435E;  \n"
"     border-radius: 3px;  \n"
"     padding: 1px 18px 1px 3px;  \n"
"     min-width: 6em;  \n"
"}  \n"
"QComboBox::hover{  \n"
"  border-color:#5D8B9E;  \n"
"}  \n"
"QComboBox:editable {  \n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #080B10,  \n"
"                                 stop: 1.0 #212C3F);  \n"
"}  \n"
"QComboBox:!editable, QComboBox::drop-down:editable {  \n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #080B10,  \n"
"                                 stop: 1.0 #212C3F);  \n"
"}  \n"
"/* QComboBox gets the \"on\" state"
                        " when the popup is open */  \n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {  \n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #080B10,  \n"
"                                 stop: 1.0 #212C3F);;  \n"
"}  \n"
"QComboBox:on { /* shift the text when the popup opens */  \n"
"     padding-top: 3px;  \n"
"     padding-left: 4px;  \n"
"}  \n"
"QComboBox::drop-down {  \n"
"     subcontrol-origin: padding;  \n"
"     subcontrol-position: top right;  \n"
"     width: 15px;  \n"
"     border-left-width: 1px;  \n"
"     border-left-color: 32435E;  \n"
"     border-left-style: solid; /* just a single line */  \n"
"     border-top-right-radius: 3px; /* same radius as the QComboBox */  \n"
"     border-bottom-right-radius: 3px;  \n"
"}  \n"
"QComboBox::down-arrow {  \n"
"     image: url(qss/downarrow.png);  \n"
"}  \n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */  \n"
"     top: 1px;  \n"
"     left: 1px;  \n"
"}  \n"
"QCo"
                        "mboBox QAbstractItemView {  \n"
"     border: 2px solid #32435E;  \n"
"     selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #506B79,  \n"
"                                 stop: 1.0 #0D95A6);  \n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  \n"
"                                 stop: 0 #1B2534, stop: 0.4 #010101,  \n"
"                                 stop: 0.5 #000101, stop: 1.0 #1F2B3C);  \n"
"}  "));
        MainWindowClass->setIconSize(QSize(256, 256));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background:#121922;    "));
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(70, 320, 200, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        openButton->setFont(font);
        openButton->setCursor(QCursor(Qt::PointingHandCursor));
        openButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/if__7ui_2303112.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon1);
        openButton->setIconSize(QSize(36, 36));
        examButton = new QPushButton(centralWidget);
        examButton->setObjectName(QStringLiteral("examButton"));
        examButton->setGeometry(QRect(279, 190, 81, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        examButton->setFont(font1);
        examButton->setCursor(QCursor(Qt::PointingHandCursor));
        examButton->setStyleSheet(QString::fromUtf8("font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("Resources/809284-512 (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        examButton->setIcon(icon2);
        examButton->setIconSize(QSize(20, 20));
        imgLabel = new QLabel(centralWidget);
        imgLabel->setObjectName(QStringLiteral("imgLabel"));
        imgLabel->setGeometry(QRect(70, 100, 200, 200));
        imgLabel->setStyleSheet(QString::fromUtf8("border:1px solid #E0DDDC;/*\350\276\271\346\241\206\344\270\2721\345\203\217\347\264\240\357\274\214\347\201\260\350\211\262*/"));
        resLabel = new QLabel(centralWidget);
        resLabel->setObjectName(QStringLiteral("resLabel"));
        resLabel->setGeometry(QRect(370, 100, 200, 200));
        resLabel->setStyleSheet(QString::fromUtf8("\n"
"    border:1px solid #E0DDDC;/*\350\276\271\346\241\206\344\270\2721\345\203\217\347\264\240\357\274\214\347\201\260\350\211\262*/\n"
""));
        srcImgBrowser = new QTextBrowser(centralWidget);
        srcImgBrowser->setObjectName(QStringLiteral("srcImgBrowser"));
        srcImgBrowser->setGeometry(QRect(70, 50, 200, 41));
        srcImgBrowser->setStyleSheet(QString::fromUtf8("border-color: rgb(18, 25, 34);\n"
"font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        resImgBrowse = new QTextBrowser(centralWidget);
        resImgBrowse->setObjectName(QStringLiteral("resImgBrowse"));
        resImgBrowse->setGeometry(QRect(370, 50, 200, 41));
        resImgBrowse->setStyleSheet(QString::fromUtf8("border-color: rgb(18, 25, 34);\n"
"font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        resBrowser = new QTextBrowser(centralWidget);
        resBrowser->setObjectName(QStringLiteral("resBrowser"));
        resBrowser->setGeometry(QRect(410, 320, 120, 50));
        resBrowser->setFont(font);
        resBrowser->setStyleSheet(QString::fromUtf8("border-color: rgb(18, 25, 34);\n"
"font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        MainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Crack Detection Tool - Alessio Pan - Shanghai University", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        MainWindowClass->setWhatsThis(QApplication::translate("MainWindowClass", "<html><head/><body><p>A tool for crack detection by Alessio Pan from Shanghai University</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        openButton->setText(QApplication::translate("MainWindowClass", "Select Image", Q_NULLPTR));
        examButton->setText(QApplication::translate("MainWindowClass", "Exam", Q_NULLPTR));
        imgLabel->setText(QString());
        resLabel->setText(QString());
        srcImgBrowser->setHtml(QApplication::translate("MainWindowClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Adobe \351\273\221\344\275\223 Std R'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:18pt; color:#ffffff;\">SOURCE IMAGE</span></p></body></html>", Q_NULLPTR));
        resImgBrowse->setHtml(QApplication::translate("MainWindowClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Adobe \351\273\221\344\275\223 Std R'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:18pt; color:#ffffff;\">RESULT IMAGE</span></p></body></html>", Q_NULLPTR));
        resBrowser->setHtml(QApplication::translate("MainWindowClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Adobe \351\273\221\344\275\223 Std R'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
