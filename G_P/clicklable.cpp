#include "clicklable.h"



void clicklabel::mouseReleaseEvent(QMouseEvent *evt)
{
    emit qlclick(this);
}

