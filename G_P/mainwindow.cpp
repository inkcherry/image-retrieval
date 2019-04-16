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
//         cvNamedWindow("window", CV_WINDOW_NORMAL);              //加载cvmat  用于后续的处理
//                        imshow("window",*cur_cvmat);



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

         Qt3DExtras::Qt3DWindow *view= new Qt3DExtras::Qt3DWindow();
         Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
         stlloader *modifier=new stlloader(rootEntity,view,stlfilename);
       modifier->LoadSTL();
       modifier->show();


}

void MainWindow::on_pushButton_3_clicked()
{
        using namespace cv;


    //这里有个bug  用qpixamp转换过去的图像用双边滤波会有bug，因此先用opencv iread直接重新读取一遍获取cvmat。
//        //创建窗口
//       Mat in= *cur_cvmat;
//        namedWindow("in");
//        namedWindow("out");

//        //显示原图
//        imshow("in",in );

//        //进行双边滤波操作
//        Mat out;
//        bilateralFilter ( in, out, 25, 25*2, 25/2 );

//        //显示效果图
//        imshow("out",out );

//        waitKey( 0 );


            //创建窗口
           *cur_cvmat=imread(filename.toStdString());

            namedWindow("in");
            namedWindow("out");

            //显示原图
            imshow("in", *cur_cvmat );

            //进行双边滤波操作
            Mat out;
            bilateralFilter ( *cur_cvmat, out, 25, 25*2, 25/2 );

            //显示效果图
            imshow( "out" ,out );

            waitKey( 0 );

}

void MainWindow::on_pushButton_4_clicked()
{
    using namespace  cv;


    Mat src=imread(filename.toStdString());


//    Mat src = imread( argv[1], 1 );
    Mat samples(src.rows * src.cols, 3, CV_32F);
    for( int y = 0; y < src.rows; y++ )
      for( int x = 0; x < src.cols; x++ )
        for( int z = 0; z < 3; z++)
          samples.at<float>(y + x*src.rows, z) = src.at<Vec3b>(y,x)[z];


    int clusterCount = 2;
    Mat labels;
    int attempts = 1;
    Mat centers;
    kmeans(samples, clusterCount, labels, TermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 10000, 0.0001), attempts, KMEANS_PP_CENTERS, centers );


    Mat new_image( src.size(), src.type() );
    for( int y = 0; y < src.rows; y++ )
      for( int x = 0; x < src.cols; x++ )
      {
        int cluster_idx = labels.at<int>(y + x*src.rows,0);
        new_image.at<Vec3b>(y,x)[0] = centers.at<float>(cluster_idx, 0);
        new_image.at<Vec3b>(y,x)[1] = centers.at<float>(cluster_idx, 1);
        new_image.at<Vec3b>(y,x)[2] = centers.at<float>(cluster_idx, 2);
      }
    imshow( "clustered image", new_image );
    waitKey( 0 );




}
