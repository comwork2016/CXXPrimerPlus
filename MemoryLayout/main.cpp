#include <iostream>
#include "SingleDerived.h"
#include "MulDerived.h"
#include "DuplicatedDerived.h"
#include "VirtualDerived.h"

using namespace std;

typedef void(*Fun)(void);

/**
    ≤‚ ‘µ•“ªºÃ≥–
*/
void testSingleDerived()
{
    GrandChild gc;
    Fun pFun;
    int** pVtab = (int**)&gc;
    cout << "[0] GrandChild::" << endl;
    for (int i=0; (Fun)pVtab[0][i]!=NULL; i++)
    {
        pFun = (Fun)pVtab[0][i];
        cout << "    ["<<i<<"] ";
        pFun();
    }
    cout << "[1] Parent.iparent = " << (int)pVtab[1] << endl;
    cout << "[2] Child.ichild = " << (int)pVtab[2] << endl;
    cout << "[3] GrandChild.igrandchild = " << (int)pVtab[3] << endl;
}

/**
    ≤‚ ‘∂‡÷ÿºÃ≥–
*/
void testMulDerived()
{
    Derive d;
    Fun pFun;
    int** pVtab = (int**)&d;
    cout << "[0] Base1::" << endl;
    for (int i=0; i<4; i++)
    {
        pFun = (Fun)pVtab[0][i];
        cout << "    ["<<i<<"] ";
        pFun();
    }
    cout << "    [4] ";
    cout<<pFun<<endl;
    cout << "[1] Base1.ibase1 = " << (int)pVtab[1] << endl;

    int s = sizeof(Base1)/sizeof(int*);
    cout << "[" << s << "] Base2::"<<endl;
    pFun = (Fun)pVtab[s][0];
    for (int i=0; i<3; i++)
    {
        pFun = (Fun)pVtab[s][i];
        cout << "    ["<<i<<"] ";
        pFun();
    }
    pFun = (Fun)pVtab[s][3];
    cout << "    [3] ";
    cout<<pFun<<endl;
    cout << "["<< s+1 <<"] Base2.ibase2 = " << (int)pVtab[s+1] << endl;

    s = s + sizeof(Base2)/sizeof(int*);
    cout << "[" << s << "] Base3::"<<endl;
    pFun = (Fun)pVtab[s][0];
    for (int i=0; i<3; i++)
    {
        pFun = (Fun)pVtab[s][i];
        cout << "    ["<<i<<"] ";
        pFun();
    }
    pFun = (Fun)pVtab[s][3];
    cout << "    [3] ";
    cout<<pFun<<endl;

    s++;
    cout << "["<< s <<"] Base3.ibase3 = " << (int)pVtab[s] << endl;
    s++;
    cout << "["<< s <<"] Derive.iderive = " << (int)pVtab[s] << endl;
}

/**
    ≤‚ ‘÷ÿ∏¥ºÃ≥–
*/
void testDuplicatedDerived()
{
    int** pVtab = NULL;
    Fun pFun = NULL;
    D d;
    pVtab = (int**)&d;
    cout << "[0] D::B1::" << endl;
    for (int i=0; i<5; i++)
    {
        pFun = (Fun)pVtab[0][i];
        cout << "    ["<<i<<"] ";
        pFun();
    }
    pFun = (Fun)pVtab[0][5];
    cout << "    [5] " << pFun << endl;
    cout << "[1] B::ib = " << (int)pVtab[1] << endl;
    cout << "[2] B::cb = " << (char)(int)pVtab[2] << endl;
    cout << "[3] B1::ib1 = " << (int)pVtab[3] << endl;
    cout << "[4] B1::cb1 = " << (char)(int)pVtab[4] << endl;

    cout << "[5] D::B2::" << endl;
    for (int i=0; i<4; i++)
    {
        pFun = (Fun)pVtab[5][i];
        cout << "    ["<<i<<"] ";
        pFun();
    }
    pFun = (Fun)pVtab[5][4];
    cout << "    [4] " << pFun << endl;
    cout << "[6] B::ib = " << (int)pVtab[6] << endl;
    cout << "[7] B::cb = " << (char)(int)pVtab[7] << endl;
    cout << "[8] B2::ib2 = " << (int)pVtab[8] << endl;
    cout << "[9] B2::cb2 = " << (char)(int)pVtab[9] << endl;

    cout << "[10] D::id = " << (int)pVtab[10] << endl;
    cout << "[11] D::cd = " << (char)(int)pVtab[11] << endl;
}

