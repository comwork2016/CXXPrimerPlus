#ifndef VIRTUALDERIVED_H_INCLUDED
#define VIRTUALDERIVED_H_INCLUDED

/**
    ÐéÄâ¼Ì³Ð
*/

class VB
{
    public:
        int ib;
        char cb;
    public:
        VB():ib(10),cb('B') {}

        virtual void f() { cout << "VB::f()" << endl;}
        virtual void Bf() { cout << "VB::Bf()" << endl;}
};

class VB1 : virtual public VB
{
    public:
        int ib1;
        char cb1;
    public:
        VB1():ib1(111),cb1('1') {}

        virtual void f() { cout << "VB1::f()" << endl;}
        virtual void f1() { cout << "VB1::f1()" << endl;}
        virtual void Bf1() { cout << "VB1::Bf1()" << endl;}

};

class VB2: virtual public VB
{
    public:
        int ib2;
        char cb2;
    public:
        VB2():ib2(112),cb2('2') {}

        virtual void f() { cout << "VB2::f()" << endl;}
        virtual void f2() { cout << "VB2::f2()" << endl;}
        virtual void Bf2() { cout << "VB2::Bf2()" << endl;}

};

class VD : public VB1, public VB2
{
    public:
        int id;
        char cd;
    public:
        VD():id(1100),cd('D') {}

        virtual void f() { cout << "VD::f()" << endl;}
        virtual void f1() { cout << "VD::f1()" << endl;}
        virtual void f2() { cout << "VD::f2()" << endl;}
        virtual void Df() { cout << "VD::Df()" << endl;}

};

#endif // VIRTUALDERIVED_H_INCLUDED
