int  Position(int x,int y,int *k,int *l)
{
     int i,j;
	 for(i=0;i<15;i++)
		 for(j=0;j<15;j++)
		if((227+25*i<x)&&(x<245+25*i)&&(86+25*j<y)&&(y<104+25*j))
			 {  *k=i;*l=j;return 0;}
    return -1;
}

int TurnBackRecord(int x,int y)
{
   for(i=0;i<15;i++)
	   for(j=0;j<15;j++)
		   if(posit[i][j].x==NONE&&posit[i][j].y==NONE)
		   {posit[i][j].x=x;posit[i][j].y=y;return 0;}
   return -1;
}

int TurnBack()
{
   for(i=0;i<15;i++)
	   for(j=0;j<15;j++)
	   {
		  if(posit[0][0].x!=NONE&&posit[0][0].y!=NONE&&posit[0][1].x==NONE&&posit[0][1].y==NONE)
		   {Chess[posit[0][0].x][posit[0][0].y]=NONE;posit[0][0].x=NONE;posit[0][0].y=NONE;return 0;}
		   else if(posit[i][j].x==NONE&&posit[i][j].y==NONE)
		   {Chess[posit[i][j-1].x][posit[i][j-1].y]=NONE;posit[i][j-1].x=NONE;posit[i][j-1].y=NONE;return 0;}
		   else if(posit[14][14].x!=NONE&&posit[14][14].y!=NONE)
		   {Chess[posit[14][14].x][posit[14][14].y]=NONE;posit[i][j-1].x=NONE;posit[i][j-1].y=NONE;return 0;}
	   }
	return -1;
}

int Win()
{
    int x,y;

	for(y=0;y<15;y++)                //判断横向五子
     	for(x=0;x<11;x++)
		{
			if(Chess[x][y]==black&&Chess[x+1][y]==black&&Chess[x+2][y]==black&&Chess[x+3][y]==black&&Chess[x+4][y]==black)
                      return black;
			else if(Chess[x][y]==white&&Chess[x+1][y]==white&&Chess[x+2][y]==white&&Chess[x+3][y]==white&&Chess[x+4][y]==white)
				      return white;
		}
    for(x=0;x<15;x++)                //判断纵向五子
		for(y=0;y<11;y++)
		{
			if(Chess[x][y]==black&&Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]==black&&Chess[x][y+4]==black)
				      return black;
			else if(Chess[x][y]==white&&Chess[x+1][y]==white&&Chess[x+2][y]==white&&Chess[x+3][y]==white&&Chess[x+4][y]==white)
				      return white;
		}
    for(x=0;x<11;x++)                //判断“\”方向
		for(y=0;y<11;y++)
		{
			if(Chess[x][y]==black&&Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==black&&Chess[x+4][y+4]==black)
                return black;
			else if(Chess[x][y]==white&&Chess[x+1][y+1]==white&&Chess[x+2][y+2]==white&&Chess[x+3][y+3]==white&&Chess[x+4][y+4]==white)
                return white;
		}
    for(x=4;x<15;x++)                //判断“/”方向
		for(y=0;y<11;y++)
		{
            if(Chess[x][y]==black&&Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==black)
                return black;
			else if(Chess[x][y]==white&&Chess[x-1][y+1]==white&&Chess[x-2][y+2]==white&&Chess[x-3][y+3]==white&&Chess[x-4][y+4]==white)
                return white;
		}
}

