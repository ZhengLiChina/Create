#include <Winsock2.h>   
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#pragma comment(lib,"ws2_32.lib");

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
      
	hostent* mh= gethostbyname("pop.163.com");
    char** t=mh->h_addr_list;
    char * IPaddr=inet_ntoa(*((struct in_addr *)t[0]));
    SOCKADDR_IN addrSrv;   
    addrSrv.sin_addr.S_un.S_addr=inet_addr(IPaddr);//把U_LONG的主机字节顺序转换为TCP/IP网络字节顺序   
    addrSrv.sin_family=AF_INET;   
    addrSrv.sin_port=htons(110);   
  	std::cout<<IPaddr<<std::endl;
    //向服务器发送请求   

    int ret=connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));   
      

	char MSGBUF[501];

	int flag=recv(sockClient,MSGBUF,500,0); 
	std::cout<<"FLAG: "<<flag<<std::endl;
    MSGBUF[flag]='\0';

	std::cout<<MSGBUF<<endl;


    cout<<"USER"<<endl;
	flag=send(sockClient,"USER pop3testzl\r\n",strlen("USER pop3testzl\r\n"),0);
	// std::cout<<"FLAG: "<<flag<<std::endl;
	flag=recv(sockClient,MSGBUF,500,0); 
	std::cout<<"FLAG: "<<flag<<std::endl;
    MSGBUF[flag]='\0';
	std::cout<<MSGBUF<<endl;


	cout<<"PASS"<<endl;
	flag=send(sockClient,"PASS pop3test\r\n",strlen("USER pop3test\r\n"),0);
	// std::cout<<"FLAG: "<<flag<<std::endl;
	flag=recv(sockClient,MSGBUF,500,0); 
	std::cout<<"FLAG: "<<flag<<std::endl;
    MSGBUF[flag]='\0';
	std::cout<<MSGBUF<<endl;

    cout<<"STAT"<<endl;
    flag=send(sockClient,"STAT\r\n",strlen("STAT\r\n"),0);
    // std::cout<<"FLAG: "<<flag<<std::endl;
    flag=recv(sockClient,MSGBUF,500,0); 
    std::cout<<"FLAG: "<<flag<<std::endl;
    MSGBUF[flag]='\0';
    std::cout<<MSGBUF<<endl;

    cout<<"LIST"<<endl;
    flag=send(sockClient,"LIST\r\n",strlen("LIST\r\n"),0);
    // std::cout<<"FLAG: "<<flag<<std::endl;
    flag=recv(sockClient,MSGBUF,500,0); 
    std::cout<<"FLAG: "<<flag<<std::endl;
    MSGBUF[flag]='\0';
    std::cout<<MSGBUF<<endl;

    cout<<"UIDL 1"<<endl;
    flag=send(sockClient,"UIDL 1\r\n",strlen("UIDL 1\r\n"),0);
    // std::cout<<"FLAG: "<<flag<<std::endl;
    flag=recv(sockClient,MSGBUF,500,0); 
    std::cout<<"FLAG: "<<flag<<std::endl;
    MSGBUF[flag]='\0';
    std::cout<<MSGBUF<<endl;

    char message[5001];
    cout<<"RETR 3"<<endl;
    flag=send(sockClient,"RETR 3\r\n",strlen("RETR 3\r\n"),0);
    // std::cout<<"FLAG: "<<flag<<std::endl;
    flag=recv(sockClient,message,5000,0); 
    std::cout<<"FLAG: "<<flag<<std::endl;
    message[flag]='\0';
    std::cout<<message<<endl;

    flag=recv(sockClient,message,5000,0); 
    std::cout<<"FLAG: "<<flag<<std::endl;
    message[flag]='\0';
    std::cout<<message<<endl<<endl;

    closesocket(sockClient);   
    WSACleanup();   
    std::cin>>flag;
}  