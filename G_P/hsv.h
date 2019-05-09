#ifndef HSV_H
#define HSV_H
#include <QMainWindow>
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include<QMessageBox>
#include "cvmattoqimage.h"
#include "stlloader.h"
#include <QImage>
#include <QWidget>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/shape.hpp>
#include <string>
#include<QMovie>
#include<QScopedPointer>    //Qt家族的只能指针,用着玩玩
#include "opencv2/imgproc/imgproc.hpp"
class hsv
{

public:
    enum hist_type{H,S,V};
    hsv(std::string &path);
//    std::unique_ptr<IplImage> *hsv_img;
    IplImage *cur_image;
    IplImage *hsv_img;
    IplImage *cur_img;
    IplImage *image_h ;
    IplImage *image_s;
    IplImage *image_v;
    CvHistogram *hist_h;
    CvHistogram *hist_s;
    CvHistogram *hist_v;

    float *range_h;
    float *range_s;
    float *range_v;

    int arr_size_h;
    int arr_size_s;
    int arr_size_v;

    void show();
//    void init_and_get_range(int *arr,hist_type type);   //通过type 拿到arr_size_*   然后根据一维数组确定区间 ps:完全弄错了
    ~hsv();
};

#endif // HSV_H