int forbid1()
{
	 int x,y;
     for(y=0;y<15;y++)
		 for(x=0;x<10;x++)
		 {
			 if(Chess[x][y]==black&&Chess[x+1][y]==black&&Chess[x+2][y]==black&&Chess[x+3][y]==black&&Chess[x+4][y]==black&&Chess[x+5][y]==black)
			 {  
			    return 3;
			 }
		 }
     for(x=0;x<15;x++)
		 for(y=0;y<10;y++)
		 {
             if(Chess[x][y]==black&&Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]==black&&Chess[x][y+4]==black&&Chess[x][y+5]==black)
			 { 
				return 3;
			 }
		 }
	 for(x=0;x<10;x++)
		 for(y=0;y<10;y++)
		 {
		    if(Chess[x][y]==black&&Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==black&&Chess[x+4][y+4]==black&&Chess[x+5][y+5]==black)
		    { 
				return 3;
			}
		 }
	 for(x=5;x<15;x++)
		 for(y=0;y<10;y++)
		 {
		    if(Chess[x][y]==black&&Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==black&&Chess[x-5][y+5]==black)
			{ 
				return 3;
			}
		 }
     Win();
}

int forbid2(int x,int y)
{
	//////////////////////////三三禁手//////////////////////////////////////////////////////////
    if((Chess[x-1][y]==black&&Chess[x-2][y]==black&&Chess[x-3][y]==NONE&&Chess[x+1][y]==NONE
		||Chess[x+1][y]==black&&Chess[x+2][y]==black&&Chess[x+3][y]==NONE&&Chess[x-1][y]==NONE)
		&&(Chess[x-1][y-1]==NONE&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==black&&Chess[x-4][y-4]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x][y-1]==NONE&&Chess[x][y-2]==black&&Chess[x][y-3]==black&&Chess[x][y-4]==NONE&&Chess[x][y+1]==NONE
		||Chess[x+1][y-1]==NONE&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==black&&Chess[x+4][y-4]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==NONE&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==black&&Chess[x+4][y+4]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x][y+1]==NONE&&Chess[x][y+2]==black&&Chess[x][y+3]==black&&Chess[x][y+4]==NONE&&Chess[x][y-1]==NULL
		||Chess[x-1][y+1]==NONE&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	else if((Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]==NONE&&Chess[x][y+1]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]==NONE&&Chess[x][y-1]==NONE)
		&&(Chess[x-1][y-1]==NONE&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==black&&Chess[x-4][y-4]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x+1][y-1]==NONE&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==black&&Chess[x+4][y-4]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==NONE&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==black&&Chess[x+4][y+4]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x-1][y+1]==NONE&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	else if((Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==NONE&&Chess[x-1][y-1]==NONE)
		&&(Chess[x+1][y-1]==NONE&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==black&&Chess[x+4][y-4]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x-1][y+1]==NONE&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	//////////////////////////////////另一种三三禁手，边界处理////////////////////////////////////////////////////////////
    else if((Chess[x-1][y]==black&&Chess[x-2][y]==NONE&&Chess[x+1][y]==black&&Chess[x+2][y]==NONE)
		&&(Chess[x-1][y-1]==NONE&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==black&&Chess[x-4][y-4]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x][y-1]==NONE&&Chess[x][y-2]==black&&Chess[x][y-3]==black&&Chess[x][y-4]==NONE&&Chess[x][y+1]==NONE
		||Chess[x+1][y-1]==NONE&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==black&&Chess[x+4][y-4]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==NONE&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==black&&Chess[x+4][y+4]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x][y+1]==NONE&&Chess[x][y+2]==black&&Chess[x][y+3]==black&&Chess[x][y+4]==NONE&&Chess[x][y-1]==NONE
		||Chess[x-1][y+1]==NONE&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==NONE&&Chess[x+1][y-1]==NONE))
    {
	return 3;
	}
	else if((Chess[x][y-1]==black&&Chess[x][y-2]==NONE&&Chess[x][y+1]==black&&Chess[x][y+2]==NONE)
		&&(Chess[x-1][y-1]==NONE&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==black&&Chess[x-4][y-4]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x+1][y-1]==NONE&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==black&&Chess[x+4][y-4]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==NONE&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==black&&Chess[x+4][y+4]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x-1][y+1]==NONE&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==NONE&&Chess[x+1][y-1]==NONE))
    {
	return 3;
	}
	else if((Chess[x-1][y-1]==black&&Chess[x-2][y-2]==NONE&&Chess[x+1][y+1]==black&&Chess[x+2][y+2]==NONE)
		&&(Chess[x+1][y-1]==NONE&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==black&&Chess[x+4][y-4]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x-1][y+1]==NONE&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==NONE&&Chess[x+1][y-1]==NONE))
    {
	return 3;
	}
	//////////////////////////////////另一种三三禁手，边界处理////////////////////////////////////////////////////////////
	else if((Chess[x-1][y]==black&&Chess[x-2][y]==black&&Chess[x-3][y]==NONE&&Chess[x+1][y]==NONE
		||Chess[x+1][y]==black&&Chess[x+2][y]==black&&Chess[x+3][y]==NONE&&Chess[x-1][y]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]==NONE&&Chess[x][y+1]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]==NONE&&Chess[x][y-1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	else if((Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]==NONE&&Chess[x][y+1]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]==NONE&&Chess[x][y-1]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	else if((Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==NONE&&Chess[x-1][y-1]==NONE)
		&&(Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
		//////////////////////////////////另一种三三禁手，边界处理////////////////////////////////////////////////////////////
	else if((Chess[x-1][y]==black&&Chess[x-2][y]==NONE&&Chess[x+1][y]==black&&Chess[x+2][y]==NONE
		&&Chess[x][y-1]==black&&Chess[x][y-2]==NONE&&Chess[x][y+1]==black&&Chess[x][y+2]==NONE))
	{
	return 3;
	}
	//////////////////////四四有界无界禁手/////////////////////////////////////////////////////
	else if((Chess[x-1][y]==black&&Chess[x-2][y]==black&&Chess[x-3][y]==black&&Chess[x-4][y]!=black&&Chess[x+1][y]==NONE
		||Chess[x+1][y]==black&&Chess[x+2][y]==black&&Chess[x+3][y]==black&&Chess[x+4][y]!=black&&Chess[x-1][y]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==black&&Chess[x-4][y-4]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]==black&&Chess[x][y-4]==NONE&&Chess[x][y+1]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==black&&Chess[x+4][y-4]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==black&&Chess[x+4][y+4]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]==black&&Chess[x][y+4]==NONE&&Chess[x][y-1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	else if((Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]==black&&Chess[x][y+4]!=black&&Chess[x][y-1]==NONE
		||Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]==black&&Chess[x][y-4]!=black&&Chess[x][y+1]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==black&&Chess[x-4][y-4]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==black&&Chess[x+4][y-4]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==black&&Chess[x+4][y+4]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	else if((Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==black&&Chess[x-4][y-4]!=black&&Chess[x+1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==black&&Chess[x+4][y+4]!=black&&Chess[x-1][y-1]==NONE)
		&&(Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==black&&Chess[x+4][y-4]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
///////////////////////////////另一四四有界无界禁手///////////////////////////////////////////////////////////////
	else if((Chess[x-1][y]==black&&Chess[x-2][y]==black&&Chess[x-3][y]!=black&&Chess[x+1][y]==black&&Chess[x+2][y]==NONE
		||Chess[x+1][y]==black&&Chess[x+2][y]==black&&Chess[x+3][y]!=black&&Chess[x-1][y]==black&&Chess[x-2][y]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==black&&Chess[x-4][y-4]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]==black&&Chess[x][y-4]==NONE&&Chess[x][y+1]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==black&&Chess[x+4][y-4]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==black&&Chess[x+4][y+4]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]==black&&Chess[x][y+4]==NONE&&Chess[x][y-1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	else if((Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]!=black&&Chess[x][y+1]==black&&Chess[x][y+2]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]!=black&&Chess[x][y-1]==black&&Chess[x][y-2]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==black&&Chess[x-4][y-4]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==black&&Chess[x+4][y-4]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==black&&Chess[x+4][y+4]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	else if((Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]!=black&&Chess[x+1][y+1]==black&&Chess[x+2][y+2]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]!=black&&Chess[x-1][y-1]==black&&Chess[x-2][y-2]==NONE)
		&&(Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==black&&Chess[x+4][y-4]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==black&&Chess[x-4][y+4]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	///////////////////////////////另一四四有界无界禁手///////////////////////////////////////////////////////////////
	else if((Chess[x-1][y]==black&&Chess[x-2][y]==black&&Chess[x-3][y]!=black&&Chess[x+1][y]==black&&Chess[x+2][y]==NONE
		||Chess[x+1][y]==black&&Chess[x+2][y]==black&&Chess[x+3][y]!=black&&Chess[x-1][y]==black&&Chess[x-2][y]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]!=black&&Chess[x+1][y+1]==black&&Chess[x+2][y+2]==NONE
		||Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]!=black&&Chess[x][y+1]==black&&Chess[x][y+2]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]!=black&&Chess[x-1][y+1]==black&&Chess[x-2][y+2]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]!=black&&Chess[x-1][y-1]==black&&Chess[x-2][y-2]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]!=black&&Chess[x][y-1]==black&&Chess[x][y-2]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]!=black&&Chess[x+1][y-1]==black&&Chess[x+2][y-2]==NONE))
	{
	return 3;
	}
	else if((Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]!=black&&Chess[x][y+1]==black&&Chess[x][y+2]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]!=black&&Chess[x][y-1]==black&&Chess[x][y-2]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]!=black&&Chess[x+1][y+1]==black&&Chess[x+2][y+2]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]!=black&&Chess[x-1][y+1]==black&&Chess[x-2][y+2]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]!=black&&Chess[x-1][y-1]==black&&Chess[x-2][y-2]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]!=black&&Chess[x+1][y-1]==black&&Chess[x+2][y-2]==NONE))
	{
	return 3;
	}
	else if((Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]!=black&&Chess[x+1][y+1]==black&&Chess[x+2][y+2]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]!=black&&Chess[x-1][y-1]==black&&Chess[x-2][y-2]==NONE)
		&&(Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]!=black&&Chess[x-1][y+1]==black&&Chess[x-2][y+2]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]!=black&&Chess[x+1][y-1]==black&&Chess[x+2][y-2]==NONE))
	{
	return 3;
	}
