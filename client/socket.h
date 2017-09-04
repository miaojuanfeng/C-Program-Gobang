DWORD  WINAPI  AnswerThread(LPVOID  lparam) //接受数据线程
{
     while(1)
	 {
      recvfrom(so,(char*)&revmessage,sizeof(Msg),0,(SOCKADDR*)&add,&len); 
		  switch(revmessage.type)
		  {
		  case msgconnected:
			       color=revmessage.color;
				   rule=revmessage.rule;
					   if(color==black)
							order=black;
					   else if(color==white)
						    SetTimer(Hwnd,TIMERWAITE,500,NULL);
					   if(rule==0)
					   {
						         GetClientRect(Hwnd, &rc);
								 rc.bottom=70+400;
								 rc.top=70;
								 rc.left=212;
								 rc.right=212+400;
								 InvalidateRect(Hwnd,&rc,true);
					         hdc2=GetDC(Hwnd);
					         mdc2=(HDC)CreateCompatibleDC(hdc2);
							 imformation=1;
							 SelectObject(mdc2,himformation[imformation]);
							 TransparentBlt2(hdc2,212,70,400,400,mdc2,0,0,400,400,RGB(255,255,255));
					         DeleteObject(mdc2);
					         DeleteDC(hdc2);
					   }
					   else if(rule==1)
					   {
						    imformation=NONE;
					        GetClientRect(Hwnd, &rc);
							rc.bottom=70+400;
							rc.top=70;
							rc.left=212;
							rc.right=212+400;
							InvalidateRect(Hwnd,&rc,true);
					   }
				       if(rule==1)
						    CheckMenuItem(hMenu[0],IDM_HEIZIJINSHOU,MF_CHECKED);
                   strcpy(server,revmessage.server);
				   SetWindowText(hstatic,revmessage.server);
				        switchsong=2;
		                play=true;
						destroy=1;
				   break;
		  case msgchating:
			       SetWindowText(hedit[0],revmessage.chat);
				   break;
		  case msgchess:
			        hdc2=GetDC(Hwnd);
					mdc2=(HDC)CreateCompatibleDC(hdc2);
			        if(color==white)
					{
			           Chess[revmessage.pox][revmessage.poy]=black;                 //1表示下黑子	
					   SelectObject(mdc2,hbitmap[1]);
					   TransparentBlt2(hdc2,posi[revmessage.pox][revmessage.poy].x-12,posi[revmessage.pox][revmessage.poy].y-12,24,24,mdc2,0,0,24,24,RGB(255,0,255));
					   order=white;
					   KillTimer(Hwnd,TIMERWAITE);
					}
					else if(color==black)
					{
					   Chess[revmessage.pox][revmessage.poy]=white;                 //2表示下白子	
					   SelectObject(mdc2,hbitmap[2]);
					   TransparentBlt2(hdc2,posi[revmessage.pox][revmessage.poy].x-12,posi[revmessage.pox][revmessage.poy].y-12,24,24,mdc2,0,0,24,24,RGB(255,0,255));
					   order=black;
					   KillTimer(Hwnd,TIMERWAITE);
					}
					DeleteObject(mdc2);
					DeleteDC(hdc2);
					TurnBackRecord(revmessage.pox,revmessage.poy);
                    
                    sprintf(staticcaption,"对方落子(%d,%d)\n请落子...",revmessage.pox+1,revmessage.poy+1);
                    SetWindowText(hstatic,staticcaption);

					mciSendString("close downzi",NULL,NULL,NULL);
				    mciSendString("OPEN Sound\\downzi.wav alias downzi",NULL,NULL,NULL);
					mciSendString("play downzi",NULL,NULL,NULL);
					break;
		  case msgback:
			     if(IDYES==MessageBox(NULL,"对方想要悔棋,你是否同意?","是否悔棋?",MB_YESNO))
				 {
			               if(!TurnBack())
						   {
						       	GetClientRect(Hwnd, &rc);
								 rc.bottom=460;
								 rc.top=78;
								 rc.left=220;
								 rc.right=600;
								 InvalidateRect(Hwnd,&rc,true);
								 if(order==black)
								 {
									 order=white;
									 KillTimer(Hwnd,TIMERWAITE);
									 if(color==black)
					                   SetTimer(Hwnd,TIMERWAITE,500,NULL);
								 }
				                 else if(order==white)
								 {
									 order=black;
									 KillTimer(Hwnd,TIMERWAITE);
									 if(color==white)
					                   SetTimer(Hwnd,TIMERWAITE,500,NULL);
								 }
						   }
                       sendmessage.type=msgyestoback;
					   sendornot=1;
					   if(switchsong==3)
					   {
						   switchsong=2;
						   play=true;
					   }
					   if(order==black)
					   {
					      if(color==black)
						  {
						      sprintf(staticcaption,"悔棋成功\n时光逆流了，这次要仔细思考后落子咯");
						  }
						  else if(color==white)
						  {
						      sprintf(staticcaption,"悔棋成功\n时光逆流了,等待对方落子...");
						  }
					   }
					   else if(order==white)
					   {
					      if(color==white)
						  {
						      sprintf(staticcaption,"悔棋成功\n时光逆流了，这次要仔细思考后落子咯");
						  }
						  else if(color==black)
						  {
						      sprintf(staticcaption,"悔棋成功\n时光逆流了,等待对方落子...");
						  }
					   }
					   SetWindowText(hstatic,staticcaption);
				 }
				 else
				 {
				       sendmessage.type=msgnotoback;
					   sendornot=1;
				 }
				break;
		  case msgyestoback:
			              if(!TurnBack())
						   {
						       	GetClientRect(Hwnd, &rc);
								 rc.bottom=460;
								 rc.top=78;
								 rc.left=220;
								 rc.right=600;
								 InvalidateRect(Hwnd,&rc,true);
								  if(order==black)
								 {
									 order=white;
									 KillTimer(Hwnd,TIMERWAITE);
									 if(color==black)
					                   SetTimer(Hwnd,TIMERWAITE,500,NULL);
								 }
				                 else if(order==white)
								 {
									 order=black;
									 KillTimer(Hwnd,TIMERWAITE);
									 if(color==white)
					                   SetTimer(Hwnd,TIMERWAITE,500,NULL);
								 }
						   }
						  SetWindowText(hstatic,server);
						  if(switchsong==3)
						   {
							   switchsong=2;
							   play=true;
						   }
						  if(order==black)
					   {
					      if(color==black)
						  {
						      sprintf(staticcaption,"悔棋成功\n时光逆流了，这次要仔细思考后落子咯");
						  }
						  else if(color==white)
						  {
						      sprintf(staticcaption,"悔棋成功\n时光逆流了,等待对方落子...");
						  }
					   }
					   else if(order==white)
					   {
					      if(color==white)
						  {
						      sprintf(staticcaption,"悔棋成功\n时光逆流了，这次要仔细思考后落子咯");
						  }
						  else if(color==black)
						  {
						      sprintf(staticcaption,"悔棋成功\n时光逆流了,等待对方落子...");
						  }
					   }
					   SetWindowText(hstatic,staticcaption);
						  break;
		  case msgnotoback:
			              MessageBox(NULL,"很遗憾，对方不同意悔棋!","很遗憾",0);
						  SetWindowText(hstatic,server);
						  break;
		  case msgrestart:
			  if(IDYES==MessageBox(NULL,"对方想要重来,你是否同意?","是否重来?",MB_YESNO))
			  {
				  order=black;
				  winpic=NONE;
				  if(color==black)
					   KillTimer(Hwnd,TIMERWAITE);
				  else if(color==white)
					   SetTimer(Hwnd,TIMERWAITE,500,NULL);
                            for( i=0;i<15;i++)
		                        for( j=0;j<15;j++)
								 {
			                         Chess[i][j]=NONE;
									 posit[i][j].x=NONE;
									 posit[i][j].y=NONE;
								 }
								 GetClientRect(Hwnd, &rc);
								 rc.bottom=460;
								 rc.top=78;
								 rc.left=220;
								 rc.right=600;
								 InvalidateRect(Hwnd,&rc,true);
                   sendmessage.type=msgyestorestart;
				   sendornot=1;

				   if(switchsong==3)
				   {
					   switchsong=2;
				       play=true;
				   }

				   
							 sprintf(staticcaption,"游戏重新开始\n做好准备，小心谨慎");
							 SetWindowText(hstatic,staticcaption);
			  }
			  else
			  {
			           sendmessage.type=msgnotorestart;
					   sendornot=1;
			  }
		  case msgyestorestart:
			      order=black;
				  winpic=NONE;
				  if(color==black)
					   KillTimer(Hwnd,TIMERWAITE);
				  else if(color==white)
					   SetTimer(Hwnd,TIMERWAITE,500,NULL);
			                 for( i=0;i<15;i++)
		                        for( j=0;j<15;j++)
								 {
			                         Chess[i][j]=NONE;
									 posit[i][j].x=NONE;
									 posit[i][j].y=NONE;
								 }
								 GetClientRect(Hwnd, &rc);
								 rc.bottom=460;
								 rc.top=78;
								 rc.left=220;
								 rc.right=600;
								 InvalidateRect(Hwnd,&rc,true);

                   SetWindowText(hstatic,server);

				   if(switchsong==3)
				   {
					   switchsong=2;
				       play=true;
				   }
				   sprintf(staticcaption,"游戏重新开始\n做好准备，小心谨慎");
				   SetWindowText(hstatic,staticcaption);
				   break;
		  case msgnotorestart:
			       MessageBox(NULL,"很遗憾，对方不同意重来!","很遗憾",0);
				   SetWindowText(hstatic,server);
					break;
		  case msgchangerule:
			        if(IDYES==MessageBox(NULL,"对方要求改变【黑子禁手】规则，\n你是否同意？","改变规则",MB_YESNO))
					{
					     sendmessage.type =msgyeschangerule;
						 sendornot=1;
                         order=black;
						 rule=revmessage.rule;
						 winpic=NONE;
					if(rule==1)
                           CheckMenuItem(hMenu[0],IDM_HEIZIJINSHOU,MF_CHECKED);
					else if(rule==0)
						   CheckMenuItem(hMenu[0],IDM_HEIZIJINSHOU,MF_UNCHECKED);
					     for( i=0;i<15;i++)
		                        for( j=0;j<15;j++)
								 {
			                         Chess[i][j]=NONE;
									 posit[i][j].x=NONE;
									 posit[i][j].y=NONE;
								 }
								 GetClientRect(Hwnd, &rc);
								 rc.bottom=460;
								 rc.top=78;
								 rc.left=220;
								 rc.right=600;
								 InvalidateRect(Hwnd,&rc,true);

								 if(color==black)
									   KillTimer(Hwnd,TIMERWAITE);
								  else if(color==white)
									   SetTimer(Hwnd,TIMERWAITE,500,NULL);

								   if(switchsong==3)
								   {
									   switchsong=2;
									   play=true;
								   }

                             if(color==black)
							 {
								 if(rule==0)
							      sprintf(staticcaption,"规则改变,无【黑子禁手】规则\n游戏重新开始\n我方执黑，请落子...");
								 else if(rule==1)
                                  sprintf(staticcaption,"规则改变,有【黑子禁手】规则\n游戏重新开始\n我方执黑，请落子...");
							 }
							 else if(color==white)
							 {
							      if(rule==0)
							      sprintf(staticcaption,"规则改变,无【黑子禁手】规则\n游戏重新开始\n我方执白，请等待对方落子...");
								 else if(rule==1)
                                  sprintf(staticcaption,"规则改变,有【黑子禁手】规则\n游戏重新开始\n我方执白，请等待对方落子...");
							 }
							 SetWindowText(hstatic,staticcaption);
					}
					else
					{
					     sendmessage.type =msgnochangerule;
						 sendornot=1;
					}
					break;
		  case msgyeschangerule:
			        order=black;
			        rule=revmessage.rule;
					winpic=NONE;
					if(rule==1)
                           CheckMenuItem(hMenu[0],IDM_HEIZIJINSHOU,MF_CHECKED);
					else if(rule==0)
						   CheckMenuItem(hMenu[0],IDM_HEIZIJINSHOU,MF_UNCHECKED);
					     for( i=0;i<15;i++)
		                        for( j=0;j<15;j++)
								 {
			                         Chess[i][j]=NONE;
									 posit[i][j].x=NONE;
									 posit[i][j].y=NONE;
								 }
								 GetClientRect(Hwnd, &rc);
								 rc.bottom=460;
								 rc.top=78;
								 rc.left=220;
								 rc.right=600;
								 InvalidateRect(Hwnd,&rc,true);

								 if(color==black)
									   KillTimer(Hwnd,TIMERWAITE);
								  else if(color==white)
									   SetTimer(Hwnd,TIMERWAITE,500,NULL);
								  SetWindowText(hstatic,server);
								  if(switchsong==3)
								   {
									   switchsong=2;
									   play=true;
								   }

								  if(color==black)
							 {
								 if(rule==0)
							      sprintf(staticcaption,"规则改变,无【黑子禁手】规则\n游戏重新开始\n我方执黑，请落子...");
								 else if(rule==1)
                                  sprintf(staticcaption,"规则改变,有【黑子禁手】规则\n游戏重新开始\n我方执黑，请落子...");
							 }
							 else if(color==white)
							 {
							      if(rule==0)
							      sprintf(staticcaption,"规则改变,无【黑子禁手】规则\n游戏重新开始\n我方执白，请等待对方落子...");
								 else if(rule==1)
                                  sprintf(staticcaption,"规则改变,有【黑子禁手】规则\n游戏重新开始\n我方执白，请等待对方落子...");
							 }
							 SetWindowText(hstatic,staticcaption);
			        break;
		  case msgnochangerule:
			        MessageBox(NULL,"很遗憾，对方不同意改变游戏规则!","很遗憾",0);
					SetWindowText(hstatic,server);
					break;
		  case msgchangecolor:
			        if(IDYES==MessageBox(NULL,"对方要求换色，\n你是否同意？","换色",MB_YESNO))
					{
					     sendmessage.type =msgyeschangecolor;
						 sendornot=1;
                         winpic=NONE;
						 if(color==black)
						 {
						       color=white;
							   SetTimer(Hwnd,TIMERWAITE,500,NULL);
						 }
					    else if(color==white)
						{
						       color=black;
							   KillTimer(Hwnd,TIMERWAITE);
						}
						 order=black;
					        for( i=0;i<15;i++)
		                        for( j=0;j<15;j++)
								 {
			                         Chess[i][j]=NONE;
									 posit[i][j].x=NONE;
									 posit[i][j].y=NONE;
								 }
								 GetClientRect(Hwnd, &rc);
								 rc.bottom=460;
								 rc.top=78;
								 rc.left=220;
								 rc.right=600;
								 InvalidateRect(Hwnd,&rc,true);

								   if(switchsong==3)
								   {
									   switchsong=2;
									   play=true;
								   }

							 if(color==black)
							 {
                                  sprintf(staticcaption,"颜色改变\n游戏重新开始\n我方执黑，请落子...");
							 }
							 else if(color==white)
							 {
                                  sprintf(staticcaption,"颜色改变\n游戏重新开始\n我方执白，请等待对方落子...");
							 }
							 SetWindowText(hstatic,staticcaption);
					}
					else
					{
					     sendmessage.type =msgnochangecolor;
						 sendornot=1;
					}
					break;
		  case msgyeschangecolor:
			            if(color==black)
						 {
						       color=white;
							   SetTimer(Hwnd,TIMERWAITE,500,NULL);
						 }
					    else if(color==white)
						{
						       color=black;
							   KillTimer(Hwnd,TIMERWAITE);
						}
                        order=black;
                         winpic=NONE;
					        for( i=0;i<15;i++)
		                        for( j=0;j<15;j++)
								 {
			                         Chess[i][j]=NONE;
									 posit[i][j].x=NONE;
									 posit[i][j].y=NONE;
								 }
								 GetClientRect(Hwnd, &rc);
								 rc.bottom=460;
								 rc.top=78;
								 rc.left=220;
								 rc.right=600;
								 InvalidateRect(Hwnd,&rc,true);

								 SetWindowText(hstatic,server);

								  if(switchsong==3)
								   {
									   switchsong=2;
									   play=true;
								   }

						     if(color==black)
							 {
							      sprintf(staticcaption,"颜色改变\n游戏重新开始\n我方执黑，请落子...");
							 }
							 else if(color==white)
							 {
                                  sprintf(staticcaption,"颜色改变\n游戏重新开始\n我方执白，请等待对方落子...");
							 }
							 SetWindowText(hstatic,staticcaption);
								 break;
		 case msgnochangecolor:
			        MessageBox(NULL,"很遗憾，对方不同意换色!","很遗憾",0);
					SetWindowText(hstatic,server);
					break;
		 case msgblackwin:
			     hdc2=GetDC(Hwnd);
				 mdc2=(HDC)CreateCompatibleDC(hdc2);
			     SelectObject(mdc2,hwin[0]);
				 TransparentBlt2(hdc2,360,220,100,100,mdc2,0,0,100,100,RGB(255,255,255));
				 DeleteObject(mdc2);
				 DeleteDC(hdc2);
				 winpic=0;
				 order=0;
				 KillTimer(Hwnd,TIMERWAITE);
				                            play=true;
											switchsong=3;
							 if(color==black)
							 {
							      sprintf(staticcaption,"恭喜恭喜，你赢了\n如果你觉得意犹未尽或胜之不武\n你可以再来一局");
							 }
							 else if(color==white)
							 {
                                  sprintf(staticcaption,"很遗憾，你输了\n如果你不服气\n可以再来一局");
							 }
							 SetWindowText(hstatic,staticcaption);
			 break;
		 case msgwhitewin:
			 hdc2=GetDC(Hwnd);
				 mdc2=(HDC)CreateCompatibleDC(hdc2);
			     SelectObject(mdc2,hwin[1]);
				 TransparentBlt2(hdc2,360,220,100,100,mdc2,0,0,100,100,RGB(255,255,255));
				 DeleteObject(mdc2);
				 DeleteDC(hdc2);
				 winpic=1;
			 order=0;
			 KillTimer(Hwnd,TIMERWAITE);
			                                play=true;
											switchsong=3;
							if(color==white)
							 {
							      sprintf(staticcaption,"恭喜恭喜，你赢了\n如果你觉得意犹未尽或胜之不武\n你可以再来一局");
							 }
							 else if(color==black)
							 {
                                  sprintf(staticcaption,"很遗憾，你输了\n如果你不服气\n可以再来一局");
							 }
							 SetWindowText(hstatic,staticcaption);
			 break;
		 case msgjinshou:
			     hdc2=GetDC(Hwnd);
				 mdc2=(HDC)CreateCompatibleDC(hdc2);
			     SelectObject(mdc2,hwin[2]);
				 TransparentBlt2(hdc2,360,220,100,100,mdc2,0,0,100,100,RGB(255,255,255));
				 DeleteObject(mdc2);
				 DeleteDC(hdc2);
				 winpic=2;
			order=0;
			KillTimer(Hwnd,TIMERWAITE);
			                                play=true;
											switchsong=3;
							 if(color==white)
							 {
							      sprintf(staticcaption,"恭喜恭喜，你赢了\n如果你觉得意犹未尽或胜之不武\n你可以再来一局");
							 }
							 else if(color==black)
							 {
                                  sprintf(staticcaption,"很遗憾，你输了\n注意黑子禁手规则\n如果你不服气,可以再来一局");
							 }
							 SetWindowText(hstatic,staticcaption);
			break;
		 case msglineout:
			     GetClientRect(Hwnd, &rcwin);
                 rcwin.top =220;
				 rcwin.bottom =320;
				 rcwin.left =360;
				 rcwin.right =460;
                 InvalidateRect(Hwnd,&rcwin,true);
			    
			     hdc2=GetDC(Hwnd);
				 mdc2=(HDC)CreateCompatibleDC(hdc2);
			     SelectObject(mdc2,hwin[3]);
				 TransparentBlt2(hdc2,360,220,100,100,mdc2,0,0,100,100,RGB(255,255,255));
				 DeleteObject(mdc2);
				 DeleteDC(hdc2);
				 winpic=3;
			       order=0;
				  KillTimer(Hwnd,TIMERWAITE);
				                            play=true;
											switchsong=3;

                             sprintf(staticcaption,"对方胆怯地开溜了\n看来你真的很厉害");
							 SetWindowText(hstatic,staticcaption);
				  break;
			        
		  }
	 }
}

