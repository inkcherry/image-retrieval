



#include <mainwindow.h>
#include<QApplication>
#include "unit_test.cpp"
using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{


     QApplication a(argc, argv);
        MainWindow w;
        w.show();

//   string path = "F:\\te\\3.jpg";
//   hsv *m=new hsv(path);
//   m->show();


  return a.exec();








}