//////////////////////三四有界无界禁手/////////////////////////////////////////////////////
    else if((Chess[x-1][y]==black&&Chess[x-2][y]==black&&Chess[x-3][y]==black&&Chess[x-4][y]!=black&&Chess[x+1][y]==NONE
		||Chess[x+1][y]==black&&Chess[x+2][y]==black&&Chess[x+3][y]==black&&Chess[x+4][y]!=black&&Chess[x-1][y]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]==NONE&&Chess[x][y+1]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]==NONE&&Chess[x][y-1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==NONE&&Chess[x+1][y-1]==NONE))
		{
	return 3;
	}
	else if((Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]==black&&Chess[x][y-4]!=black&&Chess[x][y+1]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]==black&&Chess[x][y+4]!=black&&Chess[x][y-1]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	else if((Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==black&&Chess[x-4][y-4]!=black&&Chess[x+1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==black&&Chess[x+4][y+4]!=black&&Chess[x-1][y-1]==NONE)
		&&(Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	//////////////////////另一三四有界无界禁手/////////////////////////////////////////////////////
	else if((Chess[x-1][y]==black&&Chess[x-2][y]==black&&Chess[x-3][y]!=black&&Chess[x+1][y]==black&&Chess[x+2][y]==NONE
		||Chess[x+1][y]==black&&Chess[x+2][y]==black&&Chess[x+3][y]!=black&&Chess[x-1][y]==black&&Chess[x-2][y]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]==NONE&&Chess[x][y+1]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]==NONE&&Chess[x][y-1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	else if((Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]!=black&&Chess[x][y+1]==black&&Chess[x][y+2]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]!=black&&Chess[x][y-1]==black&&Chess[x][y-2]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]==NONE&&Chess[x+1][y+1]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]==NONE&&Chess[x-1][y-1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
	else if((Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]!=black&&Chess[x+1][y+1]==black&&Chess[x+2][y+2]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]!=black&&Chess[x-1][y-1]==black&&Chess[x-2][y-2]==NONE)
		&&(Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]==NONE&&Chess[x-1][y+1]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]==NONE&&Chess[x+1][y-1]==NONE))
	{
	return 3;
	}
		//////////////////////另一三四有界无界禁手/////////////////////////////////////////////////////
	else if((Chess[x-1][y]==black&&Chess[x-2][y]==black&&Chess[x-3][y]!=black&&Chess[x+1][y]==black&&Chess[x+2][y]==NONE
		||Chess[x+1][y]==black&&Chess[x+2][y]==black&&Chess[x+3][y]!=black&&Chess[x-1][y]==black&&Chess[x-2][y]==NONE)
		&&(Chess[x-1][y-1]==black&&Chess[x-2][y-2]==NONE&&Chess[x+1][y+1]==black&&Chess[x+2][y+2]==NONE
		||Chess[x][y-1]==black&&Chess[x][y-2]==NONE&&Chess[x][y+1]==black&&Chess[x][y+2]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==NONE&&Chess[x-1][y+1]==black&&Chess[x-2][y+2]==NONE))
    {
	return 3;
	}
	else if((Chess[x][y-1]==black&&Chess[x][y-2]==black&&Chess[x][y-3]!=black&&Chess[x][y+1]==black&&Chess[x][y+2]==NONE
		||Chess[x][y+1]==black&&Chess[x][y+2]==black&&Chess[x][y+3]!=black&&Chess[x][y-1]==black&&Chess[x][y-2]==NONE)
		&&(Chess[x-1][y]==black&&Chess[x-2][y]==NONE&&Chess[x+1][y]==black&&Chess[x+2][y]==NONE
		||Chess[x-1][y-1]==black&&Chess[x-2][y-2]==NONE&&Chess[x+1][y+1]==black&&Chess[x+2][y+2]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==NONE&&Chess[x-1][y+1]==black&&Chess[x-2][y+2]==NONE))
    {
	return 3;
	}
	else if((Chess[x-1][y-1]==black&&Chess[x-2][y-2]==black&&Chess[x-3][y-3]!=black&&Chess[x+1][y+1]==black&&Chess[x+2][y+2]==NONE
		||Chess[x+1][y+1]==black&&Chess[x+2][y+2]==black&&Chess[x+3][y+3]!=black&&Chess[x-1][y-1]==black&&Chess[x-2][y-2]==NONE)
		&&(Chess[x-1][y]==black&&Chess[x-2][y]==NONE&&Chess[x+1][y]==black&&Chess[x+2][y]==NONE
		||Chess[x][y-1]==black&&Chess[x][y-2]==NONE&&Chess[x][y+1]==black&&Chess[x][y+2]==NONE
		||Chess[x+1][y-1]==black&&Chess[x+2][y-2]==NONE&&Chess[x-1][y+1]==black&&Chess[x-2][y+2]==NONE))
    {
	return 3;
	}
	else if((Chess[x+1][y-1]==black&&Chess[x+2][y-2]==black&&Chess[x+3][y-3]!=black&&Chess[x-1][y+1]==black&&Chess[x-2][y+2]==NONE
		||Chess[x-1][y+1]==black&&Chess[x-2][y+2]==black&&Chess[x-3][y+3]!=black&&Chess[x+1][y-1]==black&&Chess[x+2][y-2]==NONE)
		&&(Chess[x-1][y]==black&&Chess[x-2][y]==NONE&&Chess[x+1][y]==black&&Chess[x+2][y]==NONE
		||Chess[x][y-1]==black&&Chess[x][y-2]==NONE&&Chess[x][y+1]==black&&Chess[x][y+2]==NONE
		||Chess[x-1][y-1]==black&&Chess[x-2][y-2]==NONE&&Chess[x+1][y+1]==black&&Chess[x+2][y+2]==NONE))
    {
	return 3;
	}
	forbid1();
}
