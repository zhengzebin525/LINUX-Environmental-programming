#include <iostream>

using namespace std;

class Data
{
public:
    Data(){};
    ~Data(){};

public:
    static void printData(string msg)   //static 修饰成员函数
    {
        cout<<"["<<msg<<"]"<<endl;
        //cout<<number<<endl;           //此语句是错误的，此时number变量没有用static修饰，所以现在还不能用，必须创建对象时候才能用
    }

    static string printstring(int data)      //将整型类型转换为字符串类型
    {
        char buf[100] = {0};
        sprintf(buf, "%d", data);
        string str = buf;
        return str;
    }

    static int fun()        //因为sdata是static修饰的，所以可以被static成员函数使用
    {
        return sdata;      //  sdata是static修饰的，所以可以再任何地方使用
       //return anum;      //此语句错误，因为abum不是static修饰的，不能用在static修饰的成员函数，换成number也一样不行
    }

public:
    int anum;

private:
    int number;
    static int sdata;         //static 修饰成员变量
};

int Data::sdata = 100;          /*静态成员变量只能在类外和main函数外赋值，静态成员在main函数创建对象之前就可以用了
                                但是要注意，程序的执行都是从主函数开始的*/

int main(int argc, char *argv[])
{

    Data::printData("helloworld");    //如上文所说，此函数是静态修饰的，所以不创建对象也能用

    printf("============整型转换为字符串================\n");
    int data = 123456;
    cout<<Data::printstring(data)<<endl;

    printf("=====static不能访问非static修饰的成员==========\n");
    cout<<Data::fun()<<endl;

    return 0;
}
