#include<all.h>
int main()
{
    int page = 1;
    while(1)
    {
        switch(page)
        {
            case 1:
            page = menu();
            printf("%d",page);
            break;

            case 2:
            page = login();
            break;

            case 3:
            page = user_register();
            break;

            case 4:
            page = help();
            break;

            case 5:
            page = userscreen();
            break;

            case 6:
            page = yuyueguhao();
        }
    }
    
}
