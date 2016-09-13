#include <iostream>
#include <csignal>
#include <cstdlib>
#include <windows.h>

using namespace std;

void signalHandler( int signum )
{
    cout << "Interrupt signal (" << signum << ") received.\n";
    // 清理并关闭
    // 终止程序
	exit(signum);
}

int main ()
{
    //注册信号 SIGINT 和信号处理程序
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
