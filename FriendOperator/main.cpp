#include <iostream>
#include <MyTime.h>
int main()
{
    MyTime t1 = MyTime(8,56);
    MyTime t2 = MyTime(17,32);
    t1.Display();
    t2.Display();
    // 重载加法
    MyTime tt = t1 + t2;
    tt.Display();
    // 重载乘法
    double d_mul = 1.5;
    tt = t1 * d_mul;
    tt.Display();

    //友元函数
    tt = d_mul * t1;
    std::cout<<tt<<std::endl;
    return 0;
}
