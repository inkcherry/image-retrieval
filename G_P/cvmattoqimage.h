#ifndef CVMATTOQIMAGE_H
#define CVMATTOQIMAGE_H


#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <QImage>
cv::Mat QImageToMat(QImage image);
QImage	MatToQImage(cv::Mat mtx);
#endif // CVMATTOQIMAGE_H
