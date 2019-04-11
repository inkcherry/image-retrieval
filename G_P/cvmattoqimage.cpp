//实现Qimage和cv::Mat的转化
#include"cvmattoqimage.h"

cv::Mat QImageToMat(QImage& image)
{
    cv::Mat mat;
    switch (image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        break;
    case QImage::Format_Grayscale8:
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    }
    return mat;
}


QImage	MatToQImage(cv::Mat& mtx)
{
    switch (mtx.type())
    {
        case CV_8UC1:
        {
        QImage img((const unsigned char *)(mtx.data), mtx.cols, mtx.rows, mtx.cols, QImage::Format_Grayscale8);
        return img;
        }
        break;
        case CV_8UC3:
        {
        QImage img((const unsigned char *)(mtx.data), mtx.cols, mtx.rows, mtx.cols * 3, QImage::Format_RGB888);
        return img.rgbSwapped();
        }
        break;
        case CV_8UC4:
         {
        QImage img((const unsigned char *)(mtx.data), mtx.cols, mtx.rows, mtx.cols * 4, QImage::Format_ARGB32);
        return img;
        }
        break;
        default:
        {
        QImage img;
        return img;
        }
    break;
    }
}

QPixmap MatToQpixmat(cv::Mat& mtx)  //这两个是用过Qimage间接转过来的
{
    return QPixmap::fromImage( MatToQImage( mtx ) );

}
cv::Mat QPixmapToMat(QPixmap& pimage)  //这两个是用过Qimage间接转过来的
{
     QImage qimg=pimage.toImage();
    return QImageToMat( qimg );
}

