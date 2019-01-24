#include <iostream>

using namespace std;

//父类
class Base
{
public:
    Base(){}     		 //构造函数
    ~Base(){}    		 //析构函数
    virtual void showinfo(){cout<<"Base::showinfo()"<<endl;}
    virtual void show(){cout<<"Base::show()"<<endl;}
private:
    int data;
};


//子类
class Child:public Base        //继承父类
{
public:
    Child(){}			//构造函数
    ~Child(){}			 //析构函数
    virtual void show(){cout<<"Child::show()"<<endl;}
    virtual void print(){}
private:
    int dataC;
};


int main(int argc, char *argv[])
{
#if 0
    Base b;                  /*vptr指针中的函数分别是Base::showinfo, Child::show(), Child::print()
                               可通过调试得知，将断点设置在对象那一行，就会生成虚表*/
    cout<<sizeof(b)<<endl;
    b.show();
    b.showinfo();
#endif
    Child a;
    Child *aptr = (Child*)&a;
    aptr->show();             // 这里的show函数其实是子类的函数
                              /*vptr指针中的函数分别是Base::showinfo, Child::show(), Child::print()
                               可通过调试得知，将断点设置在对象那一行，就会生成虚表*/

    Child c;
    Base *bptr = (Base*)&c;
    bptr->show();           // 这里的show函数其实是子类的函数
                            /*vptr指针中的函数分别是Base::showinfo, Child::show(), Child::print()
                            可通过调试得知，将断点设置在对象那一行，就会生成虚表*/


    return 0;
}
