#include<windows.h>
#include <wingdi.h>                  //what is this?
#include<stdio.h>
#pragma  comment(lib,"winmm.lib")
#pragma  comment(lib,"ws2_32.lib")
#include "source.h"
#include "load.h"
#include "function.h"	
#include "sound.h"
#include "socket.h"
#include "win.h"
#include "TransparentBlt2.h"


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	HWND hwnd;
	MSG  msg;
    WNDCLASS win;
    
    load(hInstance);

	win.cbClsExtra =0;
	win.cbWndExtra =0;
	win.hbrBackground =(HBRUSH)GetStockObject(WHITE_BRUSH);
	win.hCursor =hcursor[0];
	win.hIcon =LoadIcon(hInstance,"ID_ICO");
	win.hInstance =hInstance;
	win.lpfnWndProc =Winpro;
	win.lpszClassName ="Window";
	win.lpszMenuName=NULL;
	win.style=CS_HREDRAW|CS_VREDRAW;
	RegisterClass(&win);

	hwnd=CreateWindow("Window","Windows SDK 五子棋(作者：缪隽峰)",WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU  | WS_MINIMIZEBOX,
		                                  100,100,1051,600,NULL,hMenu[0],hInstance,NULL);
	ShowWindow(hwnd,nShowCmd);
	UpdateWindow(hwnd);
    
	while(GetMessage(&msg,NULL,0,0))
	{
	   TranslateMessage(&msg);
	   DispatchMessage(&msg);
	}
	return msg.lParam;
}

