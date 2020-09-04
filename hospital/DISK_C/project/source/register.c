 #include <graphics.h> 
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <stdlib.h>
#include<conio.h>
#include<dos.h>
#include <mouse.h> 
void user_register();//用户注册函数 
void user_register()
{
	int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"C:\\BORLANDC\\bgi");
	cleardevice();//清空屏幕 
	setbkcolor(WHITE);//设置背景色 
	mouseinit();//初始化鼠标 
	
}
