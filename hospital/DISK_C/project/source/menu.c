#include<all.h> 
void draw_page_close()
{
	setfillstyle(1,LIGHTGRAY);
	bar(616,0,640,24);
	putbmp(617,0,"bmp\\close.bmp");
	
}
int help()
{
	
	int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"C:\\BORLANDC\\bgi");
	cleardevice();//�����Ļ 
	setbkcolor(WHITE);//���ñ���ɫ 
	mouseinit();//��ʼ����� 
	puthz(250,10,"����",32,32,'K',CYAN);
	setfillstyle(1,DARKGRAY);//���������ɫ 
	bar(0,0,65,35);
	draw_page_close();
	puthz(0,0,"����",32,32,'K',CYAN);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,65,35)==1)//���� 
		{
			closegraph();
			return 1;
		}
		if(mouse_press(616,0,640,24)==1)//ֱ���˳� 
		{
			exit(0); 
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
	clrmous(MouseX,MouseY);
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
                    outtextxy(x+i * 15, y+1 + 10, "*");//���t�ַ�
                    i++;
                    setcolor(WHITE);
                    line(x +i * 15, y+1, x+ i * 15, y+59);
                    strcat(s,ss);
                }
            
        		else if (t == '\b' && i > 0)//�˸��
                {
                	setcolor(LIGHTGRAY);
                    line(x+15*i,y+1,201+15*i,359);//�ڸǹ��
                    i--;//����һ������
                    setfillstyle(1,LIGHTGRAY);
                    bar(x +i * 15, 300, x +15 + i * 15, 360);//�ڸ�����
                    setcolor(WHITE);
                    line(x +i * 15, 301, x +i * 15, 359);//���ƹ��
                    *(s+length-1)= '\0';
                    *(s+length) = '\0';//�ַ���ĩβɾ�� 
                }
            }	
	}
	*p=i;
}
int login_username(char *s,int *p)
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
                    bar(x + i * 15, 200, x + 15 + i * 15, 260);//�ڸ�����
                    setcolor(WHITE);
                    line(x + i * 15, 201, x + i * 15, 259);//���ƹ��
                    *(s+length-1)= '\0';
                    *(s+length) = '\0';//�ַ���ĩβɾ�� 
                }
            }	
	}
	*p=i;
	return;
}
/*void input(int x1,int y1,int x2,int y2, char *s, int max_len, int fp, int fn,int backcolor)
{
	char value;
	int length=strlen(s);
	int width=16;  //�ַ����
    int flag;
	line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, BLACK);//���ƹ��
	while(1)
	{
        int flag;
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press_out(x1,y1,x2,y2)==1)
        {
            s[length]='\0';
			line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, backcolor);	//���ǹ��
			break;
        }
        if(kbhit())
        {
            value=getch();
            if(value=='\n'||value=='\r') //�жϵ����»س�
            {
                s[length]='\0';
			    line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, backcolor);	//���ǹ��
			    break;
            }
		    else if(value=='\b')
		    {
			    clrmous(MouseX, MouseY);
                newmouse(&MouseX, &MouseY, &press);
                if(length==0) continue;
                line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, BLACK);	
			    bar(x1+5+width*(length-1), y1+3, x2, y2-3, backcolor);	//���ǹ������һ���ַ�
			    s[--length]='\0';
			    if(length+1<max_len) s[length+1]='\0';
			    line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, BLACK);  //���»��ƹ��
		    }
            //������ӿ�ͨ���������̬�޸Ĺ��ܣ�������
            /*else if(value==224)
            {
                value1=getch();
                if(value1==72||value1==80) continue;
                else if(value1==75) 
                else if(value1==77) 
            }
		    else if(length<max_len)
		    {
			    if(fn&&(value>'9'||value<'0')) continue; //�ж��Ƿ�Ҫ��ȫ����
                clrmous(MouseX, MouseY);
                newmouse(&MouseX, &MouseY, &press);
                line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, backcolor);	//���ǹ��
			    //�ж��Ƿ�Ϊ���룬����ǣ�����Ҫ����
                if(!fp) putEngletter(x1-4+width*length, y1+8, (int)(value), 2,2,BLACK);  //��ʾ�ַ�
			    else fill_circle(x1+16+width*length, (y1+y2)/2, 4,BLACK); //��ʾСԲ��
			    s[length++]=value;
			    line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, BLACK);	//���»��ƹ��
		    }
        }
	}
}*/
int login()
{ 
	struct student_register_information stu[10];
	int i;//���ڼ��� 
	int i1=0,i2=0;//���ڹ��Ļ滭 
	int judge=0;
	int namejudge=0;//���ڼ�¼�Ƿ���ڸ��û��� 
	unsigned long time=4000;
	int gd=VGA,gm=VGAHI; 
	char username[100]={0};
	char password[100]={0};
	int num[2]={0,0};
	int judge1=0,judge2=0;//�����ж��Ƿ�ʵ�� 
	FILE *fp;
	if((fp=fopen("data\\zhuce.txt","rt+"))==NULL)
	{
		setfillstyle(1,RED);
		bar(100,100,200,200);
	}
	initgraph(&gd,&gm,"C:\\BORLANDC\\bgi");
	cleardevice();//�����Ļ 
	setbkcolor(WHITE);  
	delay(50);
	for(i=0;i<10;i++)
	{
		fscanf(fp,"%s%s",stu[i].stu_username,stu[i].stu_password);
	}
	draw_page_close();
	puthz(120,220,"�˺�",32,32,'K',CYAN);
	setfillstyle(1,LIGHTGRAY);
	bar(200,200,530,260);//
	setcolor(CYAN);
	rectangle(199,199,531,261);
	puthz(120,320,"����",32,32,'K',CYAN);
	setfillstyle(1,LIGHTGRAY);
	bar(200,300,530,360);
	setcolor(CYAN);
	rectangle(199,299,531,361);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,70,40);
	//output_ha(5,10,"����",2,CYAN);
	puthz(0,0,"����",32,32,'K',CYAN);
	//output_ha(5,420,"��¼",2,CYAN); 
	puthz(0,420,"��¼",32,32,'K',CYAN);
	setcolor(CYAN);//���û�����ɫ 
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);//����ֱ�߸�ʽ 
	line(0,453,64,453);
	i1=0;
	i2=0;
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
		/*if(bioskey(1))
		{
			getch();
		}*/
		
		if(mouse_press(0,0,70,50)==1)//���� 
		{
			closegraph();
			//menu();
			return 1;
		}
		//�˺����� 
		if(mouse_press(200,200,530,260)==1)
		{
			setcolor(WHITE);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			line(201+15*i1,201,201+15*i1,259);
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
		//�������� 
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
		//��¼
		if(mouse_press(0,415,60,480)==1)
		{
			for(i=0;i<10;i++)
			{
				if(strcmp(username,stu[i].stu_username)==0&&strcmp(password,stu[i].stu_password)==0)
				{
					setfillstyle(1,LIGHTBLUE);
					bar(260,200,400,280);
					puthz(270,230,"��¼�ɹ�",24,30,'H',CYAN);
					namejudge=1; 
					delay(200);
					//closegraph();
					//userscreen();
					return 5;
				}
				if(strcmp(username,stu[i].stu_username)==0&&strcmp(password,stu[i].stu_password)!=0)
				{
					setfillstyle(1,LIGHTBLUE);
					bar(260,200,400,280);
					puthz(270,230,"�������",24,30,'H',CYAN);
					namejudge=1;
					delay(100);
					//login();
					return 2;
				 }
				if(strcmp(username,stu[i].stu_username)==0)
				{
					namejudge=1;
				 } 
			}
			if(judge==0)
			{
					setfillstyle(1,LIGHTBLUE);
					bar(260,200,440,280);
					puthz(270,230,"�û�������",24,30,'H',CYAN);
					delay(100);
					//login();
					return 2;
			}
		}
		if(mouse_press(615,0,640,24)==1)
		{
			exit(0);
		}
		
	}
	
}
int menu()
{
	int x,y;
	char *s="���пƼ���ѧУҽԺ���Ͼ���";
	char *s1="��¼";
	char *s2="ע��";
	char *s3="����";
	char *s4="�˳�";
	int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"C:\\BORLANDC\\bgi");
	cleardevice();
	setbkcolor(WHITE);  
	delay(50);
	puthz(60,20,s,32,40,'K',CYAN);
	setfillstyle(1,CYAN);
	bar(145,250,215,290);
	//output_ha(150,260,s1,2,DARKGRAY);
	puthz(145,250,s1,32,36,'K',BLUE);
	bar(395,250,465,290);                        
	puthz(395,250,s2,32,36,'K',BLUE);
	bar(145,320,215,360);
	puthz(145,320,s3,32,36,'K',BLUE);
	bar(395,320,465,360);
	puthz(395,320,s4,32,36,'K',BLUE);
	putbmp(220,80,"bmp\\shizi.bmp");//��ͼ���� 
	mouseinit();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(145,250,215,290)==1)//��¼ 
		{
			delay(100);
			closegraph();
			//login();
			return 2;
		}
		if(mouse_press(395,250,465,290)==1)//ע�� 
		{
			delay(100);
			closegraph();
			//user_register();
			return 3;
		}
		if(mouse_press(145,320,215,360)==1)//���� 
		{
			delay(100);
			closegraph();
			//help();
			return 4;
		}
		if(mouse_press(395,320,465,360)==1)//�˳� 
		{
			delay(100);
			closegraph();
			exit(0);
		}
		 
	}
	
}

