#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWidget>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{file:///C:/Users/inkcherry/AppData/Local/Temp/Test.pro

    ui->setupUi(this);
    curfile=nullptr;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_input_clicked()
{
 QMessageBox *m=  new QMessageBox();
m->setText("32434");
 m->show();

}

void MainWindow::on_pushButton_2_clicked()   //检索图像
{


         QFileDialog* fd = new QFileDialog(this);
         QString fileName= fd->getOpenFileName();
//         curfile  =

         QMessageBox *m =new QMessageBox();
         m->setText(fileName);
         m->show();



}
