#include <iostream>
#include <MyTime.h>
int main()
{
    MyTime t1 = MyTime(8,56);
    MyTime t2 = MyTime(17,32);
    t1.Display();
    t2.Display();
    // ���ؼӷ�
    MyTime tt = t1 + t2;
    tt.Display();
    // ���س˷�
    double d_mul = 1.5;
    tt = t1 * d_mul;
    tt.Display();

    //��Ԫ����
    tt = d_mul * t1;
    std::cout<<tt<<std::endl;
    return 0;
}
