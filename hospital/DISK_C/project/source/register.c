#include <graphics.h> 
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <stdlib.h>
#include<conio.h>
#include<dos.h>
#include <mouse.h> 
void user_register();//用户注册函数 
void register_username(char *s,int *p);
void register_password(char *s,int *p);
void register_repassword(char *s,int *p);
void register_username(char *s,int *p)
{ 
	static int i=0;
	int judge=0; 
	int length;
	char t,ss[2]={'\0'}; 
	int x=201,y=100;
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
                    line(x+15*i,y+1,201+15*i,y+59);//遮盖光标
                    i--;//减少一个字数
                    setfillstyle(1,LIGHTGRAY);
                    bar(x + i * 15, y, x + 15 + i * 15, y+60);//遮盖文字
                    setcolor(WHITE);
                    line(x + i * 15, y+1, x + i * 15, y+59);//绘制光标
                    *(s+length-1)= '\0';
                    *(s+length) = '\0';//字符串末尾删除 
                }
            }	
	}
	*p=i;
	return;
}
void register_password(char *s,int *p)
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
                    bar(x + i * 15, y, x + 15 + i * 15, y+60);//遮盖文字
                    setcolor(WHITE);
                    line(x + i * 15, y+1, x + i * 15, y+59);//绘制光标
                    *(s+length-1)= '\0';
                    *(s+length) = '\0';//字符串末尾删除 
                }
            }	
	}
	*p=i;
	return;
}
void register_repassword(char *s,int *p)
{ 
	static int i=0;
	int judge=0; 
	int length;
	char t,ss[2]={'\0'}; 
	int x=201,y=300;
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
                    line(x+15*i,y+1,201+15*i,y+59);//遮盖光标
                    i--;//减少一个字数
                    setfillstyle(1,LIGHTGRAY);
                    bar(x + i * 15, y, x + 15 + i * 15, y+60);//遮盖文字
                    setcolor(WHITE);
                    line(x + i * 15, y+1, x + i * 15, y+59);//绘制光标
                    *(s+length-1)= '\0';
                    *(s+length) = '\0';//字符串末尾删除 
                }
            }	
	}
	*p=i;
	return;
}
void user_register()
{
	int i1=0,i2=0,i3=0;
	int judge=0;
	unsigned long time=4000;
	int gd=VGA,gm=VGAHI; 
	char username[100]={0};
	char password[100]={0};
	char repassword[100]={0};
	int judge1=0,judge2=0,judge3=0;//用来判断是否画实线 
	initgraph(&gd,&gm,"C:\\BORLANDC\\bgi");
	cleardevice();
	setbkcolor(WHITE);  
	delay(50);
	output_hanzi(130,120,"账号",1,CYAN);//150 200 
	setfillstyle(1,LIGHTGRAY);
	bar(200,100,530,160);//
	setcolor(CYAN);
	rectangle(199,99,531,161);
	output_hanzi(130,220,"密码",1,CYAN);
	setfillstyle(1,LIGHTGRAY);
	bar(200,200,530,260);
	setcolor(CYAN);
	rectangle(199,199,531,261);
	output_hanzi(60,320,"再次输入密码",1,CYAN);
	setfillstyle(1,LIGHTGRAY);
	bar(200,300,530,360);
	setcolor(CYAN);
	rectangle(199,299,531,361);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,70,50);//画框左为x-5，上为y-10，右为左+70，下为上+50 
	output_hanzi(5,10,"返回",2,CYAN);
	output_hanzi(5,420,"注册",2,CYAN); 
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
		if(mouse_press(200,100,530,160)==1)
		{
			setcolor(WHITE);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			line(201+15*i1,101,201+15*i1,159);
			delay(50);
			register_username(username,&i1);
			judge1=1; 
		}
		else if(judge1==1&&mousein(200,100,530,160)==1)
		{
			newmouse(&MouseX,&MouseY,&press);
			register_username(username,&i1);
		}
		else if(mouse_press_out(200,100,530,160)==1)
		{
			judge1=0;
			setcolor(LIGHTGRAY);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			line(201+15*i1,101,201+15*i1,159);
			delay(50);
		}
		//密码输入 
		if(mouse_press(200,200,530,260)==1)
		{
			setcolor(WHITE);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			line(201+15*i2,201,201+15*i2,259);
			register_password(password,&i2);
			judge2=1; 
		}
		else if(judge2==1&&mousein(200,200,530,260)==1)
		{
			newmouse(&MouseX,&MouseY,&press);
			register_password(password,&i2);
		}
		else if(mouse_press_out(200,200,530,260)==1)
		{
			judge2=0;
			setcolor(LIGHTGRAY);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			line(201+15*i2,201,201+15*i2,259);
			delay(50); 
		}
		//密码输入 
		if(mouse_press(200,300,530,360)==1)
		{
			setcolor(WHITE);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			line(201+15*i2,301,201+15*i2,359);
			register_repassword(repassword,&i3);
			judge3=1; 
		}
		else if(judge3==1&&mousein(200,300,530,360)==1)
		{
			newmouse(&MouseX,&MouseY,&press);
			register_repassword(repassword,&i3);
		}
		else if(mouse_press_out(200,300,530,360)==1)
		{
			judge3=0;
			setcolor(LIGHTGRAY);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			line(201+15*i2,301,201+15*i2,359);
			delay(50); 
		}
		//注册 
		if(mouse_press(0,400,60,480)==1)
		{
			if(strcmp(password,repassword)==0) 
			{
				register_success();
			}
		}
		
}

