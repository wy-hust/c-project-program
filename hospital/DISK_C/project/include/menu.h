#ifndef _menu_h_
#define _menu_h_
void output_hanzi(int x,int y,char *s,int times,int color);
int menu();//�˵�
int login();//��¼
int help();//����
int login_username(char *s,int *p);
void userkey();
int user_register();
void draw_page_close();
#endif
