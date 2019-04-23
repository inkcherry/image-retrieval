#include<string>
#include"hsv.h"
using namespace  std;
using namespace  cv;
void test_hsv()
{
    std::string path="F:\te\3.jpg";
    hsv *m =new hsv(path);
    m->show();
}

void test_fun()
{

    std::string path="F:\\te\\55.jpg";
    IplImage * cur_image = cvLoadImage(path.c_str(),1);


    int k=33;
    k++;
//    IplImage * hsv_img=cvCreateImage(cvSize(395, 413),IPL_DEPTH_8U,3);	//注意图像必须和输入图像的size，颜色位深度，通道一致
    CvSize size=cvSize((*cur_image).width,((*cur_image)).height);
    IplImage * hsv_img = cvCreateImage(size, 8,3);
//    IplImage* hsv_img=cvCreateImage( cvSize(360,640), IPL_DEPTH_8U,3 );
//   IplImage * hsv_img=cvCreateImage(cvSize(cur_image->width, cur_image->height), cur_image->depth, cur_image->nChannels);	//注意图像必须和输入图像的size，颜色位深度，通道一致
    cvZero(hsv_img);

    cvCvtColor(cur_image, hsv_img, CV_BGR2HSV);//CV_BGR2HSV
  IplImage * cur_img=cur_image;

  IplImage * image_h = cvCreateImage(size, IPL_DEPTH_8U, 1);//注意，必须是单通道图像
    IplImage *image_s = cvCreateImage(size, IPL_DEPTH_8U, 1);//注意，必须是单通道图像
     IplImage * image_v = cvCreateImage(size, IPL_DEPTH_8U, 1);//注意，必须是单通道图像

    cvSplit(cur_image, image_h, image_s, image_v, NULL); //注意Opencv中hsv没有顺序问题




    //创建H通道的直方图
    int arr_size_h = 255;                 //定义一个变量用于表示直方图行宽
    float hranges_arr_h[] = { 0, 180 };       //图像方块范围数组
    float *phranges_arr_h = hranges_arr_h;      //cvCreateHist参数是一个二级指针，所以要用指针指向数组然后传参
    CvHistogram* hist_h = cvCreateHist(1, &arr_size_h, CV_HIST_ARRAY, &phranges_arr_h, 1);    //创建一个一维的直方图，行宽为255，多维密集数组，方块范围为0-180，bin均化

    //创建S通道的直方图
    int arr_size_s = 255;                 //定义一个变量用于表示直方图行宽
    float hranges_arr_s[] = { 0, 255 };       //图像方块范围数组
    float *phranges_arr_s = hranges_arr_s;      //cvCreateHist参数是一个二级指针，所以要用指针指向数组然后传参
    CvHistogram* hist_s = cvCreateHist(1, &arr_size_s, CV_HIST_ARRAY, &phranges_arr_s, 1);    //创建一个一维的直方图，行宽为255，多维密集数组，方块范围为0-255，bin均化

    //创建V通道的直方图
    int arr_size_v = 255;                 //定义一个变量用于表示直方图行宽
    float hranges_arr_v[] = { 0, 255 };       //图像方块范围数组
    float *phranges_arr_v = hranges_arr_v;      //cvCreateHist参数是一个二级指针，所以要用指针指向数组然后传参
    CvHistogram* hist_v = cvCreateHist(1, &arr_size_v, CV_HIST_ARRAY, &phranges_arr_v, 1);    //创建一个一维的直方图，行宽为255，多维密集数组，方块范围为0-255，bin均化

     //计算H通道的直方图大小

    cvCalcHist(&image_h,hist_h, 0, 0);
    //计算S通道的直方图大小
    cvCalcHist(&image_s, hist_s, 0, 0);

    //计算V通道的直方图大小
    cvCalcHist(&image_v, hist_v, 0, 0);

    //H通道的直方图缩小
    float max_val_h;  //用于存储获取到的最大值
    cvGetMinMaxHistValue(hist_h, 0, &max_val_h, 0, 0); //获取直方图最大值
    cvConvertScale(hist_h->bins, hist_h->bins, max_val_h ? 180 / max_val_h : 0., 0);  //按比例缩小直方图

    //S通道的直方图缩小
    float max_val_s;  //用于存储获取到的最大值
    cvGetMinMaxHistValue(hist_s, 0, &max_val_s, 0, 0); //获取直方图最大值
    cvConvertScale(hist_s->bins, hist_s->bins, max_val_s ? 255 / max_val_s : 0., 0);  //按比例缩小直方图

    //V通道的直方图缩小
    float max_val_v;  //用于存储获取到的最大值
    cvGetMinMaxHistValue(hist_v, 0, &max_val_v, 0, 0); //获取直方图最大值
    cvConvertScale(hist_v->bins, hist_v->bins, max_val_v ? 255 / max_val_v : 0., 0);  //按比例缩小直方图


        //创建一个空白图像用于绘制直方图
            IplImage *histimg = cvCreateImage(cvSize(320, 200), 8, 3);
            cvZero(histimg);    //清空histimag-imagedata数据

            //开始绘制H通道的直方图
            int bin_h;
            bin_h = histimg->width / arr_size_h; //得到开始绘制点位置

            for (int i = 0; i < arr_size_h; i++)
            {
                double val = (cvGetReal1D(hist_h->bins, i)*histimg->height / 360);//获取矩阵元素值，并转换为对应高度
                CvScalar color = CV_RGB(255, 0, 0);
                cvRectangle(histimg, cvPoint(i*bin_h, histimg->height), cvPoint((i + 1)*bin_h, (int)(histimg->height - val)), color, 1, 8, 0);
            }

            //创建一个空白图像用于绘制直方图
            IplImage *sistimg = cvCreateImage(cvSize(320, 200), 8, 3);
            cvZero(sistimg);    //清空histimag-imagedata数据

            //开始绘制S通道的直方图
            int bin_s;
            bin_s = sistimg->width / arr_size_s; //得到开始绘制点位置

            for (int i = 0; i < arr_size_s; i++)
            {
                double val = (cvGetReal1D(hist_s->bins, i)*sistimg->height / 255);//获取矩阵元素值，并转换为对应高度
                CvScalar color = CV_RGB(0, 255, 0);
                cvRectangle(sistimg, cvPoint(i*bin_s, sistimg->height), cvPoint((i + 1)*bin_s, (int)(sistimg->height - val)), color, 1, 8, 0);
            }

            //创建一个空白图像用于绘制直方图
            IplImage *vistimg = cvCreateImage(cvSize(320, 200), 8, 3);
            cvZero(vistimg);    //清空histimag-imagedata数据

            //开始绘制V通道的直方图
            int bin_v;
            bin_v = vistimg->width / arr_size_v; //得到开始绘制点位置

            for (int i = 0; i < arr_size_v; i++)
            {
                double val = (cvGetReal1D(hist_v->bins, i)*vistimg->height / 255);//获取矩阵元素值，并转换为对应高度
                CvScalar color = CV_RGB(0, 0, 255);
                cvRectangle(vistimg, cvPoint(i*bin_v, vistimg->height), cvPoint((i + 1)*bin_v, (int)(vistimg->height - val)), color, 1, 8, 0);
            }




              //显示图像
                cvNamedWindow("image_hsv",0);
                cvNamedWindow("H",0);
                cvNamedWindow("S",0);
                cvNamedWindow("V",0);
                cvShowImage("image_hsv", hsv_img);
                cvShowImage("H", histimg);
                cvShowImage("S", sistimg);
                cvShowImage("V", vistimg);
                cvWaitKey(0);//message
                 cvShowImage("image_hsv", cur_img);

               cv::waitKey(0);

}
