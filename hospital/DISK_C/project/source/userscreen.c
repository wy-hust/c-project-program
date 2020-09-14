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
	puthz(0,150,"∏ˆ»À–≈œ¢",24,30,'K',CYAN);
	puthz(0,200,"–ﬁ∏ƒ√‹¬Î",24,30,'K',CYAN);
	puthz(0,450,"ÕÀ≥ˆµ«¬º",24,30,'K',CYAN);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(DARKGRAY);
	//ª≠øÚ
	line(0,145,119,145);
	line(0,180,119,180); 
	line(119,145,119,180);
	//ª≠øÚ
	line(0,195,119,195);
	line(0,240,119,240); 
	line(119,195,119,240);
	//ª≠øÚ
	line(0,445,119,445);
	line(0,480,119,480); 
	line(119,445,119,480);
	setfillstyle(1,LIGHTGRAY);

	bar(180,40,330,200);
	puthz(200,60,"‘§‘º",48,60,'H',CYAN);
	puthz(200,130,"π“∫≈",48,60,'H',CYAN);

	bar(400,40,550,200);
	puthz(420,60,"Œ ’Ô",48,60,'H',CYAN);
	puthz(420,130,"◊…—Ø",48,60,'H',CYAN);

	bar(180,260,330,440);
	puthz(200,280,"Ω…∑—",48,60,'H',CYAN);
	puthz(200,350,"÷ß∏∂",48,60,'H',CYAN);
	
	bar(400,260,550,440);
	puthz(420,280,"“©∆∑",48,60,'H',CYAN);
	puthz(420,350,"≈‰ÀÕ",48,60,'H',CYAN);
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


		if (flag1==0&&mouse_press(180,40,330,200)==2)
		{
			flag1=1;
			setfillstyle(1,DARKGRAY);
			clrmous(MouseX,MouseY);
			bar(180,40,330,200);
			puthz(200,60,"‘§‘º",48,60,'H',CYAN);
			puthz(200,130,"π“∫≈",48,60,'H',CYAN);
		}
		else if (flag1==1&&mouse_press(180,40,330,200)!=2)
		{
			flag1=0;
			setfillstyle(1,LIGHTGRAY);
			clrmous(MouseX,MouseY);
			bar(180,40,330,200);
			puthz(200,60,"‘§‘º",48,60,'H',CYAN);
			puthz(200,130,"π“∫≈",48,60,'H',CYAN);
		}


		if (flag2==0&&mouse_press(400,40,550,200)==2)
		{
			flag2=1;
			setfillstyle(1,DARKGRAY);
			clrmous(MouseX,MouseY);
			bar(400,40,550,200);
			puthz(420,60,"Œ ’Ô",48,60,'H',CYAN);
			puthz(420,130,"◊…—Ø",48,60,'H',CYAN);
		}
		else if (flag2==1&&mouse_press(400,40,550,200)!=2)
		{
			flag2=0;
			setfillstyle(1,LIGHTGRAY);
			clrmous(MouseX,MouseY);
			bar(400,40,550,200);
			puthz(420,60,"Œ ’Ô",48,60,'H',CYAN);
			puthz(420,130,"◊…—Ø",48,60,'H',CYAN);
		}


		if (flag3==0&&mouse_press(180,260,330,440)==2)
		{
			flag3=1;
			setfillstyle(1,DARKGRAY);
			clrmous(MouseX,MouseY);
			bar(180,260,330,440);
			puthz(200,280,"Ω…∑—",48,60,'H',CYAN);
			puthz(200,350,"÷ß∏∂",48,60,'H',CYAN);
		}
		else if (flag3==1&&mouse_press(180,260,330,440)!=2)
		{
			flag3=0;
			setfillstyle(1,LIGHTGRAY);
			clrmous(MouseX,MouseY);
			bar(180,260,330,440);
			puthz(200,280,"Ω…∑—",48,60,'H',CYAN);
			puthz(200,350,"÷ß∏∂",48,60,'H',CYAN);
		}


		if (flag4==0&&mouse_press(400,260,550,440)==2)
		{
			flag4=1;
			setfillstyle(1,DARKGRAY);
			clrmous(MouseX,MouseY);
			bar(400,260,550,440);
			puthz(420,280,"“©∆∑",48,60,'H',CYAN);
			puthz(420,350,"≈‰ÀÕ",48,60,'H',CYAN);
		}
		else if (flag4==1&&mouse_press(400,260,550,440)!=2)
		{
			flag4=0;
			setfillstyle(1,LIGHTGRAY);
			clrmous(MouseX,MouseY);
			bar(400,260,550,440);
			puthz(420,280,"“©∆∑",48,60,'H',CYAN);
			puthz(420,350,"≈‰ÀÕ",48,60,'H',CYAN);
		}
		
		//‘§‘ºπ“∫≈
		if (mouse_press(180,40,330,200)==1)
		{
			closegraph();
			return 6;
		}
		
		
		
		
	}
}
