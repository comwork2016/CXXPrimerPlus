#include "MyTime.h"

MyTime::MyTime()
{
    //ctor
}

MyTime::MyTime(int n_hour,int n_minute)
{
    this->m_hour = n_hour;
    this->m_minute = n_minute;
}

MyTime MyTime::operator+(const MyTime& t)
{
    MyTime total;
    total.m_minute = this->m_minute + t.m_minute;
    total.m_hour =this->m_hour + t.m_hour + total.m_minute/60;
    total.m_hour = total.m_hour%24;
    total.m_minute = total.m_minute %60;
    return total;
}

MyTime MyTime::operator*(const double d_mul)
{
    MyTime t;
    long l_minute = (this->m_hour * 60 + this->m_minute) * d_mul;
    t.m_hour = l_minute/60;
    t.m_hour = t.m_hour%24;
    t.m_minute = l_minute %60;
    return t;
}

MyTime operator*(const double d_mul, MyTime& t)
{
    return t*d_mul;
}

void MyTime::Display()
{
    using std::cout;
    using std::endl;
    cout<<"MyTime is "<<this->m_hour<<":"<<this->m_minute<<endl;
}

MyTime::~MyTime()
{
    //dtor
}
