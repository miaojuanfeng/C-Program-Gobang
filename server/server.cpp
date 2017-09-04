#include <Winsock2.h> 
#include <stdio.h> 
#include<iostream>

#define msglinein 1
#define msgconnected 2
#define msgchess 3
#define msgchating 4
#define msglineout 5
#define msgstart 6
#define msgrestart 7
#define msgback 8
#define msgcolor 9
#define msgserver 10
#define msgyestoback 11
#define msgnotoback 12
#define msgyestorestart 13
#define msgnotorestart 14
#define msgchangecolor 15
#define msgyeschangecolor 16
#define msgnochangecolor 17
#define msgchangerule 18
#define msgyeschangerule 19
#define msgnochangerule 20
#define msgblackwin 21
#define msgwhitewin 22
#define msgjinshou 23

using namespace std;

struct chess
{
   int pox;
   int poy;
};

struct Msg
{
   int type;
   char position[20];
   char chat[500];
   char server[100];
   int pox;
   int poy;
   int color;
   int rule;
}sendmessage,revmessage;

struct cli
{
   int ip;
   int port;
}client1,client2;

SOCKADDR_IN addrClient,addrSrv; 
int len=sizeof(SOCKADDR); 
SOCKET sockSrv;
SOCKADDR_IN resend;
int color=1,rule=1,count=0,sendtrue=1,sendornot=0,sender=0;
char information[500];


