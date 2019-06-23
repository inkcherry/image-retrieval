#include "retrieval.h"

retrieval::retrieval(hsv* hsv_,int num):main_hsv(hsv_),number(num)
{
    dis_h=new int[main_hsv->arr_size_h];
    dis_s=new int[main_hsv->arr_size_s];
    dis_v=new int[main_hsv->arr_size_v];

    for(int i=0;i<main_hsv->arr_size_h;i++)
    {
        dis_h[i]=cvGetReal1D(main_hsv->hist_h->bins, i);
    }
    for(int i=0;i<main_hsv->arr_size_s;i++)
    {
        dis_s[i]=cvGetReal1D(main_hsv->hist_s->bins, i);
    }
    for(int i=0;i<main_hsv->arr_size_v;i++)
    {
        dis_v[i]=cvGetReal1D(main_hsv->hist_v->bins, i);
    }

}
void retrieval::retr()
{
    std::string basepath="C:\\Users\\inkcherry\\Desktop\\img\\";


    int dis_all=0;

    for(int i=0;i<=28;i++)
    {
        std::string path = (basepath+"kk"+std::to_string(i)+".jpg");

        hsv *temp_hsv =new hsv(path);

        dis_all=0;
        for(int i=0;i<main_hsv->arr_size_h;i++)
        {
            dis_all+=pow(dis_h[i]-cvGetReal1D(temp_hsv->hist_h->bins, i),2);
        }

        for(int i=0;i<main_hsv->arr_size_s;i++)
        {
            dis_all+=pow(dis_s[i]-cvGetReal1D(temp_hsv->hist_s->bins, i),2);
        }
        for(int i=0;i<main_hsv->arr_size_v;i++)
        {
            dis_all+=pow(dis_v[i]-cvGetReal1D(temp_hsv->hist_v->bins, i),2);
        }
        dis_all=(int)  sqrt(dis_all);
        img_node* temp_node=new img_node(dis_all,temp_hsv);
        img_list.insert(temp_node);
    }
}
void retrieval::show()
{
    int cnt=0;
    qDebug()<<"start"<<endl;
    for(auto it=img_list.begin();it!=img_list.end();++it)
    {
        std::string debugstr=(*it)->node.second->filepath;
        std::string disstr = std::to_string((*it)->node.first);


        qDebug() << QString::fromStdString(debugstr)<<" "<<QString::fromStdString(disstr)<<endl;
        cnt++;
        if(cnt==number)
            break;
    }
}
std::multiset<img_node*,img_cmp> retrieval::get_img_list()
{
    return img_list;
}

