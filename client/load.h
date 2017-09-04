load(HINSTANCE hInstance)
{
    hMenu[0]=LoadMenu(hInstance,MAKEINTRESOURCE(IDM_MAIN));
    hMenu[1]=LoadMenu(hInstance,MAKEINTRESOURCE(IDA_MAIN));

    hcursor[0]=LoadCursor(hInstance,"ID_CUR");
	hcursor[1]=LoadCursor(hInstance,"ID_CUR2");
	hcursor[2]=LoadCursor(hInstance,"ID_CUR3");
	hcursor[3]=LoadCursor(hInstance,"ID_CUR4");
	hcursor[4]=LoadCursor(hInstance,"ID_CUR5");
    hbitmap[0]=(HBITMAP)LoadImage(hInstance,"Image\\Table.bmp",IMAGE_BITMAP,1043,547,LR_LOADFROMFILE);
    hbitmap[1]=(HBITMAP)LoadImage(hInstance,"Image\\Black.bmp",IMAGE_BITMAP,24,24,LR_LOADFROMFILE);
	hbitmap[2]=(HBITMAP)LoadImage(hInstance,"Image\\White.bmp",IMAGE_BITMAP,24,24,LR_LOADFROMFILE);
	hbitmap[3]=(HBITMAP)LoadImage(hInstance,"Image\\load.bmp",IMAGE_BITMAP,1043,547,LR_LOADFROMFILE);

    hwin[0]=(HBITMAP)LoadImage(hInstance,"Image\\blackwin.bmp",IMAGE_BITMAP,100,100,LR_LOADFROMFILE);
	hwin[1]=(HBITMAP)LoadImage(hInstance,"Image\\whitewin.bmp",IMAGE_BITMAP,100,100,LR_LOADFROMFILE);
    hwin[2]=(HBITMAP)LoadImage(hInstance,"Image\\blackjinshou.bmp",IMAGE_BITMAP,100,100,LR_LOADFROMFILE);
	hwin[3]=(HBITMAP)LoadImage(hInstance,"Image\\lineout.bmp",IMAGE_BITMAP,100,100,LR_LOADFROMFILE);

	hcom[0]=(HBITMAP)LoadImage(hInstance,"Image\\restart.bmp",IMAGE_BITMAP,110,30,LR_LOADFROMFILE);
	hcom[1]=(HBITMAP)LoadImage(hInstance,"Image\\back.bmp",IMAGE_BITMAP,110,30,LR_LOADFROMFILE);
	hcom[2]=(HBITMAP)LoadImage(hInstance,"Image\\changecolor.bmp",IMAGE_BITMAP,110,30,LR_LOADFROMFILE);
	hcom[3]=(HBITMAP)LoadImage(hInstance,"Image\\exit.bmp",IMAGE_BITMAP,110,30,LR_LOADFROMFILE);
	hcom[4]=(HBITMAP)LoadImage(hInstance,"Image\\send.bmp",IMAGE_BITMAP,110,30,LR_LOADFROMFILE);

	himformation[0]=(HBITMAP)LoadImage(hInstance,"Image\\imformation1.bmp",IMAGE_BITMAP,400,400,LR_LOADFROMFILE);
	himformation[1]=(HBITMAP)LoadImage(hInstance,"Image\\imformation2.bmp",IMAGE_BITMAP,400,400,LR_LOADFROMFILE);

    hbitmapsend[0]=(HBITMAP)LoadImage(hInstance,"Image\\send1.bmp",IMAGE_BITMAP,40,40,LR_LOADFROMFILE);
    hbitmapsend[1]=(HBITMAP)LoadImage(hInstance,"Image\\send2.bmp",IMAGE_BITMAP,40,40,LR_LOADFROMFILE);
	hbitmapsend[2]=(HBITMAP)LoadImage(hInstance,"Image\\send3.bmp",IMAGE_BITMAP,40,40,LR_LOADFROMFILE);

	hbird[0]=(HBITMAP)LoadImage(hInstance,"Image\\bird1.bmp",IMAGE_BITMAP,68,63,LR_LOADFROMFILE);
	hbird[1]=(HBITMAP)LoadImage(hInstance,"Image\\bird2.bmp",IMAGE_BITMAP,68,63,LR_LOADFROMFILE);

	hwaite[0]=(HBITMAP)LoadImage(hInstance,"Image\\waite.bmp",IMAGE_BITMAP,129,32,LR_LOADFROMFILE);
	hwaite[1]=(HBITMAP)LoadImage(hInstance,"Image\\waite1.bmp",IMAGE_BITMAP,129,32,LR_LOADFROMFILE);
	hwaite[2]=(HBITMAP)LoadImage(hInstance,"Image\\waite2.bmp",IMAGE_BITMAP,129,32,LR_LOADFROMFILE);
	hwaite[3]=(HBITMAP)LoadImage(hInstance,"Image\\waite3.bmp",IMAGE_BITMAP,129,32,LR_LOADFROMFILE);
    hwaite[4]=(HBITMAP)LoadImage(hInstance,"Image\\waite22.bmp",IMAGE_BITMAP,298,55,LR_LOADFROMFILE);

    hrabbit[0]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\1.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[1]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\2.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[2]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\3.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[3]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\4.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[4]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\5.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[5]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\6.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[6]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\7.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[7]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\8.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[8]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\9.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[9]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\10.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[10]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\11.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[11]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\12.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[12]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\13.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[13]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\14.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);
	hrabbit[14]=(HBITMAP)LoadImage(hInstance,"Image\\Rabbit\\15.bmp",IMAGE_BITMAP,96,96,LR_LOADFROMFILE);

    hdog[0]=(HBITMAP)LoadImage(hInstance,"Image\\Dog\\1.bmp",IMAGE_BITMAP,73,94,LR_LOADFROMFILE);
	hdog[1]=(HBITMAP)LoadImage(hInstance,"Image\\Dog\\2.bmp",IMAGE_BITMAP,73,94,LR_LOADFROMFILE);

	hkiss[0]=(HBITMAP)LoadImage(hInstance,"Image\\Kiss\\1.bmp",IMAGE_BITMAP,88,107,LR_LOADFROMFILE);
	hkiss[1]=(HBITMAP)LoadImage(hInstance,"Image\\Kiss\\2.bmp",IMAGE_BITMAP,88,107,LR_LOADFROMFILE);
	hkiss[2]=(HBITMAP)LoadImage(hInstance,"Image\\Kiss\\3.bmp",IMAGE_BITMAP,88,107,LR_LOADFROMFILE);
	hkiss[3]=(HBITMAP)LoadImage(hInstance,"Image\\Kiss\\4.bmp",IMAGE_BITMAP,88,107,LR_LOADFROMFILE);
	hkiss[4]=(HBITMAP)LoadImage(hInstance,"Image\\Kiss\\5.bmp",IMAGE_BITMAP,88,107,LR_LOADFROMFILE);

	hhand[0]=(HBITMAP)LoadImage(hInstance,"Image\\Hand\\1.bmp",IMAGE_BITMAP,97,111,LR_LOADFROMFILE);
	hhand[1]=(HBITMAP)LoadImage(hInstance,"Image\\Hand\\2.bmp",IMAGE_BITMAP,97,111,LR_LOADFROMFILE);

    for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			Chess[i][j]=NONE;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
		{posi[i][j].x=236+25*i;posi[i][j].y=95+25*j;}
    for(i=0;i<15;i++)
		for(j=0;j<15;j++)
		{posit[i][j].x=NONE;posit[i][j].y=NONE;}
}