DWORD  WINAPI  AnswerThread2(LPVOID  lparam) 
{
     while(1)
	 {
      recvfrom(sockSrv,(char *)&revmessage,sizeof(Msg),0,(SOCKADDR*)&addrClient,&len);                 
          if(client1.ip==ntohl(addrClient.sin_addr.S_un.S_addr)&&client1.port==ntohs(addrClient.sin_port))
		   {    
			     resend.sin_addr.S_un.S_addr=htonl(client2.ip); 
				 resend.sin_family=AF_INET; 
				 resend.sin_port=htons(client2.port); 
		   }
		   else if(client2.ip==ntohl(addrClient.sin_addr.S_un.S_addr)&&client2.port==ntohs(addrClient.sin_port))
		   {
		         resend.sin_addr.S_un.S_addr=htonl(client1.ip); 
				 resend.sin_family=AF_INET; 
				 resend.sin_port=htons(client1.port); 
		   }
	      
  
		  switch(revmessage.type)
		  {
           case msglinein:
                        if(client1.ip !=ntohl(addrClient.sin_addr.S_un.S_addr)
						  ||client2.ip !=ntohl(addrClient.sin_addr.S_un.S_addr)
						  ||client1.port != ntohs(addrClient.sin_port)
						  ||client2.port !=ntohs(addrClient.sin_port))
						{        
							  if(client1.ip==0)
							  {
											client1.ip= ntohl(addrClient.sin_addr.S_un.S_addr);
											client1.port = ntohs(addrClient.sin_port);
							  }
							  else if(client2.ip==0)
							  {
											client2.ip= ntohl(addrClient.sin_addr.S_un.S_addr);
											client2.port = ntohs(addrClient.sin_port);
							  }
						}
			/*	printf("%d\n",client1.ip);
				printf("%d\n",client1.port);
				printf("%d\n",client2.ip);
				printf("%d\n",client2.port);*/

						printf("\t有客户端连接\n");
						in_addr temp;
						temp.S_un.S_addr = addrClient.sin_addr.S_un.S_addr;
						cout<<"\tIP地址："<<inet_ntoa(temp)<<endl;
						cout<<"\t端口："<<addrClient.sin_port<<endl;
						cout<<endl;

						count++;

						if(client2.ip!=0 && client2.port !=0)
						{
                        sendmessage.color=color;
						sendmessage.rule =rule;
						sprintf(sendmessage.server,"与服务器连接成功!\n当前共有%d个玩家\n玩家执黑，请落子。",count);
						   resend.sin_addr.S_un.S_addr=htonl(client1.ip); 
				           resend.sin_family=AF_INET; 
				           resend.sin_port=htons(client1.port);
						  sendmessage.type =msgconnected;
                          sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
                          Sleep(100);
						    if(color==1)
							  color=2;
						    else if(color==2)
							  color=1;
						  sendmessage.color=color;
						  sendmessage.rule =rule;
						  sprintf(sendmessage.server,"与服务器连接成功!\n当前共有%d个玩家\n玩家执白，等待对方落子...",count);
					      sendmessage.type =msgconnected;
					      sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&addrClient,len);
						}
						else if(client2.ip ==0 && client2.port ==0)
						{
						   sendmessage.color=0;
						   sendmessage.rule =0;
						   sprintf(sendmessage.server,"与服务器连接成功!\n当前共有%d个玩家\n等待其他玩家连接...",count);
						   sendmessage.type =msgconnected;
					       sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&addrClient,len);
						} 
					break;
			 case msgchating:
				    sprintf(sendmessage.chat,"%s 说 : %s",inet_ntoa(addrClient.sin_addr),revmessage.chat);
					printf("%s\n",sendmessage.chat);
					sendmessage.type=msgchating;
					
					sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);		

					break;
			 case msgchess:
				    sendmessage.type = msgchess;
					sendmessage.pox = revmessage.pox ;
					sendmessage.poy = revmessage.poy ;
					sprintf(information,"%s 落子: (%d,%d)",inet_ntoa(addrClient.sin_addr),revmessage.pox,revmessage.poy);
					printf("%s\n",information);
					sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
					break;
			 case msgback:
				     sendmessage.type=revmessage.type;
					 sprintf(information,"%s 请求悔棋，等待对方确认",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
					 break;
			 case msgyestoback:
				     sendmessage.type=revmessage.type;
					 sprintf(information,"%s 同意悔棋",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
					 break;
			 case msgnotoback:
				     sendmessage.type=revmessage.type;
					 sprintf(information,"%s 不同意悔棋",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
					 break;
			 case msgrestart:
				     sendmessage.type=revmessage.type;
					 sprintf(information,"%s 请求重新开始，等待对方确认...",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
					 break;
			 case msgyestorestart:
				     sendmessage.type=revmessage.type;
					 sprintf(information,"%s 同意重新开始",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
					 break;
			 case msgnotorestart:
				     sendmessage.type=revmessage.type;
					 sprintf(information,"%s 不同意重新开始",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
					 break;
			 case msgchangerule:
				     sendmessage.type =revmessage.type;
					 sendmessage.rule =revmessage.rule;
					 sprintf(information,"%s 请求改变规则，等待对方确认...",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
					 break;
			case msgyeschangerule:
				     sendmessage.type =revmessage.type;
					 sprintf(information,"%s 同意改变规则",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
				     break;
			case msgnochangerule:
				     sendmessage.type =revmessage.type;
					 sprintf(information,"%s 不同意改变规则",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
				     break;
			case msgchangecolor:
				     sendmessage.type =revmessage.type;
					 sprintf(information,"%s 请求换色，等待对方确认...",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
				     break;
            case msgyeschangecolor:
				     sendmessage.type =revmessage.type;
					 sprintf(information,"%s 同意换色",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
				     break;
			case msgnochangecolor:
				     sendmessage.type =revmessage.type;
					 sprintf(information,"%s 不同意换色",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
				     break;
			case msglineout:
				        printf("\t有客户端离线\n");
						temp.S_un.S_addr = addrClient.sin_addr.S_un.S_addr;
						cout<<"\tIP地址："<<inet_ntoa(temp)<<endl;
						cout<<"\t端口："<<addrClient.sin_port<<endl;
						cout<<endl;
                        count--;
						if(client1.ip==ntohl(addrClient.sin_addr.S_un.S_addr)
						 &&client1.port == ntohs(addrClient.sin_port))
						{
						    client1.ip =0;
							client1.port =0;
							sendmessage.type =msglineout;
							sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
						}
						else if(client2.ip==ntohl(addrClient.sin_addr.S_un.S_addr)
						 &&client2.port == ntohs(addrClient.sin_port))
						{
						    client2.ip =0;
							client2.port =0;
							sendmessage.type =msglineout;
							sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
						}
						break;
			case msgblackwin:
				     sendmessage.type =revmessage.type;
					 sprintf(information,"%s 赢了",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
				     break;
			case msgwhitewin:
				     sendmessage.type =revmessage.type;
					 sprintf(information,"%s 赢了",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
				     break;
			case msgjinshou:
				     sendmessage.type =revmessage.type;
					 sprintf(information,"%s 玩家禁手",inet_ntoa(addrClient.sin_addr));
					 printf("%s\n",information);
					 sendto(sockSrv,(char *)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&resend,len);
				     break;
		  }
	 }
}

void main() 
{ 
WORD wVersionRequested; 
WSADATA wsaData; 
int err; 

wVersionRequested = MAKEWORD( 1, 1 ); 

err = WSAStartup( wVersionRequested, &wsaData ); 
if ( err != 0 ) { 
	printf("套接字Socket 载入出错。服务器将关闭\n按任意键继续...\n");
	getchar();
   return; 
} 
printf("套接字Socket 载入正确...\n");
if ( LOBYTE( wsaData.wVersion ) != 1 || 
         HIBYTE( wsaData.wVersion ) != 1 ) { 
    printf("套接字Socket 版本错误(非1.1)。服务器将关闭\n按任意键继续...\n");
	getchar();
   WSACleanup( ); 
   return; 
} 
printf("套接字Socket 版本正确(1.1)\n服务器正常工作\n");

sockSrv=socket(AF_INET,SOCK_DGRAM,0); 

addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY); 
addrSrv.sin_family=AF_INET; 
addrSrv.sin_port=htons(65500); 
bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR)); 
len=sizeof(SOCKADDR);

client1.ip =0;
client1.port =0;
client2.ip =0;
client2.port =0;

                       DWORD  dwThreadId;  
                       HANDLE  hThread;  
                     
					   hThread=CreateThread(NULL,NULL,AnswerThread2,  
                                   (LPVOID)sockSrv,0,&dwThreadId);
					   getchar();                                           //主进程暂停
closesocket(sockSrv); 
WSACleanup(); 
} 
