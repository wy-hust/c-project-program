 #include <graphics.h> 
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <stdlib.h>
#include<conio.h>
#include<dos.h>
#include <mouse.h> 
void user_register();//�û�ע�ắ�� 
void user_register()
{
	int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"C:\\BORLANDC\\bgi");
	cleardevice();//�����Ļ 
	setbkcolor(WHITE);//���ñ���ɫ 
	mouseinit();//��ʼ����� 
	
}
