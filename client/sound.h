DWORD  WINAPI  sound(LPVOID  lparam)
{
	while(1)
	{
		if(play)
		{
			  if(switchsong==1)
			  {
				  PlaySound("Sound\\xianjian.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
			  }
			  else if(switchsong==2)
			  {
				  PlaySound(NULL,NULL,SND_FILENAME);
                  PlaySound("Sound\\music.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
			  }
			  else if(switchsong==3)
			  {
				   PlaySound(NULL,NULL,SND_FILENAME);
				   PlaySound("Sound\\run.wav",NULL,SND_FILENAME|SND_SYNC);
				   PlaySound("Sound\\gameover.wav",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
			  }
			  play=false;
		}
		Sleep(100);
	}
	return 0;
}