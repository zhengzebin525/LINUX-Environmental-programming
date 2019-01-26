#include <iostream>

using namespace std;

class complex
{
public:
    complex(int r, int i):real(r),image(i){}

    complex operator+(complex &num)      //类中“+”的函数重载,&num指的是一个加数的地址
    {
        complex add(0,0);
        add.real = this->real + num.real;
        add.image = this->image + num.image;
        return add;
    }

    complex operator-(complex &num)    //类中“-”的函数重载，&num指的是被减数的地址
    {
        complex sub(0,0);
        sub.real = this->real - num.real;
        sub.image = this->image - num.image;
        return sub;
    }

    complex operator*(complex &num)   //类中“*”的函数重载，&num指的是另一个乘数的地址
    {
        complex mul(0,0);
        mul.real = this->real * num.real;
        mul.image = this->image * num.image;
        return mul;
    }

    complex operator/(complex &num)    //类中“/”的函数重载，&num指的是被除数的地址
    {
        complex div(0,0);
        div.real = this->real / num.real;
        div.image = this->image / num.image;
        return div;
   }


    void show()
    {
        cout<<"["<<this->real<<","<<this->image<<"]"<<endl;
    }

private:
        int real;        //代表虚数的实部
        int image;		 //代表虚数的虚部
        friend ostream& operator << (ostream& out, complex &num);  //将“<<”函数重载声明为类的友元函数，这样此函数重载就可以使用类中的成员
        friend ostream& operator >>(ostream& in, complex &num);
};

ostream& operator <<( ostream& out, complex &num)
{
    out<<"["<<num.real<<","<<num.image<<"]"<<endl;      //xxx.real和xxx.image都是类中的成员，因为此函数被声明为类的友元函数，所以可以使用类中的成员
    return out;
}

ostream& operator >>(ostream& in, complex &num)
{
    in<<"["<<num.real<<","<<num.image<<"]"<<endl;
    return in;
}

int main(int argc, char *argv[])
{
    int real1,image1;
    int real2,image2;

     printf("==============输入输出流函数重载==================\n");

    cout<<"input the first complex"<<endl;
    cin>>real1>>image1;

    cout<<"input the second complex"<<endl;
    cin>>real2>>image2;

    complex A(real1, image1);
    complex B(real2, image2);

    printf("==============加减乘除函数重载==================\n");
    complex ADD = A+B;  //相当于A.operator+(B)
    ADD.show();

    complex SUB = B-A;  //相当于A.operator-(B)
    SUB.show();

    complex MUL = A*B;  //相当于A.operator*(B)
    MUL.show();

    complex DIV = A/B;  //相当于A.operator/(B)
    DIV.show();

    printf("==============输出流函数重载==================\n");
    cout<<A<<B<<ADD<<SUB<<MUL<<DIV<<endl;


    return 0;
}
