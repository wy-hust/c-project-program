#ifndef _register_h_
#define _register_h_
struct student_register_information
{
	char stu_username[100];
	char stu_password[100];
};
void register_username(char *s,int *p);
void register_password(char *s,int *p);
void register_repassword(char *s,int *p);
int user_register();
#endif
