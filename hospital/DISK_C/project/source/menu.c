#include <graphics.h> 
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <mouse.h> 
#include <menu.h>
#include "hzk.h"
void help()
{
	
	int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"C:\\BORLANDC\\bgi");
	cleardevice();//清空屏幕 
	setbkcolor(WHITE);//设置背景色 
	mouseinit();//初始化鼠标 
	//output_ha(250,10,"帮助",2,DARKGRAY);
	setfillstyle(1,DARKGRAY);//设置填充颜色 
	bar(0,0,70,50);
	//output_ha(5,10,"返回",2,CYAN);
	//output_ha(50,50,"初始登录密码为账号后六位",2,CYAN);
	//output_ha(50,100,"第一次登录后请进行密码更改",2,CYAN);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,70,50)==1)//返回 
		{
			closegraph();
			menu();
		}
	}
}
void userkey(char *s,int *p)
{
	int i=0;
	int length;
	char t,ss[2]={'\0'}; 
	int x=201,y=300;
	i=*p;
	newmouse(&MouseX,&MouseY,&press);
	length=strlen(s);
	if (kbhit())
        {	
        	t=getch();
			if (t != '\n'
            && t != '\r'
            && t != ' '
            && t != 033)//Esc
            {
                if (t != '\b')
                {
                	ss[0]=t;
                	setcolor(LIGHTGRAY);
                    line(x+15*i,y+1,x+15*i,y+59);//遮盖光标
                    setcolor(CYAN);
                    settextstyle(1,0,3);
                    outtextxy(x+i * 15, y+1 + 10, "*");//输出t字符
                    i++;
                    setcolor(WHITE);
                    line(x +i * 15, y+1, x+ i * 15, y+59);
                    strcat(s,ss);
                }
            
        		else if (t == '\b' && i > 0)//退格键
                {
                	setcolor(LIGHTGRAY);
                    line(x+15*i,y+1,201+15*i,359);//遮盖光标
                    i--;//减少一个字数
                    setfillstyle(1,LIGHTGRAY);
                    bar(x +i * 15, 300, x +15 + i * 15, 360);//遮盖文字
                    setcolor(WHITE);
                    line(x +i * 15, 301, x +i * 15, 359);//绘制光标
                    *(s+length-1)= '\0';
                    *(s+length) = '\0';//字符串末尾删除 
                }
            }	
	}
	*p=i;
}
void login_username(char *s,int *p)
{ 
	static int i=0;
	int judge=0; 
	int length;
	char t,ss[2]={'\0'}; 
	int x=201,y=200;
	newmouse(&MouseX,&MouseY,&press);
	length=strlen(s);
	if (kbhit())
        {	
        	t=getch();
			if (t != '\n'
            && t != '\r'
            && t != ' '
            && t != 033)//Esc
            {
                if (t != '\b')
                {
                	ss[0]=t;
                	setcolor(LIGHTGRAY);
                    line(x+15*i,y+1,x+15*i,y+59);//遮盖光标
                    setcolor(CYAN);
                    settextstyle(1,0,3);
                    outtextxy(x+ i * 15, y+1 + 10, ss);//输出t字符
                    i++;
                    setcolor(WHITE);
                    line(x + i * 15, y+1, x + i * 15, y+59);
                    strcat(s,ss);
                }
            
        		else if (t == '\b' && i > 0)//退格键
                {
                	setcolor(LIGHTGRAY);
                    line(x+15*i,y+1,201+15*i,259);//遮盖光标
                    i--;//减少一个字数
                    setfillstyle(1,LIGHTGRAY);
                    bar(x + i * 15, 200, x + 15 + i * 15, 260);//遮盖文字
                    setcolor(WHITE);
                    line(x + i * 15, 201, x + i * 15, 259);//绘制光标
                    *(s+length-1)= '\0';
                    *(s+length) = '\0';//字符串末尾删除 
                }
            }	
	}
	*p=i;
	return;
}
void login()
{ 
	int i1=0,i2=0;
	int judge=0;
	unsigned long time=4000;
	int gd=VGA,gm=VGAHI; 
	char username[100]={0};
	char password[100]={0};
	int num[2]={0,0};
	int judge1=0,judge2=0;//用来判断是否画实线 
	initgraph(&gd,&gm,"C:\\BORLANDC\\bgi");
	cleardevice();
	putbmp(597,0,"c:\\project\\close.bmp"); 
	setbkcolor(WHITE);  
	delay(50);
	//output_ha(130,220,"账号",1,CYAN);//150 200 
	setfillstyle(1,LIGHTGRAY);
	bar(200,200,530,260);//
	setcolor(CYAN);
	rectangle(199,199,531,261);
	//output_ha(130,320,"密码",1,CYAN);
	setfillstyle(1,LIGHTGRAY);
	bar(200,300,530,360);
	setcolor(CYAN);
	rectangle(199,299,531,361);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,70,50);//画框左为x-5，上为y-10，右为左+70，下为上+50 
	//output_ha(5,10,"返回",2,CYAN);
	//output_ha(5,420,"登录",2,CYAN); 
	setcolor(CYAN);//设置画笔颜色 
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);//设置直线格式 
	line(0,460,80,460);
	mouseinit(); 
	while(1)
	{
		if(judge==0&&time<8000)//代替delay计数，以实现光标闪烁时鼠标自由移动
		{
			time++;
		}
		else if(judge==0&&time==8000)
		{
			judge=1;
		}
		if(judge==1&&time>0)
		{
			time--;
		}
		else if(judge==1&&time==0)
		{
			judge=0;
		}
		newmouse(&MouseX,&MouseY,&press);
		
		
		if(mouse_press(0,0,70,50)==1)//返回 
		{
			closegraph();
			menu();
		}
		//账号输入 
		if(mouse_press(200,200,530,260)==1)
		{
			setcolor(WHITE);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			line(201+15*i1,201,201+15*i1,259);
			delay(50);
			login_username(username,&i1);
			judge1=1; 
		}
		else if(judge1==1&&mousein(200,200,530,260)==1)
		{
			newmouse(&MouseX,&MouseY,&press);
			login_username(username,&i1);
		}
		else if(mouse_press_out(200,200,530,260)==1)
		{
			judge1=0;
			setcolor(LIGHTGRAY);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			line(201+15*i1,201,201+15*i1,259);
			delay(50);
		}
		//密码输入 
		if(mouse_press(200,300,530,360)==1)
		{
			setcolor(WHITE);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			line(201+15*i2,301,201+15*i2,359);
			userkey(password,&i2);
			judge2=1; 
		}
		else if(judge2==1&&mousein(200,300,530,360)==1)
		{
			newmouse(&MouseX,&MouseY,&press);
			userkey(password,&i2);
		}
		else if(mouse_press_out(200,300,530,360)==1)
		{
			judge2=0;
			setcolor(LIGHTGRAY);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			line(201+15*i2,301,201+15*i2,359);
			delay(50); 
		}
		//登录
		if(mouse_press(0,400,60,480)==1)
		{
			//if(strcmp(username,password)==0) 
			//
				setfillstyle(1,WHITE);
				bar(100,0,200,150);
				outtextxy(100, 0, username);
				outtextxy(100, 100, password);
			//}
		}
		if(mouse_press(597,0,640,47)==1)
		{
			exit(0);
		}
		
	}
	i1=0;
	i2=0; 
	
}
void menu()
{
	int x,y;
	char *s="华中科技大学校医院网上就诊";
	char *s1="登录";
	char *s2="注册";
	char *s3="帮助";
	char *s4="退出";
	int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"C:\\BORLANDC\\bgi");
	cleardevice();
	setbkcolor(WHITE);  
	delay(50);
	puthz(60,20,s,32,40,'K',CYAN);
	setfillstyle(1,CYAN);
	bar(145,250,215,300);//画框左为x-5，上为y-10，右为左+70，下为上+50 
	//output_ha(150,260,s1,2,DARKGRAY);
	bar(395,250,465,300);//画框左为x-5，上为y-10，右为左+70，下为上+50                          
	//output_ha(400,260,s2,2,DARKGRAY);
	bar(145,320,215,370);//画框左为x-5，上为y-10，右为左+70，下为上+50 
	//output_ha(150,330,s3,2,DARKGRAY);
	bar(395,320,465,370);//画框左为x-5，上为y-10，右为左+70，下为上+50 
	//output_ha(400,330,s4,2,DARKGRAY);
	putbmp(220,80,"c:\\project\\shizi.bmp");//贴图函数 
	putbmp(597,0,"c:\\project\\close.bmp"); 
	mouseinit();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(145,250,215,300)==1)//登录 
		{
			delay(100);
			closegraph();
			login();
		}
		if(mouse_press(395,250,465,300)==1)//退出 
		{
			delay(100);
			closegraph();
			user_register();
		}
		if(mouse_press(145,320,215,370)==1)//帮助 
		{
			delay(100);
			closegraph();
			help();
		}
		if(mouse_press(395,320,465,370)==1)//退出 
		{
			delay(100);
			closegraph();
			exit(0);
		}
		 
	}
	getch();
	
}
/*void output_hanzi(int x,int y,char *s,int times,int color)//在指定位置输出汉字 
{
	FILE *fp;
	char buffer[32];
	int m,n,i,j,k;
	unsigned char qh,wh;
	unsigned long offset;
	if ((fp=fopen("c:\\project\\hzk16F","rb"))==NULL)
	{ 
	printf("Can't open File,Wrong!");
	getch();
	closegraph(); 
	exit(0);
	}
	while(*s)
	{ 
	qh=*(s)-0xa0; 
	wh=*(s+1)-0xa0;
	offset=(94*(qh-1)+(wh-1))*32L; 
	fseek(fp,offset,SEEK_SET);
	fread(buffer,32,1,fp); 
	for (i=0;i<16;i++)
	for(n=0;n<times;n++)//times为放大倍数 
	for(j=0;j<2;j++)
	for(k=0;k<8;k++)
	for(m=0;m<times;m++)
	if (((buffer[i*2+j]>>(7-k))&0x1)!=NULL)
	putpixel(x+8*j*times+k*times+m,y+i*times+n,color);
	s+=2; 
	x+=15*times;
	}
	fclose(fp);
}*/ 

