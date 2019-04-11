#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include<QMessageBox>
#include "cvmattoqimage.h"
#include <QImage>
#include <QWidget>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <string>
#include<QMovie>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QFile *curfile;
    QString    filename;
    ~MainWindow();

private slots:
    void on_input_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
