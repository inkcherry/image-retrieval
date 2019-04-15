#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{file:///C:/Users/inkcherry/AppData/Local/Temp/Test.pro

    ui->setupUi(this);
    curfile=nullptr;
    filename="";

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

void MainWindow::on_input_image_button_clicked()   //检索图像
{


         QFileDialog*  fd = new QFileDialog(this);
         filename = fd->getOpenFileName();



//         std::string fileName= (fd->getOpenFileName()).toStdString();




//
//         QImage m1= MatToQImage(cvim);
//          QImage *input_image = new QImage(m1);
//         ui->input_image_lable->setPixmap(QPixmap::fromImage(input_image));


         //自适应检索图像
    if(filename=="")   //未选择文件直接结束
    return ;


           cur_pimg.reset(new QPixmap(filename));              //pimg智能指针
//        std::unique_ptr<QPixmap>pimg; pimg(new QPixmap(filename));


         cur_pimg->scaled(ui->input_image_lable_2->size(),Qt::KeepAspectRatio);
         ui->input_image_lable_2->setScaledContents(true);
         ui->input_image_lable_2->setPixmap(*cur_pimg);



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

void MainWindow::on_input_image_button_2_clicked()
{
    QFileDialog*  fd = new QFileDialog(this);
    stlfilename = fd->getOpenFileName();



//       QMessageBox *m=new QMessageBox();
//       m->setText(stlfilename);
//       m->show();


         Qt3DExtras::Qt3DWindow *view= new Qt3DExtras::Qt3DWindow();
         Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
         stlloader *modifier=new stlloader(rootEntity,view,stlfilename);
       modifier->LoadSTL();
       modifier->show();





//          Qt3DRender::QCamera *camera = view->camera();
//          camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
//          camera->setPosition(QVector3D(0, 0, 320.0f));
//          camera->setViewCenter(QVector3D(0, 0, 0));

//          Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
//          camController->setCamera(camera);

//          Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
//          Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
//          light->setColor("white");
//          light->setIntensity(1);
//          lightEntity->addComponent(light);


//          modifier->LoadSTL();

//          view->setRootEntity(rootEntity);

//          view->show();


}
