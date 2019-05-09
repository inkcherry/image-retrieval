#ifndef RETRIEVAL_H
#define RETRIEVAL_H
#include<hsv.h>
#include<set>
#include<map>


class retrieval
{
public:
    retrieval();
    hsv *main_hsv; //被检索的图片
    std::multiset<map<int,hsv*>> list;   //单调数组
    int number;    //被检索的图片

};

#endif // RETRIEVAL_H