/**
    ≤‚ ‘µ•“ª–ÈºÃ≥–
*/
void testSingleVirtualDerived()
{
    VB1 vb1;
    int **pVtab = NULL;
    pVtab = (int**)&vb1;
    Fun pFun = NULL;
    cout << "[0] VB1::" << endl;
    for(int i=0; i<3; ++i)
    {
        pFun = (Fun)pVtab[0][i];
        cout << "    ["<<i<<"] ";
        pFun();
    }
    cout << "    [3] ";
    cout << pVtab[0][3] << endl;

    cout << "[1] VB1::ib1 = ";
    cout << (int)pVtab[1] <<endl; //B1::ib1
    cout << "[2] VB1::cb1 = ";
    cout << (char)(int)pVtab[2] <<endl; //B1::ib1

    cout << "[3] VB::" << endl;
    pFun = (Fun)pVtab[3][0];
    for(int i=0; i<2; ++i)
    {
        pFun = (Fun)pVtab[3][i];
        cout << "    ["<<i<<"] ";
        pFun();
    }
    cout << "    [2] ";
    cout << (Fun)pVtab[3][2] << endl;

    cout << "[4] VB::ib = ";
    cout << (int)pVtab[4] <<endl; //B::ib
    cout << "[5] VB::cb = ";
    cout << (char)(int)pVtab[5] <<endl; //B::cb
}

/**
    ≤‚ ‘–ÈºÃ≥–
*/
void testVirtualDerived()
{
    VD vd;
    Fun pFun;
    int** pVtab = (int**)&vd;
    cout << "[0] VD::VB1::" << endl;
    for(int i=0; i<5; i++)
    {
        pFun = (Fun)pVtab[0][i];
        cout<<"     ["<<i<<"] ";
        pFun();
    }
    pFun = (Fun)pVtab[0][5];
    cout << "     [5] ";
    cout << pFun << endl;
    cout << "[1] VB1::ib1 = ";
    cout << (int)pVtab[1] <<endl; //B1::ib1
    cout << "[2] VB1::cb1 = ";
    cout << (char)(int)pVtab[2] << endl; //B1::cb1


    cout << "[3] VD::VB2::" << endl;
    for(int i=0; i<3; i++)
    {
        pFun = (Fun)pVtab[3][i];
        cout<<"     ["<<i<<"] ";
        pFun();
    }
    pFun = (Fun)pVtab[3][3];
    cout << "     [3] ";
    cout << pFun << endl;


    cout << "[4] VB2::ib2 = ";
    cout << (int)pVtab[4] <<endl; //B2::ib2
    cout << "[5] VB2::cb2 = ";
    cout << (char)(int)pVtab[5] << endl; //B2::cb2


    cout << "[6] VD::id = ";
    cout << (int)pVtab[6] << endl; //D::id
    cout << "[7] VD::cd = ";
    cout << (char)(int)pVtab[7] << endl;//D::cd


    cout << "[8] VD::VB::" << endl;
    for(int i=0; i<2; i++)
    {
        pFun = (Fun)pVtab[8][i];
        cout<<"     ["<<i<<"] ";
        pFun();
    }
    pFun = (Fun)pVtab[8][2];
    cout << "     [2] ";
    cout << pFun << endl;

    cout << "[9] VB::ib = ";
    cout << (int)pVtab[9] << endl; //B::ib
    cout << "[10] VB::cb = ";
    cout << (char)(int)pVtab[10] <<endl;//B::cb*/
    cout << "[11] = ";
    cout << pVtab[11] <<endl;
}

int main()
{
    testSingleDerived();
    cout<<endl<<"***********************************"<<endl<<endl;
    testMulDerived();
    cout<<endl<<"***********************************"<<endl<<endl;
    testDuplicatedDerived();
    cout<<endl<<"***********************************"<<endl<<endl;
    testSingleVirtualDerived();
    cout<<endl<<"***********************************"<<endl<<endl;
    testVirtualDerived();
    return 0;
}
