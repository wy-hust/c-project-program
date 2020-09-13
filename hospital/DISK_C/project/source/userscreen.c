#include<all.h>
int userscreen()
{
	int gd=VGA,gm=VGAHI; 
	int flag1=0;
	int flag2=0;
	int flag3=0;
	int flag4=0;
	initgraph(&gd,&gm,"C:\\BORLANDC\\bgi");
	clrmous(MouseX,MouseY);
	cleardevice();
	setbkcolor(WHITE); 
	draw_page_close();
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,119,480);
	putbmp(0,0,"bmp\\user.bmp");
	puthz(0,150,"¸öÈËÐÅÏ¢",24,30,'K',CYAN);
	puthz(0,200,"ÐÞ¸ÄÃÜÂë",24,30,'K',CYAN);
	puthz(0,450,"ÍË³öµÇÂ¼",24,30,'K',CYAN);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(DARKGRAY);
	//»­¿ò
	line(0,145,119,145);
	line(0,180,119,180); 
	line(119,145,119,180);
	//»­¿ò
	line(0,195,119,195);
	line(0,240,119,240); 
	line(119,195,119,240);
	//»­¿ò
	line(0,445,119,445);
	line(0,480,119,480); 
	line(119,445,119,480);
	setfillstyle(1,LIGHTGRAY);

	bar(180,40,330,200);
	puthz(200,60,"Ô¤Ô¼",48,60,'H',CYAN);
	puthz(200,130,"¹ÒºÅ",48,60,'H',CYAN);

	bar(400,40,550,200);
	puthz(420,60,"ÎÊÕï",48,60,'H',CYAN);
	puthz(420,130,"×ÉÑ¯",48,60,'H',CYAN);

	bar(180,260,330,440);
	puthz(200,280,"½É·Ñ",48,60,'H',CYAN);
	puthz(200,350,"Ö§¸¶",48,60,'H',CYAN);
	
	bar(400,260,550,440);
	puthz(420,280,"Ò©Æ·",48,60,'H',CYAN);
	puthz(420,350,"ÅäËÍ",48,60,'H',CYAN);
	mouseinit();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(615,0,640,24)==1)
		{
			exit(0);
		}
		if(mouse_press(0,440,120,480)==1)
		{
			return 1;
		}
		if (mouse_press(180,40,330,200)==2)
		{
			flag1=1;
		}
		else if (mouse_press(180,40,330,200)!=2)
		{
			flag1=0;
		}
		if (flag1==0)
		{
			/* code */
		}
		
		
		
	}
}
