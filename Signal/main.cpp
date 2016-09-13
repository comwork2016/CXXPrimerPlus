#include <iostream>
#include <csignal>
#include <cstdlib>
#include <windows.h>

using namespace std;

void signalHandler( int signum )
{
    cout << "Interrupt signal (" << signum << ") received.\n";
    // �����ر�
    // ��ֹ����
	exit(signum);
}

int main ()
{
    //ע���ź� SIGINT ���źŴ������
    signal(SIGINT, signalHandler);

    int i=0;
    while(++i){
        cout << "Going to sleep...." << endl;
		if(i == 3)
        {
            raise(SIGINT);
        }
        Sleep(100);
    }

    return 0;
}
