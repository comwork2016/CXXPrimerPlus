#include <stdio.h>
#include <winsock2.h>
#pragma comment (lib, "ws2_32.lib")  //���� ws2_32.dll

#define BUF_SIZE 100

int main()
{
    //��ʼ�� DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    //�����׽���
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    //���׽���
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���
    sockAddr.sin_family = PF_INET;  //ʹ��IPv4��ַ
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //�����IP��ַ
    sockAddr.sin_port = htons(1234);  //�˿�
    bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

    //�������״̬
    listen(servSock, 20);

    //���տͻ�������
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    while(true)
    {
        SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
        char buffer[BUF_SIZE];  //������
        int strLen = recv(clntSock, buffer, BUF_SIZE, 0);  //���տͻ��˷���������
        buffer[strLen] = '\0';
        printf("%s\n",buffer);
        //��ͻ��˷�������
        send(clntSock, buffer, strLen, NULL);
        //�ر��׽���
        closesocket(clntSock);
    }
    closesocket(servSock);

    //��ֹ DLL ��ʹ��
    WSACleanup();

    return 0;
}
