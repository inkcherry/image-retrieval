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


         QFileDialog*  fd = new QFileDialog(this);
         QString        filename = fd->getOpenFileName();



         std::string fileName= (fd->getOpenFileName()).toStdString();

//
//         QImage m1= MatToQImage(cvim);
//          QImage *input_image = new QImage(m1);
//         ui->input_image_lable->setPixmap(QPixmap::fromImage(input_image));


         //自适应检索图像

           cur_pimg.reset(new QPixmap(filename));              //pimg智能指针
//        std::unique_ptr<QPixmap>pimg; pimg(new QPixmap(filename));


         cur_pimg->scaled(ui->input_image_lable->size(),Qt::KeepAspectRatio);
         ui->input_image_lable->setScaledContents(true);
         ui->input_image_lable->setPixmap(*cur_pimg);



//      cur_cvmat.reset(new cv::Mat(cv::imread(fileName)));  //直接使用cv imread读取的图像
//             cvNamedWindow("window", CV_WINDOW_NORMAL);
//             imshow("window",*cur_cvmat);





//         cur_qimg.reset(new QImage(filename));                    //使用Qimage转换后的图像

//         cur_cvmat.reset(new cv::Mat(QImageToMat(*cur_qimg)));
//         cvNamedWindow("window", CV_WINDOW_NORMAL);
//               imshow("window",*cur_cvmat);

         cur_cvmat.reset((new cv::Mat(QPixmapToMat(*cur_pimg))));    //使用qpixmat 转换后的图像
         cvNamedWindow("window", CV_WINDOW_NORMAL);
                        imshow("window",*cur_cvmat);



//         QImage *image= new QImage(filename);
//         ui->input_image_lable->setPixmap(QPixmap::fromImage(*image));
//         ui->input_image_lable->resize(QSize(image->width(),image->height()));



//         ui->scrollImag->setWidget(input_image_lable);

//         QMessageBox *m =new QMessageBox();
//         m->setText(fileName);
//         m->show();



}
