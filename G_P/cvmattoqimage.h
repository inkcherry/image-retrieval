#ifndef CVMATTOQIMAGE_H
#define CVMATTOQIMAGE_H


#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <QImage>
#include<QPixmap>
cv::Mat QImageToMat(QImage& image) ;
QImage	MatToQImage(cv::Mat& mtx) ;
QPixmap MatToQpixmap(cv::Mat& mtx) ;  //这两个是用过Qimage间接转过来的
cv::Mat QPixmapToMat(QPixmap& pimage) ;
#endif // CVMATTOQIMAGE_H
