



#include <mainwindow.h>
#include<QApplication>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{

//     cvNamedWindow("window", CV_WINDOW_NORMAL);
//     imshow("window",image);
//     waitKey(0);

     QApplication a(argc, argv);
        MainWindow w;
        w.show();
       return a.exec();
 }

