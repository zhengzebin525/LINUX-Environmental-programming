运算符重载：
	是一种特殊的函数重载，函数名是固定的。

operator是C++中的关键字，（又称重载操作符），和运算符一起使用。

为什么需要用到运算符重载？
	对于编译器来说，只支持基本梳理类型和标准库中提供的类（class），对于用户自己定义的类，比如想类中实现一些基本操作加减乘除，比较大小，判断对错，则需要用户自定义自己实现。
	举个例子：我们想要比较两个人的年龄大小，首先定义person这个类，判断的依据是person中的age，用到的操作符是==，这时候“==”操作符已经跟标准库隔离开了，如果直接使用，编译器就会报错说“==”没有定义。
	所以才需要用到操作符重载，原因就是编译器在是是实现的时候，已经提供了“==”这个操作符并规定好了功能，你想用一摸一样的操作符，并且让它成为用户自定义的class中的内部成员，实现的方法就是操作符重载。

   运算符                 函数重载
     + 		complex operator+(complex &num)    complex是类名，&num是另一个操作数的地址
     -		complex operator-(complex &num)
     *		complex operator*(complex &num)
     /		complex operator/(complex &num)



ostream&   指的是引用
	为了支持连续，输出必须返回一个ostream的引用，这样，“<<”就可以连续输出

    <<		ostream& operator <<(ostream& out, complex &num)
    >>		ostream& operator >>(ostream& out, complex &num)
