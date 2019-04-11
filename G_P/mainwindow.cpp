#include "mainwindow.h"
#include "ui_mainwindow.h"



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
         QString    filename = fd->getOpenFileName();



//         std::string fileName= (fd->getOpenFileName()).toStdString();

//         cv::Mat cvim = cv::imread(fileName);
//         QImage m1= MatToQImage(cvim);
//          QImage *input_image = new QImage(m1);
//         ui->input_image_lable->setPixmap(QPixmap::fromImage(input_image));

         QPixmap * img = new QPixmap(filename);
         img->scaled(ui->input_image_lable->size(),Qt::KeepAspectRatio);
         ui->input_image_lable->setScaledContents(true);
         ui->input_image_lable->setPixmap(*img);




//         QImage *image= new QImage(filename);
//         ui->input_image_lable->setPixmap(QPixmap::fromImage(*image));
//         ui->input_image_lable->resize(QSize(image->width(),image->height()));



//         ui->scrollImag->setWidget(input_image_lable);

//         QMessageBox *m =new QMessageBox();
//         m->setText(fileName);
//         m->show();



}
