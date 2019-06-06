#include "clicklable.h"



void clicklabel::mouseReleaseEvent(QMouseEvent *evt)
{
    emit click(this);
}

void  clicklabel::click(clicklabel *clicked)
{
  QMessageBox *m=new QMessageBox();
  m->setText("tttt");
  m->show();
}
