#ifndef RETRIEVAL_H
#define RETRIEVAL_H
#include<hsv.h>
#include<set>
#include<map>


struct img_node{
    std::pair<int,hsv*>node;
    img_node(int &dis,hsv*hsv_)
    {node =std::make_pair(dis,hsv_);}

//    bool operator<(const img_node &o_node) const   //指针类型不能这样排序
//    {
//        return this->node.first < o_node.node.first;
//    }
};

struct img_cmp{

        bool operator()(const img_node *A1,const img_node*A2) const   //指针类型不能这样排序
        {
           return A1->node.first < A2->node.first;
        }
};
class retrieval
{
public:
    retrieval(hsv *hsv_,int num);
    hsv *main_hsv; //被检索的图片
    std::multiset<img_node*,img_cmp> img_list;    //单调数组   int是距离 文件路径*hsv里有
    std::multiset<img_node*,img_cmp> retrieval::get_img_list();
    int number;    //被检索的图片
    void retr();
    int *dis_h;
    int *dis_s;
    int *dis_v;

    void show();
};

#endif // RETRIEVAL_H
