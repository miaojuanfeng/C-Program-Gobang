DWORD  WINAPI  AnswerThread(LPVOID  lparam) //���������߳�
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
			           Chess[revmessage.pox][revmessage.poy]=black;                 //1��ʾ�º���	
					   SelectObject(mdc2,hbitmap[1]);
					   TransparentBlt2(hdc2,posi[revmessage.pox][revmessage.poy].x-12,posi[revmessage.pox][revmessage.poy].y-12,24,24,mdc2,0,0,24,24,RGB(255,0,255));
					   order=white;
					   KillTimer(Hwnd,TIMERWAITE);
					}
					else if(color==black)
					{
					   Chess[revmessage.pox][revmessage.poy]=white;                 //2��ʾ�°���	
					   SelectObject(mdc2,hbitmap[2]);
					   TransparentBlt2(hdc2,posi[revmessage.pox][revmessage.poy].x-12,posi[revmessage.pox][revmessage.poy].y-12,24,24,mdc2,0,0,24,24,RGB(255,0,255));
					   order=black;
					   KillTimer(Hwnd,TIMERWAITE);
					}
					DeleteObject(mdc2);
					DeleteDC(hdc2);
					TurnBackRecord(revmessage.pox,revmessage.poy);
                    
                    sprintf(staticcaption,"�Է�����(%d,%d)\n������...",revmessage.pox+1,revmessage.poy+1);
                    SetWindowText(hstatic,staticcaption);

					mciSendString("close downzi",NULL,NULL,NULL);
				    mciSendString("OPEN Sound\\downzi.wav alias downzi",NULL,NULL,NULL);
					mciSendString("play downzi",NULL,NULL,NULL);
					break;
		  case msgback:
			     if(IDYES==MessageBox(NULL,"�Է���Ҫ����,���Ƿ�ͬ��?","�Ƿ����?",MB_YESNO))
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
						      sprintf(staticcaption,"����ɹ�\nʱ�������ˣ����Ҫ��ϸ˼�������ӿ�");
						  }
						  else if(color==white)
						  {
						      sprintf(staticcaption,"����ɹ�\nʱ��������,�ȴ��Է�����...");
						  }
					   }
					   else if(order==white)
					   {
					      if(color==white)
						  {
						      sprintf(staticcaption,"����ɹ�\nʱ�������ˣ����Ҫ��ϸ˼�������ӿ�");
						  }
						  else if(color==black)
						  {
						      sprintf(staticcaption,"����ɹ�\nʱ��������,�ȴ��Է�����...");
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
						      sprintf(staticcaption,"����ɹ�\nʱ�������ˣ����Ҫ��ϸ˼�������ӿ�");
						  }
						  else if(color==white)
						  {
						      sprintf(staticcaption,"����ɹ�\nʱ��������,�ȴ��Է�����...");
						  }
					   }
					   else if(order==white)
					   {
					      if(color==white)
						  {
						      sprintf(staticcaption,"����ɹ�\nʱ�������ˣ����Ҫ��ϸ˼�������ӿ�");
						  }
						  else if(color==black)
						  {
						      sprintf(staticcaption,"����ɹ�\nʱ��������,�ȴ��Է�����...");
						  }
					   }
					   SetWindowText(hstatic,staticcaption);
						  break;
		  case msgnotoback:
			              MessageBox(NULL,"���ź����Է���ͬ�����!","���ź�",0);
						  SetWindowText(hstatic,server);
						  break;
		  case msgrestart:
			  if(IDYES==MessageBox(NULL,"�Է���Ҫ����,���Ƿ�ͬ��?","�Ƿ�����?",MB_YESNO))
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

				   
							 sprintf(staticcaption,"��Ϸ���¿�ʼ\n����׼����С�Ľ���");
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
				   sprintf(staticcaption,"��Ϸ���¿�ʼ\n����׼����С�Ľ���");
				   SetWindowText(hstatic,staticcaption);
				   break;
		  case msgnotorestart:
			       MessageBox(NULL,"���ź����Է���ͬ������!","���ź�",0);
				   SetWindowText(hstatic,server);
					break;
		  case msgchangerule:
			        if(IDYES==MessageBox(NULL,"�Է�Ҫ��ı䡾���ӽ��֡�����\n���Ƿ�ͬ�⣿","�ı����",MB_YESNO))
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
							      sprintf(staticcaption,"����ı�,�ޡ����ӽ��֡�����\n��Ϸ���¿�ʼ\n�ҷ�ִ�ڣ�������...");
								 else if(rule==1)
                                  sprintf(staticcaption,"����ı�,�С����ӽ��֡�����\n��Ϸ���¿�ʼ\n�ҷ�ִ�ڣ�������...");
							 }
							 else if(color==white)
							 {
							      if(rule==0)
							      sprintf(staticcaption,"����ı�,�ޡ����ӽ��֡�����\n��Ϸ���¿�ʼ\n�ҷ�ִ�ף���ȴ��Է�����...");
								 else if(rule==1)
                                  sprintf(staticcaption,"����ı�,�С����ӽ��֡�����\n��Ϸ���¿�ʼ\n�ҷ�ִ�ף���ȴ��Է�����...");
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
							      sprintf(staticcaption,"����ı�,�ޡ����ӽ��֡�����\n��Ϸ���¿�ʼ\n�ҷ�ִ�ڣ�������...");
								 else if(rule==1)
                                  sprintf(staticcaption,"����ı�,�С����ӽ��֡�����\n��Ϸ���¿�ʼ\n�ҷ�ִ�ڣ�������...");
							 }
							 else if(color==white)
							 {
							      if(rule==0)
							      sprintf(staticcaption,"����ı�,�ޡ����ӽ��֡�����\n��Ϸ���¿�ʼ\n�ҷ�ִ�ף���ȴ��Է�����...");
								 else if(rule==1)
                                  sprintf(staticcaption,"����ı�,�С����ӽ��֡�����\n��Ϸ���¿�ʼ\n�ҷ�ִ�ף���ȴ��Է�����...");
							 }
							 SetWindowText(hstatic,staticcaption);
			        break;
		  case msgnochangerule:
			        MessageBox(NULL,"���ź����Է���ͬ��ı���Ϸ����!","���ź�",0);
					SetWindowText(hstatic,server);
					break;
		  case msgchangecolor:
			        if(IDYES==MessageBox(NULL,"�Է�Ҫ��ɫ��\n���Ƿ�ͬ�⣿","��ɫ",MB_YESNO))
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
                                  sprintf(staticcaption,"��ɫ�ı�\n��Ϸ���¿�ʼ\n�ҷ�ִ�ڣ�������...");
							 }
							 else if(color==white)
							 {
                                  sprintf(staticcaption,"��ɫ�ı�\n��Ϸ���¿�ʼ\n�ҷ�ִ�ף���ȴ��Է�����...");
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
							      sprintf(staticcaption,"��ɫ�ı�\n��Ϸ���¿�ʼ\n�ҷ�ִ�ڣ�������...");
							 }
							 else if(color==white)
							 {
                                  sprintf(staticcaption,"��ɫ�ı�\n��Ϸ���¿�ʼ\n�ҷ�ִ�ף���ȴ��Է�����...");
							 }
							 SetWindowText(hstatic,staticcaption);
								 break;
		 case msgnochangecolor:
			        MessageBox(NULL,"���ź����Է���ͬ�⻻ɫ!","���ź�",0);
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
							      sprintf(staticcaption,"��ϲ��ϲ����Ӯ��\n������������δ����ʤ֮����\n���������һ��");
							 }
							 else if(color==white)
							 {
                                  sprintf(staticcaption,"���ź���������\n����㲻����\n��������һ��");
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
							      sprintf(staticcaption,"��ϲ��ϲ����Ӯ��\n������������δ����ʤ֮����\n���������һ��");
							 }
							 else if(color==black)
							 {
                                  sprintf(staticcaption,"���ź���������\n����㲻����\n��������һ��");
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
							      sprintf(staticcaption,"��ϲ��ϲ����Ӯ��\n������������δ����ʤ֮����\n���������һ��");
							 }
							 else if(color==black)
							 {
                                  sprintf(staticcaption,"���ź���������\nע����ӽ��ֹ���\n����㲻����,��������һ��");
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

                             sprintf(staticcaption,"�Է����ӵؿ�����\n��������ĺ�����");
							 SetWindowText(hstatic,staticcaption);
				  break;
			        
		  }
	 }
}

DWORD  WINAPI  AnswerThread2(LPVOID  lparam) //���������߳�
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