DWORD  WINAPI  AnswerThread2(LPVOID  lparam) //发送数据线程
{
    while(1)
	{
		if(sendornot==1)
		{
            sendto(so,(char*)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&add,len);
			sendornot=0;
		}
		Sleep(10);
	}
}

sock()
{	
    WORD banben;
	WSADATA data;
	banben=MAKEWORD(1,1);
	if(WSAStartup(banben,&data))
	{
	   MessageBox(NULL,"socket load wrong!","",0);
	   return;
	}
	if(LOBYTE(data.wVersion)!=1||
		HIBYTE(data.wVersion)!=1)
	{
	   MessageBox(NULL,"socket data wrong!","",0);
	   return;
	}

	so=socket(AF_INET,SOCK_DGRAM,0);

	add.sin_addr.S_un.S_addr=inet_addr(ip);
	add.sin_family=AF_INET;
	add.sin_port=htons(65500);
	
    len=sizeof(SOCKADDR);
    sendto(so,(char*)&sendmessage,sizeof(Msg),0,(SOCKADDR*)&add,len);

	                   DWORD  dwThreadId,dwThreadId2;  
                       HANDLE  hThread[2];  
                     
                       hThread[0]=CreateThread(NULL,NULL,AnswerThread,  
                                   (LPVOID)so,0,&dwThreadId); 
					   hThread[1]=CreateThread(NULL,NULL,AnswerThread2,  
                                   (LPVOID)so,0,&dwThreadId2);
}