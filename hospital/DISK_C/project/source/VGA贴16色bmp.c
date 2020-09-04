#include<stdio.h>
#include<graphics.h>
int putbmp(int x, int y, char *s);//s为bmp路径
int putbmp(int x, int y, char *s)
{
    FILE *fp;
    long begin, tcolor;
    unsigned char color[256],k;
	unsigned int i,j,w,h;                
    if ((fp = fopen(s, "rb")) == NULL)
    {
        return 1;
    }
    fseek(fp, 10l, 0);
    fread(&begin, 4, 1, fp);
    fseek(fp, 18l, 0);
    fread(&w, 2, 1, fp);
    fread(&h, 2, 1, fp);
    fread(&h, 2, 1, fp);
    fseek(fp, 28l, 0);
    fread(color, 2, 1, fp);
    if (color[0] != 8)
    {
        fclose(fp);
        return 2;
    }
    fseek(fp, 54l, 0);
    for (i = 0; i < 256; i++)
    {
        fread(&tcolor, 4, 1, fp);
        switch (tcolor)
        {
        case 0:
            color[i] = 0;
            break;
        case 0xA8:
            color[i] = 1;
            break;
        case 0XA800:
            color[i] = 2;
            break;
        case 0XA8A8:
            color[i] = 3;
            break;
        case 0XA80000:
            color[i] = 4;
            break;
        case 0XA800A8:
            color[i] = 5;
            break;
        case 0XA85400:
            color[i] = 6;
            break;
        case 0XA8A8A8:
            color[i] = 7;
            break;
        case 0X545454:
            color[i] = 8;
            break;
        case 0X5454FC:
            color[i] = 9;
            break;
        case 0X54FC54:
            color[i] = 10;
            break;
        case 0X54FCFC:
            color[i] = 11;
            break;
        case 0XFC5454:
            color[i] = 12;
            break;
        case 0XFC54FC:
            color[i] = 13;
            break;
        case 0XFCFC54:
            color[i] = 14;
            break;
        case 0XFFFFFF:
            color[i] = 15;
            break;
        default:
            color[i] = 0;
        }
    }
    for (i = 0; i < h; i++)
    {
        fseek(fp, begin + (w + 3) / 4 * i * 4, 0);
        for (j = 0; j < w; j++)
        {
            fread(&k, 1, 1, fp);
            putpixel(x + j, y + h - i - 1, color[k]);
        }
    }
    fclose(fp);
    return 0;
}
