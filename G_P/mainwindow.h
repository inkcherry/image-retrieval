#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include<QMessageBox>


//INCLUDEPATH += F:/opencv/opencv/build/include\

//#include<opencv2/core.hpp>

//#include "F:/opencv/opencv/build/include\opencv2/core.hpp"

//#include<F:\opencvcontrib\install\include\opencv2\core\core.hpp>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QFile *curfile;
    ~MainWindow();

private slots:
    void on_input_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