LRESULT CALLBACK Winpro(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)
{
    x=LOWORD(lParam);
	y=HIWORD(lParam);
    Hwnd=hWnd;

   switch(Msg)
	{
   case WM_CREATE:
	             hedit[0]=CreateWindow("edit","",WS_CHILD | WS_VISIBLE 
					                          | WS_VSCROLL | WS_BORDER 
											  | ES_LEFT | ES_MULTILINE 
											  | ES_AUTOVSCROLL,
											  753,50,290,300,
											  hWnd,(HMENU)1,hinstance,NULL);
				 hstatic=CreateWindow("static","请输入服务器IP地址：",WS_CHILD | WS_VISIBLE,
					                                  753,350,290,60,
													  hWnd,(HMENU)2,hinstance,NULL);
				 hedit[1]=CreateWindow("edit","",WS_CHILD | WS_VISIBLE 
					                          | WS_VSCROLL | WS_BORDER 
											  | ES_LEFT | ES_MULTILINE 
											  | ES_AUTOVSCROLL,
											  753,410,290,90,
											  hWnd,(HMENU)3,hinstance,NULL);
				 hedit[2]=CreateWindow("edit","",WS_CHILD | WS_VISIBLE 
					                          | WS_BORDER | ES_LEFT, 
											  753,365,273,20,
											  hWnd,(HMENU)4,hinstance,NULL);
                 hcommand=CreateWindow("button","连接",WS_CHILD | WS_VISIBLE 
					                          | WS_BORDER | ES_LEFT, 
											  945,387,73,20,
											  hWnd,(HMENU)5,hinstance,NULL);
                 SetFocus(hedit[2]);

                 SetTimer(hWnd,TIMERBIRD,500,NULL);
				 play=true;
				 switchsong=1;
                 hsound=CreateThread(NULL,NULL,sound,0,0,&Id);

                           static  NOTIFYICONDATA icondata;
						   icondata.cbSize =sizeof(NOTIFYICONDATA);
						   icondata.hIcon=LoadIcon((HINSTANCE)GetWindowLong(hWnd,GWL_HINSTANCE),"ID_ICO");
						   icondata.hWnd =hWnd;
						   strcpy(icondata.szTip,"Windows SDK 五子棋(作者：缪隽峰)");
						   icondata.uCallbackMessage = WM_ICON;
						   icondata.uFlags=NIF_MESSAGE|NIF_ICON|NIF_TIP;
						   icondata.uID = 10;
						   Shell_NotifyIcon(NIM_ADD,&icondata);		   
	             break;
   case WM_TIMER:
	   switch(wParam)
	   {
	   case TIMERBIRD:
		                GetClientRect(hWnd,&rc2);
						  rc2.top=0;
						  rc2.bottom=63;
					    	rc2.left=birdx;
					    	rc2.right=birdx+68;

						hdc3=GetDC(hWnd);
                        mdc3=CreateCompatibleDC(hdc3);
						SelectObject(mdc3,hbird[bird]);
						TransparentBlt2(hdc3,birdx,0,68,63,mdc3,0,0,68,63,RGB(255,255,255));
						DeleteObject(mdc3);
                        DeleteDC(hdc3);
						if(bird==0)
							bird=1;
						else
							bird=0;

						birdx+=6;
						if(birdx>=1042)
							birdx=-65;
						SetTimer(hWnd,TIMERBIRDKILL,500,NULL);
		                break;	
						
	   case TIMERBIRDKILL:
						InvalidateRect(hWnd,&rc2,true);
						KillTimer(hWnd,TIMERBIRDKILL);
		                break;
	   case TIMERWAITE:
                        GetClientRect(hWnd,&rc3);
						rc3.top=256;
						rc3.bottom=256+32;
					    rc3.left=380;
					    rc3.right=380+129;

						hdc3=GetDC(hWnd);
                        mdc3=CreateCompatibleDC(hdc3);
						SelectObject(mdc3,hwaite[waite]);
						TransparentBlt2(hdc3,380,256,129,32,mdc3,0,0,129,32,RGB(255,255,255));
						
						DeleteObject(mdc3);
                        DeleteDC(hdc3);

						waite++;
						if(waite==4)
							waite=0;
                        SetTimer(hWnd,TIMERWAITEKILL,500,NULL);
				        break;
	   case TIMERWAITEKILL:
		                InvalidateRect(hWnd,&rc3,true);
						KillTimer(hWnd,TIMERWAITEKILL);
						break;
	   case TIMERRABBIT:
		                    GetClientRect(hWnd,&rc4);
							rc4.top=150;
							rc4.bottom=150+96;
							rc4.left=620;
							rc4.right=620+96;

							hdc3=GetDC(hWnd);
							mdc3=CreateCompatibleDC(hdc3);

						if(rabbitnum<15)
						{	
							SelectObject(mdc3,hrabbit[rabbit]);
							TransparentBlt2(hdc3,620,150,96,96,mdc3,0,0,96,96,RGB(238,242,251));
							
							rabbit++;
							if(rabbit==15)
								rabbit=0;
							SetTimer(hWnd,TIMERRABBITKILL,100,NULL);

							rabbitnum++;
						}
						else if(15<=rabbitnum&&rabbitnum<25)
						{
							rabbitnum++;
                            SelectObject(mdc3,hrabbit[0]);
							TransparentBlt2(hdc3,620,150,96,96,mdc3,0,0,96,96,RGB(238,242,251));
						}
						else if(rabbitnum>=25)
						{    
							rabbitnum=0;
						}

						    DeleteObject(mdc3);
							DeleteDC(hdc3);
						break;
	   case TIMERRABBITKILL:
		                InvalidateRect(hWnd,&rc4,true);
						KillTimer(hWnd,TIMERRABBITKILL);
						break;
       case TIMERDOG:
                            GetClientRect(hWnd,&rc5);
							rc5.top=280;
							rc5.bottom=295;
							rc5.left=655;
							rc5.right=680;

							hdc3=GetDC(hWnd);
							mdc3=CreateCompatibleDC(hdc3);

						if(dognum<3)
						{	
							SelectObject(mdc3,hdog[dog]);
							TransparentBlt2(hdc3,640,255,73,94,mdc3,0,0,73,94,RGB(238,242,251));
							
							dog++;
							if(dog==2)
								dog=0;
							SetTimer(hWnd,TIMERDOGKILL,100,NULL);

							dognum++;
						}
						else if(3<=dognum&&dognum<5)
						{
							dognum++;
                            SelectObject(mdc3,hdog[0]);
							TransparentBlt2(hdc3,640,255,73,94,mdc3,0,0,73,94,RGB(238,242,251));
						}
						else if(dognum>=5)
						{    
							dognum=0;
						}

						    DeleteObject(mdc3);
							DeleteDC(hdc3);
		                break;
	   case TIMERDOGKILL:
                        InvalidateRect(hWnd,&rc5,true);
						KillTimer(hWnd,TIMERDOGKILL); 
		                break;
	   case TIMERKISS:
		                GetClientRect(hWnd,&rc6);
							rc6.top=355;
							rc6.bottom=355+107;
							rc6.left=630;
							rc6.right=630+88;

							hdc3=GetDC(hWnd);
							mdc3=CreateCompatibleDC(hdc3);

						if(kissnum<5)
						{	
							SelectObject(mdc3,hkiss[kiss]);
							TransparentBlt2(hdc3,630,355,88,107,mdc3,0,0,88,107,RGB(255,255,255));
							
							kiss++;
							if(kiss==5)
								kiss=0;
							SetTimer(hWnd,TIMERKISSKILL,300,NULL);

							kissnum++;
						}
						else if(5<=kissnum&&kissnum<7)
						{
							kissnum++;
                            SelectObject(mdc3,hkiss[4]);
							TransparentBlt2(hdc3,630,355,88,107,mdc3,0,0,88,107,RGB(255,255,255));
						}
						else if(kissnum>=7)
						{    
							kissnum=0;
							kiss=0;
							SetTimer(hWnd,TIMERKISSKILL,300,NULL);
						}

						    DeleteObject(mdc3);
							DeleteDC(hdc3);
							break;
		case TIMERKISSKILL:
			            InvalidateRect(hWnd,&rc6,true);
						KillTimer(hWnd,TIMERKISSKILL); 
		                break;
		case TIMERHAND:
		                GetClientRect(hWnd,&rc7);
							rc7.top=445;
							rc7.bottom=445+107;
							rc7.left=635;
							rc7.right=635+88;

							hdc3=GetDC(hWnd);
							mdc3=CreateCompatibleDC(hdc3);

						if(handnum<4)
						{	
							SelectObject(mdc3,hhand[hand]);
							TransparentBlt2(hdc3,635,445,88,107,mdc3,0,0,97,111,RGB(255,255,255));
							
							hand++;
							if(hand==2)
								hand=0;
							SetTimer(hWnd,TIMERHANDKILL,300,NULL);

							handnum++;
						}
						else if(4<=handnum&&handnum<6)
						{
							handnum++;
                            SelectObject(mdc3,hhand[0]);
							TransparentBlt2(hdc3,635,445,88,107,mdc3,0,0,97,111,RGB(255,255,255));
						}
						else if(handnum>=6)
						{    
							handnum=0;
							hand=0;
							SetTimer(hWnd,TIMERHANDKILL,300,NULL);
						}

						    DeleteObject(mdc3);
							DeleteDC(hdc3);
							break;
		case TIMERHANDKILL:
			            InvalidateRect(hWnd,&rc7,true);
						KillTimer(hWnd,TIMERHANDKILL); 
		                break;
	   }break;
   case WM_PAINT:
	                     if(paint)
						 {     hdc=GetDC(hWnd);
								mdc=CreateCompatibleDC(hdc);
								SelectObject(mdc,hbitmap[3]);
								BitBlt(hdc,0,0,1043,547,mdc,0,0,SRCCOPY);
								DeleteObject(mdc);
								DeleteDC(hdc);
								Sleep(5000);
								paint=false;
						 }

	                    hdc=BeginPaint(hWnd,&ps);
                        mdc=CreateCompatibleDC(hdc);
						SelectObject(mdc,hbitmap[0]);
						BitBlt(hdc,0,0,1043,547,mdc,0,0,SRCCOPY);
						SelectObject(mdc,hbitmapsend[0]);
						BitBlt(hdc,960,503,40,40,mdc,0,0,SRCCOPY);
						    SelectObject(mdc,hrabbit[0]);
							TransparentBlt2(hdc,620,150,96,96,mdc,0,0,96,96,RGB(238,242,251));
							SelectObject(mdc,hdog[0]);
							TransparentBlt2(hdc,640,255,73,94,mdc,0,0,73,94,RGB(238,242,251));
							SelectObject(mdc,hkiss[0]);
							TransparentBlt2(hdc,630,355,88,107,mdc,0,0,88,107,RGB(255,255,255));
                          
							 if(destroy)
							 {
								 DestroyWindow(hedit[2]);
					             DestroyWindow(hcommand);
								 destroy=0;
							 }

							if(shownum==1)
							{
								SelectObject(mdc,hhand[0]);
								TransparentBlt2(hdc,635,445,88,107,mdc,0,0,97,111,RGB(255,255,255));
							}
                        for(i=0;i<15;i++)
							for(j=0;j<15;j++)
							{
								if(Chess[i][j]==black)
								{
									 SelectObject(mdc,hbitmap[1]);
                                     TransparentBlt2(hdc,posi[i][j].x-12,posi[i][j].y-12,24,24,mdc,0,0,24,24,RGB(255,0,255));
								}
								else if(Chess[i][j]==white)
								{
								     SelectObject(mdc,hbitmap[2]);
									 TransparentBlt2(hdc,posi[i][j].x-12,posi[i][j].y-12,24,24,mdc,0,0,24,24,RGB(255,0,255));
								}
							} 
                        if(winpic!=NONE)
						{
						    SelectObject(mdc,hwin[winpic]);
						    TransparentBlt2(hdc,360,220,100,100,mdc,0,0,100,100,RGB(255,255,255));
						}
                        if(imformation!=NONE)
						{
						    SelectObject(mdc,himformation[imformation]);
							TransparentBlt2(hdc,212,70,400,400,mdc,0,0,400,400,RGB(255,255,255));
						}
						DeleteObject(mdc);
						EndPaint(hWnd,&ps);				 
						break;
   case WM_MOUSEMOVE:
	                    hdc4=GetDC(hWnd);
						mdc4=CreateCompatibleDC(hdc4);
						if(960<x&&x<1000&&503<y&&y<543)                    //send
                        {
							if(sendmove==1)
							{
							 SelectObject(mdc4,hbitmapsend[1]);
							 BitBlt(hdc4,960,503,40,40,mdc4,0,0,SRCCOPY);
 
							  SelectObject(mdc4,hcom[4]);
							  TransparentBlt2(hdc4,900,510,110,30,mdc4,0,0,110,30,RGB(255,255,255));

							  sendmove=0;
							}
						}
						else
						{
							if(sendmove==0)
							{
							SelectObject(mdc4,hbitmapsend[0]);
							BitBlt(hdc4,960,503,40,40,mdc4,0,0,SRCCOPY);

							   GetClientRect(hWnd, &rccom);
                               rccom.left=900;
							   rccom.right=900+110;
							   rccom.top=510;
							   rccom.bottom=510+30;
                               InvalidateRect(hWnd,&rccom,true);

							   sendmove=1;
							}
						}
                        
                        if((630<x&&x<700&&155<y&&y<245)||(635<x&&x<700&&255<y&&y<348)||(635<x&&x<712&&380<y&&y<460)||(635<x&&x<715&&478<y&&y<545))//635,445,88,107
						{
                           SetClassLong(hWnd,GCL_HCURSOR,NULL);
						    SetCursor(hcursor[3]);
						}
						else
						{
							 SetClassLong(hWnd,GCL_HCURSOR,(long)hcursor[0]);
						     SetCursor(hcursor[0]);
						}

						if(630<x&&x<700&&155<y&&y<245)                     //rabbit
						{
							if(rabbitmove==0)
							{
							 SetTimer(hWnd,TIMERRABBIT,100,NULL);
							 rabbitmove=1;

							   SelectObject(mdc4,hcom[0]);
							   TransparentBlt2(hdc4,720,180,110,30,mdc4,0,0,110,30,RGB(255,255,255));

            	             mciSendString("PLAY notify",NULL,NULL,NULL);
							}
						}
						else 
						{
							if(rabbitmove==1)
							{
							   mciSendString("CLOSE notify",NULL,NULL,NULL);
							   KillTimer(hWnd,TIMERRABBIT);
							   SelectObject(mdc4,hrabbit[0]);
							   TransparentBlt2(hdc4,620,150,96,96,mdc4,0,0,96,96,RGB(238,242,251));
							   rabbit=0;
							   rabbitnum=0;

							   rabbitmove=0;
                               
							   GetClientRect(hWnd, &rccom);
                               rccom.left=720;
							   rccom.right=720+110;
							   rccom.top=180;
							   rccom.bottom=180+30;
                               InvalidateRect(hWnd,&rccom,true);

							   mciSendString("OPEN Sound\\notify.wav alias notify",NULL,NULL,NULL);
							}
						}
						if(635<x&&x<700&&255<y&&y<348)                    //dog
						{
							if(dogmove==0)
							{
                            SetTimer(hWnd,TIMERDOG,100,NULL);
							dogmove=1;

                              SelectObject(mdc4,hcom[1]);
							   TransparentBlt2(hdc4,720,290,110,30,mdc4,0,0,110,30,RGB(255,255,255));

							mciSendString("PLAY notify",NULL,NULL,NULL);
							}
						}
						else
						{
						  if(dogmove==1)
						  {
							  mciSendString("CLOSE notify",NULL,NULL,NULL);
						      KillTimer(hWnd,TIMERDOG);
							  SelectObject(mdc4,hdog[0]);
							  TransparentBlt2(hdc4,640,255,73,94,mdc4,0,0,73,94,RGB(238,242,251));
                              dog=0;
							  dognum=0;

							  dogmove=0;

                              GetClientRect(hWnd, &rccom);
                               rccom.left=720;
							   rccom.right=720+110;
							   rccom.top=290;
							   rccom.bottom=290+30;
                               InvalidateRect(hWnd,&rccom,true);

							  mciSendString("OPEN Sound\\notify.wav alias notify",NULL,NULL,NULL);
						  }
						}

						if(635<x&&x<712&&380<y&&y<460)
						{
							if(kissmove==0)
							{
						       SetTimer(hWnd,TIMERKISS,300,NULL);
                                kissmove=1;

                               SelectObject(mdc4,hcom[2]);
							   TransparentBlt2(hdc4,720,400,110,30,mdc4,0,0,110,30,RGB(255,255,255));

								mciSendString("PLAY notify",NULL,NULL,NULL);
							}
						}
						else
						{
						     if(kissmove==1)
							 {
								 mciSendString("CLOSE notify",NULL,NULL,NULL);
							    KillTimer(hWnd,TIMERKISS);
								SetTimer(hWnd,TIMERKISSKILL,10,NULL);
								SelectObject(mdc4,hkiss[0]);
							    TransparentBlt2(hdc4,630,355,88,107,mdc4,0,0,88,107,RGB(255,255,255));
                                kiss=0;
							    kissnum=0;

							    kissmove=0;

                               GetClientRect(hWnd, &rccom);
                               rccom.left=720;
							   rccom.right=720+110;
							   rccom.top=400;
							   rccom.bottom=400+30;
                               InvalidateRect(hWnd,&rccom,true);

								mciSendString("OPEN Sound\\notify.wav alias notify",NULL,NULL,NULL);
							 }
						}

						if(635<x&&x<715&&478<y&&y<545)
						{
						   if(handmove==0)
						   {
						       SetTimer(hWnd,TIMERHAND,300,NULL);
							   handmove=1;

							   SelectObject(mdc4,hcom[3]);
							   TransparentBlt2(hdc4,720,500,110,30,mdc4,0,0,110,30,RGB(255,255,255));

							   mciSendString("PLAY notify",NULL,NULL,NULL);
                      
							   shownum=0;
						   }
						}
						else
						{
						     if(handmove==1)
							 {
								 mciSendString("CLOSE notify",NULL,NULL,NULL);
							    KillTimer(hWnd,TIMERHAND);
								SelectObject(mdc4,hhand[0]);
							    TransparentBlt2(hdc4,635,445,88,107,mdc4,0,0,97,111,RGB(255,255,255));
                                hand=0;
							    handnum=0;

							    handmove=0;

                                GetClientRect(hWnd, &rccom);
                                rccom.left=720;
							    rccom.right=720+110;
							    rccom.top=500;
							    rccom.bottom=500+30;
                                InvalidateRect(hWnd,&rccom,true);

								mciSendString("OPEN Sound\\notify.wav alias notify",NULL,NULL,NULL);
							 }
							 shownum=1;
						}

						GetClientRect(hWnd,&rc);
	                //    wsprintf((LPSTR)a,"x=%d,y=%d",LOWORD(lParam),HIWORD(lParam));
					//	TextOut(hdc4,10,10,a,(int)strlen(a));
				        DeleteObject(mdc4);
						DeleteDC(hdc4);
						break;
    case WM_LBUTTONDOWN:
                      if(!Position(x,y,&pox,&poy))
						{
						      if(Chess[pox][poy]==NONE)
							  {
								hdc5=GetDC(hWnd);
								mdc5=(HDC)CreateCompatibleDC(hdc5);
								if(color==black)
								{
									if(order==black)
									{
										 Chess[pox][poy]=black;                 //1表示下黑子	
										 SelectObject(mdc5,hbitmap[1]);
										 TransparentBlt2(hdc5,posi[pox][poy].x-12,posi[pox][poy].y-12,24,24,mdc5,0,0,24,24,RGB(255,0,255));
										   sendmessage.type =msgchess;
										   sendmessage.pox =pox;
										   sendmessage.poy =poy;
										   sendornot=1;
										 order=white;
										 if(rule==1)
											 result=forbid2(pox,poy);
										 else if(rule==0)
											 result=Win();
										 SetTimer(hWnd,TIMERWAITE,500,NULL);

										 sprintf(staticcaption,"我方落子(%d,%d)\n请等待对方落子...",pox+1,poy+1);

										 Sleep(100);
										 switch(result)
										 {
										 case 1:
											 {
											   sendmessage.type =msgblackwin;
											   sendmessage.pox =pox;
										       sendmessage.poy =poy;
											   sendornot=1;
											   KillTimer(Hwnd,TIMERWAITE);
											         SelectObject(mdc5,hwin[0]);
							                         TransparentBlt2(hdc5,360,220,100,100,mdc5,0,0,100,100,RGB(255,255,255));
													 winpic=0;
												     order=0;
											 }break;
										 case 2:
											 {
											   sendmessage.type =msgwhitewin;
											   sendmessage.pox =pox;
										   sendmessage.poy =poy;
											  sendornot=1;
											   KillTimer(Hwnd,TIMERWAITE);
											         SelectObject(mdc5,hwin[1]);
							                         TransparentBlt2(hdc5,360,220,100,100,mdc5,0,0,100,100,RGB(255,255,255));
													 winpic=1;
												     order=0;
											 }break;
										 case 3:
											 {
											   sendmessage.type =msgjinshou;
											   sendmessage.pox =pox;
										   sendmessage.poy =poy;
											  sendornot=1;
											   KillTimer(Hwnd,TIMERWAITE);
                                                     SelectObject(mdc5,hwin[2]);
							                         TransparentBlt2(hdc5,360,220,100,100,mdc5,0,0,100,100,RGB(255,255,255));
													 winpic=2;
												     order=0;
											 }break;
										 default:
											 SetTimer(hWnd,TIMERWAITE,500,NULL);
										 }
										 if(result==1||result==2||result==3)
										 {
											 switchsong=3;
                                              play=true;
										 }
										 else
										 {
											 mciSendString("close downzi",NULL,NULL,NULL);
											 mciSendString("OPEN Sound\\downzi.wav alias downzi",NULL,NULL,NULL);
											 mciSendString("play downzi",NULL,NULL,NULL);
                                         }
										 if(result==1)
							                  sprintf(staticcaption,"恭喜恭喜，你赢了\n如果你觉得意犹未尽或胜之不武\n你可以再来一局");
										 else if(result==2)
                                              sprintf(staticcaption,"很遗憾，你输了\n如果你不服气\n可以再来一局");
										 else if(result==3)
										      sprintf(staticcaption,"很遗憾，你输了\n注意黑子禁手规则\n如果你不服气,可以再来一局");
										 SetWindowText(hstatic,staticcaption);
									}
								}
								else if(color==white)
								{
									if(order==white)
									{
										Chess[pox][poy]=white;                 //2表示下白子
										SelectObject(mdc5,hbitmap[2]);
										TransparentBlt2(hdc5,posi[pox][poy].x-12,posi[pox][poy].y-12,24,24,mdc5,0,0,24,24,RGB(255,0,255));
										   sendmessage.type =msgchess;
										   sendmessage.pox =pox;
										   sendmessage.poy =poy;
										   sendornot=1;
										order=black;
										SetTimer(hWnd,TIMERWAITE,500,NULL);
                                        
										sprintf(staticcaption,"我方落子(%d,%d)\n请等待对方落子...",pox+1,poy+1);

										Sleep(100);
										result=Win();
										      switch(result)
											  {
												 case 1:
													 {
													   sendmessage.type =msgblackwin;
													   sendmessage.pox =pox;
												   sendmessage.poy =poy;
													   sendornot=1;
													   KillTimer(Hwnd,TIMERWAITE);
															 SelectObject(mdc5,hwin[0]);
															 TransparentBlt2(hdc5,360,220,100,100,mdc5,0,0,100,100,RGB(255,255,255));
															 winpic=0;
															 order=0;
													 }break;
												 case 2:
													 {
													   sendmessage.type =msgwhitewin;
													   sendmessage.pox =pox;
												   sendmessage.poy =poy;
													   sendornot=1;
													   KillTimer(Hwnd,TIMERWAITE);
															 SelectObject(mdc5,hwin[1]);
															 TransparentBlt2(hdc5,360,220,100,100,mdc5,0,0,100,100,RGB(255,255,255));
															 winpic=1;
															 order=0;
													 }break;
												 case 3:
													 {
													   sendmessage.type =msgjinshou;
													   sendmessage.pox =pox;
												   sendmessage.poy =poy;
													   sendornot=1;
													   KillTimer(Hwnd,TIMERWAITE);
															 SelectObject(mdc5,hwin[2]);
															 TransparentBlt2(hdc5,360,220,100,100,mdc5,0,0,100,100,RGB(255,255,255));
															 winpic=2;
															 order=0;
													 }break;
												 default:
													 SetTimer(hWnd,TIMERWAITE,500,NULL);
											  }
													 if(result==1||result==2||result==3)
													 {
														  switchsong=3;
														  play=true;
													 }
													 else
													 {
														 mciSendString("close downzi",NULL,NULL,NULL);
														 mciSendString("OPEN Sound\\downzi.wav alias downzi",NULL,NULL,NULL);
														 mciSendString("play downzi",NULL,NULL,NULL);
													 }
														 if(result==2)
															   sprintf(staticcaption,"恭喜恭喜，你赢了\n如果你觉得意犹未尽或胜之不武\n你可以再来一局");
														 else if(result==1)
															   sprintf(staticcaption,"很遗憾，你输了\n如果你不服气\n可以再来一局");
														 else if(result==3)
															  sprintf(staticcaption,"恭喜恭喜，你赢了\n如果你觉得意犹未尽或胜之不武\n你可以再来一局");
														 SetWindowText(hstatic,staticcaption);
									}
								}
                                DeleteObject(mdc5);
								DeleteDC(hdc5);
								TurnBackRecord(pox,poy);
							  }
						}
					  else if(960<x&&x<1000&&503<y&&y<543)
					  {
					       hdc5=GetDC(hWnd);
						   mdc5=CreateCompatibleDC(hdc5);
                           SelectObject(mdc5,hbitmapsend[2]);
						   BitBlt(hdc5,960,503,40,40,mdc5,0,0,SRCCOPY);
						   DeleteObject(mdc5);
						   DeleteDC(hdc5);

						   sendmessage.type =msgchating;
						   GetWindowText(hedit[1],sendmessage.chat,sizeof(sendmessage.chat));
						   sendornot=1;
                           
						   char n[500];
						   SetWindowText(hedit[1],"");
						   sprintf(n,"我 说 ：%s",sendmessage.chat);
						   SetWindowText(hedit[0],n);
						   SetFocus(hedit[1]);
					  }
	                  else if(630<x&&x<700&&155<y&&y<245)
					  {
					     //restart
						  mciSendString("close notify",NULL,NULL,NULL);
                          mciSendString("close click",NULL,NULL,NULL);
						  mciSendString("OPEN Sound\\click.wav alias click",NULL,NULL,NULL);
						  mciSendString("play click",NULL,NULL,NULL);
						  SendMessage(hWnd,WM_COMMAND,IDM_RESTART,lParam);
					  }
					  else if(635<x&&x<700&&255<y&&y<348)
					  {
					     //back
						  mciSendString("close notify",NULL,NULL,NULL);
                          mciSendString("close click",NULL,NULL,NULL);
						  mciSendString("OPEN Sound\\click.wav alias click",NULL,NULL,NULL);
						  mciSendString("play click",NULL,NULL,NULL);
						  SendMessage(hWnd,WM_COMMAND,IDM_TURNBACK,lParam);
					  }
					  else if(635<x&&x<712&&380<y&&y<460)
					  {
					    //changgecolor
						  mciSendString("close notify",NULL,NULL,NULL);
                          mciSendString("close click",NULL,NULL,NULL);
						  mciSendString("OPEN Sound\\click.wav alias click",NULL,NULL,NULL);
						  mciSendString("play click",NULL,NULL,NULL);
						  SendMessage(hWnd,WM_COMMAND,IDM_HUANSE,lParam);
					  }
					  else if(635<x&&x<715&&478<y&&y<545)
					  {
					    //exit
						  SendMessage(hWnd,WM_DESTROY,wParam,lParam);
					  }

                        SetClassLong(hWnd,GCL_HCURSOR,NULL);
						SetCursor(hcursor[1]);
						
						break;
	case WM_LBUTTONUP:
                      if(960<x&&x<1000&&503<y&&y<543)
					  {
					       hdc5=GetDC(hWnd);
						   mdc5=CreateCompatibleDC(hdc5);
                           SelectObject(mdc5,hbitmapsend[1]);
						   BitBlt(hdc5,960,503,40,40,mdc5,0,0,SRCCOPY);
						   DeleteObject(mdc5);
						   DeleteDC(hdc5);
					  }

		                SetClassLong(hWnd,GCL_HCURSOR,(long)hcursor[0]);
						SetCursor(hcursor[0]);
						break;
	case WM_RBUTTONDOWN:
		                SetClassLong(hWnd,GCL_HCURSOR,NULL);
						SetCursor(hcursor[2]);
						break;
	case WM_RBUTTONUP:
		                POINT point;
		                GetCursorPos(&point);
		                hmenu[0]=GetSubMenu(hMenu[0],0);
		                TrackPopupMenu(hmenu[0],TPM_LEFTALIGN,point.x,point.y,0,(HWND)hWnd,NULL);

                        SetClassLong(hWnd,GCL_HCURSOR,(long)hcursor[0]);
						SetCursor(hcursor[0]);
						break;
	case WM_COMMAND:
		               switch(LOWORD(wParam))
					   {
					   case 5:
						   GetWindowText(hedit[2],ip,20);
						   sprintf(staticcaption,"正在连接服务器...");
						   SetWindowText(hstatic,staticcaption);
						   sendmessage.type=msglinein;
						   sock();
						   break;
					   case IDM_RESTART:
                           sendmessage.type=msgrestart;
						   sendornot=1;
						   sprintf(staticcaption,"'重新开始'请求已发送,\n请等待对方确认...");
						   SetWindowText(hstatic,staticcaption);
                           break;
					   case IDM_TURNBACK:
						         sendmessage.type=msgback;
								 sendornot=1;
						   sprintf(staticcaption,"'悔棋'请求已发送,\n请等待对方确认...");
						   SetWindowText(hstatic,staticcaption);
						   break;
					   case IDM_HEIZIJINSHOU:
						    if(IDYES==MessageBox(NULL,"改变游戏规则将重新开始游戏，\n确定更改吗？","改变游戏规则",MB_YESNO))
							{
							    sendmessage.type =msgchangerule;
								if(rule==1)
									 sendmessage.rule =0;
								else if(rule==0)
									 sendmessage.rule =1;
								sendornot=1;
							sprintf(staticcaption,"'改变游戏规则'请求已发送,\n请等待对方确认...");
						   SetWindowText(hstatic,staticcaption);
							} 
							break;
					   case IDM_HUANSE:
						    if(IDYES==MessageBox(NULL,"换色将重新开始游戏，\n确定换色吗？","换色",MB_YESNO))
							{
							    sendmessage.type =msgchangecolor;
								sendornot=1;
								sprintf(staticcaption,"'换色'请求已发送,\n请等待对方确认...");
						        SetWindowText(hstatic,staticcaption);
							} 
							break;
					   case ABOUTFIVECHESS:
					        Openannet=FindWindowEx(NULL,NULL,NULL,"Mcrosoft Internet Explorer");
							ShellExecute(Openannet,"open","aboutfivechess.mht",0,0,SW_SHOWNORMAL);
						    break;
					   case ABOUTJINSHOU:
						     Openannet=FindWindowEx(NULL,NULL,NULL,"Mcrosoft Office Word 2003");
                             ShellExecute(Openannet,"open","fivechessjinshou.doc",0,0,SW_SHOWNORMAL);
							 break;
					   case ABOUTSDK:
						   Openannet=FindWindowEx(NULL,NULL,NULL,"Mcrosoft Internet Explorer");
                            ShellExecute(Openannet,"open","aboutsdk.mht",0,0,SW_SHOWNORMAL);
						     break;
					   case ABOUTAPI:
						    Openannet=FindWindowEx(NULL,NULL,NULL,"Mcrosoft Internet Explorer");
                            ShellExecute(Openannet,"open","aboutapi.mht",0,0,SW_SHOWNORMAL);
						     break;
					   case ABOUTZUOZE:
						     Openannet=FindWindowEx(NULL,NULL,NULL,"notepad");
                             ShellExecute(Openannet,"open","aboutme.txt",0,0,SW_SHOWNORMAL);
						     break;
					   case IDM_EXIT:
						    SendMessage(hWnd,WM_DESTROY,wParam,lParam);
							break;
					   case IDM_OPEN:
				            ShowWindow(hWnd,SW_SHOWNORMAL);
				            break;
					   }
					    SetClassLong(hWnd,GCL_HCURSOR,(long)hcursor[0]);
						SetCursor(hcursor[0]);
						break;
	case WM_ICON:
		     SetClassLong(hWnd,GCL_HCURSOR,NULL);
			 SetCursor(LoadCursor(NULL,IDC_ARROW));
		     switch(lParam)
			 {
			 case WM_RBUTTONDOWN:
				        POINT point;
		                GetCursorPos(&point);
						hmenu[1]=GetSubMenu(hMenu[1],0);
		                TrackPopupMenu(hmenu[1],TPM_LEFTALIGN,point.x,point.y,0,(HWND)hWnd,NULL);
						break;
			 case WM_LBUTTONDOWN:
				        ShowWindow(hWnd,SW_SHOWNORMAL);
						break;
			 }
			 break;
	case WM_SIZE:
		        if(wParam==SIZE_MINIMIZED)
				   ShowWindow(hWnd,SW_HIDE);
				else if(wParam==SIZE_RESTORED)
                   ;
		        break;
    case WM_CLOSE:
		        ShowWindow(hWnd,SW_HIDE);
				break;
	case WM_DESTROY:
		       sendmessage.type =msglineout;
			   sendornot=1;
                      Shell_NotifyIcon(NIM_DELETE,&icondata);
					  PostQuitMessage(0);
					  return 0;
					  break;
    default:DefWindowProc(hWnd,Msg,wParam,lParam);
	}
}
