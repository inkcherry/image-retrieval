#ifndef CLICKLABLE_H
#define CLICKLABLE_H
#include<QLabel>
#include<QString>
#include<QWidget>
#include<QMainWindow>
#include<QMessageBox>
class clicklabel : public QLabel
{
    Q_OBJECT
public:
    clicklabel(QWidget *parent);

    ~clicklabel(){}
signals:
   void  clicklabel::qlclick(clicklabel *clicked);


protected:
    void mouseReleaseEvent( QMouseEvent* );
private:
    QString m_str;
};

#endif // CLICKLABLE_H
