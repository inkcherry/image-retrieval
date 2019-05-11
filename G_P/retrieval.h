#ifndef RETRIEVAL_H
#define RETRIEVAL_H
#include<hsv.h>
#include<set>
#include<map>


struct img_node{
    std::pair<int,hsv*>node;
    img_node(int &dis,hsv*hsv_)
    {node =std::make_pair(dis,hsv_);}
    bool operator<(img_node &o_node) const
    {
        return this->node.first < o_node.node.first;
    }
};

class retrieval
{
public:
    retrieval(hsv *hsv_,int num);
    hsv *main_hsv; //被检索的图片
    std::multiset<img_node*> img_list;    //单调数组   int是距离 文件路径*hsv里有
    int number;    //被检索的图片
    void retr();
    int *dis_h;
    int *dis_s;
    int *dis_v;

    void show();
};

#endif // RETRIEVAL_H
