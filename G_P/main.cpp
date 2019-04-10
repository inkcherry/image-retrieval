//#include "mainwindow.h"
//#include <QApplication>
//#include "opencv2/opencv.hpp"
//using namespace  cv;
//using namespace std;
//int main(int argc, char *argv[])
//{

//    Mat image = imread("D:\te\1.jpg");
//        NamedWindow("window", CV_WINDOW_NORMAL);
//        imshow("window",image);
//        waitKey(0);

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();




//    return a.exec();
//}


#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
     Mat image = imread("D:/te/1.jpg");
     cvNamedWindow("window", CV_WINDOW_NORMAL);
     imshow("window",image);
     waitKey(0);
 }
