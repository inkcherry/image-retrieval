#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include "hsv.h"
#include "opencv2/imgproc/imgproc.hpp"
#include <retrieval.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QFile *curfile;        //检索图像的文件指针
    QString    filename;   //检索图像的文件名
    QString  stlfilename;    //3d模型文件名字
    std::unique_ptr<QPixmap>cur_pimg;
    std::unique_ptr<cv::Mat>cur_cvmat;
    std::unique_ptr<QImage>cur_qimg;    //分别用于保存当前的 三种数据机构的检索图像
    ~MainWindow();

private slots:
    void on_input_clicked();

    void on_input_image_button_clicked();

    void on_input_image_button_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
