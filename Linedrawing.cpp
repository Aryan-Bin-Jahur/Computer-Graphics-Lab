#include<stdio.h>  
#include<graphics.h>  
void drawline(int x0, int y0, int x1, int y1)  
{  
    int dx, dy, p, x, y;  
    dx=x1-x0;  
    dy=y1-y0;  
    x=x0;  
    y=y0;  
    p=2*dy-dx;  
    while(x<x1)  
    {  
        if(p>=0)  
        {   delay(20);
            putpixel(x,y,7);  
            y=y+1;  
            p=p+2*dy-2*dx;  
        }  
        else  
        {   delay(20);
            putpixel(x,y,7);  
            p=p+2*dy;}  
            x=x+1;  
        }  
}  
int main()  
{  
    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;  
    initgraph(&gdriver, &gmode, "..\\bgi");  
    error = graphresult();
 if(error !=grOk)
 {
  printf("Graphics error:%s\n",grapherrormsg(error));
  printf("Press any key to halt:");
  getch();
  exit(1);
 }
system("cls");


    printf("Enter co-ordinates of first point: ");  
    scanf("%d%d", &x0, &y0); 
    printf("Enter co-ordinates of second point: ");  
    scanf("%d%d", &x1, &y1);  
    drawline(x0, y0, x1, y1);  
    getch();
   // return 0;  
}  