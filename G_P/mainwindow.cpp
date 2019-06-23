#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{file:///C:/Users/inkcherry/AppData/Local/Temp/Test.pro

    ui->setupUi(this);
    curfile=nullptr;
    filename="";
    result_list.push_back(ui->R1);
    result_list.push_back(ui->R2);
    result_list.push_back(ui->R3);
    result_list.push_back(ui->R4);
    result_list.push_back(ui->R5);
    result_list.push_back(ui->R6);
    result_list.push_back(ui->R7);
    result_list.push_back(ui->R8);
    result_list.push_back(ui->R9);

    using namespace std;


    show_map.insert(pair<QLabel*,int>(ui->R1,1));
    show_map.insert(pair<QLabel*,int>(ui->R2,2));
    show_map.insert(pair<QLabel*,int>(ui->R3,3));
    show_map.insert(pair<QLabel*,int>(ui->R4,4));
    show_map.insert(pair<QLabel*,int>(ui->R5,5));
    show_map.insert(pair<QLabel*,int>(ui->R6,6));
    show_map.insert(pair<QLabel*,int>(ui->R7,7));
    show_map.insert(pair<QLabel*,int>(ui->R8,8));
    show_map.insert(pair<QLabel*,int>(ui->R9,9));

//    connect(ui->R1 , SIGNAL(linkActivated(QString)), this, SLOT(on_R_clicked()));

    text_list.push_back(ui->T1);
    text_list.push_back(ui->T2);
    text_list.push_back(ui->T3);
    text_list.push_back(ui->T4);
    text_list.push_back(ui->T5);
    text_list.push_back(ui->T6);
    text_list.push_back(ui->T7);
    text_list.push_back(ui->T8);
    text_list.push_back(ui->T9);

    for(auto i =result_list.begin();i!=result_list.end();++i)
      (*i)->installEventFilter(this);//安装事件过滤器
    for(int i=0;i<9;i++)
        have_result[i]=0;
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

void MainWindow::on_pushButton_5_clicked()
{
       std::string path = filename.toStdString();
       hsv *m=new hsv(path);
       m->showdetail();
}

void MainWindow::on_pushButton_6_clicked()
{
    for(int i=0;i<9;i++)
        have_result[i]=0;

    std::string path = filename.toStdString();

    hsv *main_hsv=new hsv(path);

//    main_hsv->show();

    QString  text=ui->input_count_2->text();
    int  num = text.toInt();


    ret=new retrieval(main_hsv,num);
    ret->retr();
//    ret->show(); //debug
    img_list=ret->get_img_list();
    int cnt=0;


//    QLabel * temp=nullptr;
    auto lable_list_it=result_list.begin();

    auto hsv_list_it=img_list.begin();

    auto text_list_it=text_list.begin();

//    for(auto it=img_list.begin();it!=img_list.end();++it)
//    {
//        std::string debugstr=(*it)->node.second->filepath;
//        std::string disstr = std::to_string((*it)->node.first);


//        qDebug() << QString::fromStdString(debugstr)<<" "<<QString::fromStdString(disstr)<<endl;
//        cnt++;
//        if(cnt==num)
//            break;
//    }

//    cnt=0;




    for(;;)
    {



         QString temp_Qstr = QString::fromStdString((*hsv_list_it)->node.second->filepath);
//        std::string for_test=temp_Qstr.toStdString();
         QPixmap *temp_pimg=new QPixmap(temp_Qstr);              //pimg智能指针


        temp_pimg->scaled((*lable_list_it)->size(),Qt::KeepAspectRatio);
        (*lable_list_it)->setScaledContents(true);
        (*lable_list_it)->setPixmap(*temp_pimg);


//        std::string disstr = std::to_string((*it)->node.first);

//        QString d1=QString::fromLocal8Bit("差异度：");

//       QString d1=QStringLiteral("我是中文");
//        QString d1=QString::fromWCharArray(L"测试中文");
//        QString d1=QString::fromLocal8Bit("测试中文");
        QString d1= "差异度：";
        QString distext=QString::fromStdString(std::to_string((*hsv_list_it)->node.first));

        (*text_list_it)->setText(d1+distext);
        have_result[cnt]=true;
        cnt++;
        if(cnt==num)
            break;
        ++lable_list_it;
        ++hsv_list_it;
        ++text_list_it;
    }

}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)//这是Qobject一个虚函数
{
    if (obj == ui->R1||obj == ui->R2||obj == ui->R3||obj == ui->R4||obj == ui->R5||obj == ui->R6||obj == ui->R7||obj == ui->R8||obj == ui->R9)
  {
      if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
      {
//          QMouseEvent *mouseEvent=event;

          QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
//          QMouseEvent*mouseEvent=(QMouseEvent*)event;
//          QMouseEvent *mouseEvent=event;
          if(mouseEvent->button() == Qt::LeftButton)
          {
//
              auto iter=show_map.find((QLabel*)obj);
              int index=iter->second;

//                      std::string test_index = std::to_string(index);    pass

//                QString wc=QString::fromStdString(test_index);
//                      QMessageBox::information(NULL,"点击",wc,
//                       QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);




                if (have_result[index]=false)    //这个label没有图像
                return false;
              auto hsv_list_it=img_list.begin();


            for(int i=1;i<index;i++)
            {
                  hsv_list_it++;
            }



            QString temp_Qstr = QString::fromStdString((*hsv_list_it)->node.second->filepath);

            std::string temp_str=temp_Qstr .toStdString();


//            QString temp_Qstr_index = Qstr;
//                        QMessageBox::information(NULL,"点击",temp_Qstr,
//                         QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);

            int st =0,en=0;
            for(int i=0;i<temp_str.size();++i)
            {
                        if(isdigit(temp_str[i]))
                        {st=i;
                        break;
                        }
            }

            for(int i=st;i<temp_str.size();++i)
            {
                        if(!isdigit(temp_str[i]))
                        {en=i-1;
                        break;
                        }
            }
            int len=en-st+1;
            std::string path_index=temp_str.substr(st,len);

//            QString path_Qindex = QString::fromStdString(path_index);
//            QMessageBox::information(NULL,"点击",path_Qindex,
//             QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);




            QDesktopServices::openUrl;
            QString md_url=QString::fromStdString("F:/3ddatabase/md"+path_index);
            QDesktopServices::openUrl(QUrl(md_url, QUrl::TolerantMode)); //打不开有空格或者共享的

//            QDesktopServices::openUrl(QUrl("file:C:/111", QUrl::TolerantMode));


//              QString temp = QString::number(index);


//              auto click_dilog_hsv = result_list[index];

//             QMessageBox::information(NULL,"点击",temp,
//             QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
              return true;
          }
          else
          {
              return false;
          }
      }
      else
      {
          return false;
      }
  }
  else
  {
      // pass the event on to the parent class
      return QMainWindow::eventFilter(obj, event);
  }

}

//void MainWindow::on_R_clicked(){
//    QMessageBox *m=new QMessageBox();
//    m->setText("3234");

//    m->show();
//}
