#include<all.h>
void register_username(char *s,int *p)
{ 
	int i=0;
	int judge=0; 
	int length;
	char t,ss[2]={'\0'}; 
	int x=201,y=100;
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
                    line(x+15*i,y+1,x+15*i,y+59);//�ڸǹ��
                    setcolor(CYAN);
                    settextstyle(1,0,3);
                    outtextxy(x+ i * 15, y+1 + 10, ss);//���t�ַ�
                    i++;
                    setcolor(WHITE);
                    line(x + i * 15, y+1, x + i * 15, y+59);
                    strcat(s,ss);
                }
            
        		else if (t == '\b' && i > 0)//�˸��
                {
                	setcolor(LIGHTGRAY);
                    line(x+15*i,y+1,201+15*i,y+59);//�ڸǹ��
                    i--;//����һ������
                    setfillstyle(1,LIGHTGRAY);
                    bar(x + i * 15, y, x + 15 + i * 15, y+60);//�ڸ�����
                    setcolor(WHITE);
                    line(x + i * 15, y+1, x + i * 15, y+59);//���ƹ��
                    *(s+length-1)= '\0';
                    *(s+length) = '\0';//�ַ���ĩβɾ�� 
                }
            }	
	}
	*p=i;
	return;
}
void register_password(char *s,int *p)
{ 
	int i=0;
	int judge=0; 
	int length;
	char t,ss[2]={'\0'}; 
	int x=201,y=200;
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
                    line(x+15*i,y+1,x+15*i,y+59);//�ڸǹ��
                    setcolor(CYAN);
                    settextstyle(1,0,3);
                    outtextxy(x+ i * 15, y+1 + 10, ss);//���t�ַ�
                    i++;
                    setcolor(WHITE);
                    line(x + i * 15, y+1, x + i * 15, y+59);
                    strcat(s,ss);
                }
            
        		else if (t == '\b' && i > 0)//�˸��
                {
                	setcolor(LIGHTGRAY);
                    line(x+15*i,y+1,201+15*i,259);//�ڸǹ��
                    i--;//����һ������
                    setfillstyle(1,LIGHTGRAY);
                    bar(x + i * 15, y, x + 15 + i * 15, y+60);//�ڸ�����
                    setcolor(WHITE);
                    line(x + i * 15, y+1, x + i * 15, y+59);//���ƹ��
                    *(s+length-1)= '\0';
                    *(s+length) = '\0';//�ַ���ĩβɾ�� 
                }
            }	
	}
	*p=i;
	return;
}
void register_repassword(char *s,int *p)
{ 
	int i=0;
	int judge=0; 
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
                    line(x+15*i,y+1,x+15*i,y+59);//�ڸǹ��
                    setcolor(CYAN);
                    settextstyle(1,0,3);
                    outtextxy(x+ i * 15, y+1 + 10, ss);//���t�ַ�
                    i++;
                    setcolor(WHITE);
                    line(x + i * 15, y+1, x + i * 15, y+59);
                    strcat(s,ss);
                }
            
        		else if (t == '\b' && i > 0)//�˸��
                {
                	setcolor(LIGHTGRAY);
                    line(x+15*i,y+1,201+15*i,y+59);//�ڸǹ��
                    i--;//����һ������
                    setfillstyle(1,LIGHTGRAY);
                    bar(x + i * 15, y, x + 15 + i * 15, y+60);//�ڸ�����
                    setcolor(WHITE);
                    line(x + i * 15, y+1, x + i * 15, y+59);//���ƹ��
                    *(s+length-1)= '\0';
                    *(s+length) = '\0';//�ַ���ĩβɾ�� 
                }
            }	
	}
	*p=i;
	return;
}
void user_register()
{
	int i=0;
	int judge_register=0;//�ж��Ƿ��ظ�ע�� 
	int judge=0; 
	struct student_register_information stu[10]={0};
	int i1=0,i2=0,i3=0;
	unsigned long time=4000;
	int gd=VGA,gm=VGAHI; 
	char username[100]={0};
	char password[100]={0};
	char repassword[100]={0};
	FILE *fp;
	int judge1=0,judge2=0,judge3=0;//�����ж��Ƿ�ʵ�� 
	if((fp=fopen("data\\zhuce.txt","rt+"))==NULL)
	{
		setfillstyle(1,RED);
		bar(100,100,200,200);
	} 
	fseek(fp,0,0);
	for(i=0;i<10;i++)
	{
		fscanf(fp,"%s%s",stu[i].stu_username,stu[i].stu_password);//��ȡ�����ļ������� 
	}
	initgraph(&gd,&gm,"C:\\BORLANDC\\bgi");
	cleardevice();
	setbkcolor(WHITE);  
	delay(50);
	draw_page_close();
	puthz(120,120,"�˺�",32,32,'K',CYAN);
	setfillstyle(1,LIGHTGRAY);
	bar(200,100,530,160);
	setcolor(CYAN);
	rectangle(199,99,531,161);
	puthz(120,220,"����",32,32,'K',CYAN);
	setfillstyle(1,LIGHTGRAY);
	bar(200,200,530,260);
	setcolor(CYAN);
	rectangle(199,199,531,261);
	puthz(30,320,"�ٴ���������",24,24,'K',CYAN);
	setfillstyle(1,LIGHTGRAY);
	bar(200,300,530,360);
	setcolor(CYAN);
	rectangle(199,299,531,361);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,65,36);//������Ϊx-5����Ϊy-10����Ϊ��+70����Ϊ��+50 
	//output_hanzi(5,10,"����",2,CYAN
	puthz(0,0,"����",32,32,'K',CYAN);
	//output_hanzi(5,420,"ע��",2,CYAN); 
	puthz(0,420,"ע��",32,32,'K',CYAN);
	setcolor(CYAN);//���û�����ɫ 
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);//����ֱ�߸�ʽ 
	line(0,460,80,460);
	i1=0;
	i2=0;
	i3=0;
	mouseinit(); 
	while(1)
	{
		if(judge==0&&time<8000)//����delay��������ʵ�ֹ����˸ʱ��������ƶ�
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
		
		
		if(mouse_press(0,0,70,50)==1)//���� 
		{
			closegraph();
			menu();
		}
		//�˺����� 
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
		//�������� 
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
		//�����ٴ����� 
		if(mouse_press(200,300,530,360)==1)
		{
			setcolor(WHITE);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			line(201+15*i3,301,201+15*i3,359);
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
			line(201+15*i3,301,201+15*i3,359);
			delay(50); 
		}
		//ע�� 
		if(mouse_press(0,400,60,480)==1)
		{
			 if(strcmp(password,repassword)==0) 
			{
				for(i=0;i<100;i++)
				{
					if(strcmp(stu[i].stu_username,username)==0)
					{
						judge_register=1;
					}
				}
				if(judge_register==0)
				{
					fseek(fp,0,SEEK_END);
					fprintf(fp,"%s %s\n",username,password);
					setfillstyle(1,LIGHTBLUE);
					bar(260,200,400,280);
					puthz(270,230,"ע��ɹ�",24,30,'H',CYAN);
					delay(1000);
					menu();
				}
				if(judge_register==1)
				{
					setfillstyle(1,LIGHTBLUE);
					bar(260,200,400,280);
					puthz(270,230,"�˺��ظ�",24,30,'H',CYAN);
					delay(1000);
					user_register(); 
				}
				
			}
			if(strcmp(password,repassword)!=0)
			{
					setfillstyle(1,LIGHTBLUE);
					bar(260,200,430,280);
					puthz(270,230,"���벻һ��",24,30,'H',CYAN);
					delay(100);
					user_register();
			}
		}
		if(mouse_press(615,0,640,24)==1)
		{
			exit(0);
		}
		
	}
	fclose(fp); 
}


