#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

class MyTime
{
    public:
        MyTime();
        MyTime(int n_hour, int n_minute);
        virtual ~MyTime();

        int Gethour() { return m_hour; }
        void Sethour(int val) { m_hour = val; }
        int Getminute() { return m_minute; }
        void Setminute(int val) { m_minute = val; }

        void Display();

        // ���������
        MyTime operator+(const MyTime& t);
        MyTime operator*(const double d_mul);

        // ��Ԫ����
        friend MyTime operator*(const double d_mul, MyTime& t);

    protected:

    private:
        int m_hour;
        int m_minute;
};

#endif // MYTIME_H
