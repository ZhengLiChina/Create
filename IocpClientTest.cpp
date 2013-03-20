#include <Winsock2.h>   
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#pragma comment(lib,"ws2_32.lib")


int main()   
{   
  //加载套接字   
	WORD wVersionRequested;   
	WSADATA wsaData;   
	int err;   

	wVersionRequested=MAKEWORD(2,2);   

	err=WSAStartup(wVersionRequested,&wsaData);   
	if (err!=0)   
	{   
		return 0;   
	}   

	if (LOBYTE(wsaData.wVersion)!=2||   
		HIBYTE(wsaData.wVersion)!=2)   
	{   
		WSACleanup();   
		return 0;   
	}   



	//创建套接字   
	SOCKET sockClient=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);   
	// int dwError = WSAGetLastError();
	// std::cout<<dwError<<std::endl;
	// if (dwError != 0) {
	//     if (dwError == WSAHOST_NOT_FOUND) {
	//         printf("Host not found\n");
	//         return 0;
	//     } else if (dwError == WSANO_DATA) {
	//         printf("No data record found\n");
	//         return 0;
	//     } else {
	//         printf("Function failed with error: %ld\n", dwError);
	//         return 0;
	//     }
	// }


	SOCKADDR_IN addrSrv;   
	addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");//把U_LONG的主机字节顺序转换为TCP/IP网络字节顺序   
	addrSrv.sin_family=AF_INET;   
	addrSrv.sin_port=htons(6000);   
	//向服务器发送请求   

	int ret=connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));   



	//int flag=recv(sockClient,MSGBUF,500,0); 
	//std::cout<<"FLAG: "<<flag<<std::endl;
	//   MSGBUF[flag]='\0';

	//std::cout<<MSGBUF<<endl;
	char MSGBUF[501];
	char INBUFF[200];
	cin>>INBUFF;
	send(sockClient,INBUFF,strlen(INBUFF),0);
	while (true)
	{
		if (INBUFF[0]=='q')
		{
			break;
		}
		int flag=recv(sockClient,MSGBUF,500,0); 
		MSGBUF[flag]='\0';
		std::cout<<MSGBUF<<endl;
	}

	while (true)
	{
		cin>>INBUFF;
		send(sockClient,INBUFF,strlen(INBUFF),0);
	}


	closesocket(sockClient);   
	WSACleanup();   
	cin.get();
	cin.get();

}  
