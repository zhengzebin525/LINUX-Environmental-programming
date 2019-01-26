#include <iostream>
#include <list>               //链表的STL库
using namespace std;


int main(int argc, char *argv[])
{
    printf("===================创建新链表==================\n");

    list<int> data;                         //创建一条int型的新链表

    data.push_back(100);                    //创建新节点，放在链表后
    data.insert(data.begin(), 2, 200);      //插入节点，插在xx节点之前
    data.push_back(300);
    data.push_front(400);                   //创建新节点，放在表前

    //遍历链表，在此之前必须有一个迭代器
    list<int>::iterator it;             //迭代器,it是节点指针，即节点地址
    //打印链表
    for(it=data.begin(); it!=data.end(); it++)
    {
        cout<<*it<<" ";          //因为it是指针，取出数值需要解引用
    }                            //这样写打印出来可以组成一条横链表的形式
    cout<<endl;

    printf("===================删除第一个元素==================\n");

    data.pop_front();                      // 删除第一个元素
    for(it=data.begin();it!=data.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    printf("===================删除最后一个元素==================\n");
    data.pop_back();                        //删除最后一个元素
    for(it=data.begin();it!=data.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    printf("===================链表查找并删除指定元素==================\n");

    cout<<"input the value that you want to delate:"<<" ";
    int value;
    cin>>value;                  //从外部输入要删除的数
    cout<<endl;

    int flag = 0;
    //查找
    for(it=data.begin(); it!=data.end(); it++)    //会陷入无限循坏中，必须跳出来
    {
        if(*it == 100)
        {
            flag = 1;
            break;
        }
    }
    data.remove(100);

    if(flag == 0)          //如果输入的要删除的数是链表中没有的
    {
        cout<<"error value!"<<endl;
    }
    //打印链表
    for(it=data.begin();it!=data.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
