// #include <vector>
// #include <math.h>
// using namespace std;

// vector<unsigned char> buffer;

// int imageSide = 2048; // the width of the surface

// struct Point2Di
// {
//     int x;
//     int y;
//     Point2Di(const int &x, const int &y): x(x), y(y){}
//     Point2Di(){}

// };

// void drawLine(const Point2Di &p0, const Point2Di &p1)
// {
//     int dx = p1.x - p0.x;
//     int dy = p1.y - p0.y;

//     int dLong = abs(dx);
//     int dShort = abs(dy);

//     int offsetLong = dx > 0 ? 1 : -1;
//     int offsetShort = dy > 0 ? imageSide : -imageSide;

//     if(dLong < dShort)
//     {
//         swap(dShort, dLong);
//         swap(offsetShort, offsetLong);
//     }
    
//     int error = 2 * dShort - dLong;
//     int index = p0.y*imageSide + p0.x;
//     const int offset[] = {offsetLong, offsetLong + offsetShort};
//     const int abs_d[]  = {2*dShort, 2*(dShort - dLong)};
//     for(int i = 0; i <= dLong; ++i)
//     {
//         buffer[index] = 255;  // or a call to your painting method
//         const int errorIsTooBig = error >= 0;
//         index += offset[errorIsTooBig];
//         error += abs_d[errorIsTooBig];
//     }
// }
// C++ program to implement onClick
// functionality in OpenGL to draw
// a circle using polar coordinates
// and midpoint algorithm
// C-program for circle drawing 
// using Bresenham’s Algorithm 
// in computer-graphics 


//#include <stdio.h> 
// #include <direct.h> 
// #include <graphics.h> 

// // Function to put pixels 
// // at subsequence points 
// void drawCircle(int xc, int yc, int x, int y) 
// { 
//     putpixel(xc+x, yc+y, RED); 
//     putpixel(xc-x, yc+y, RED); 
//     putpixel(xc+x, yc-y, RED); 
//     putpixel(xc-x, yc-y, RED); 
//     putpixel(xc+y, yc+x, RED); 
//     putpixel(xc-y, yc+x, RED); 
//     putpixel(xc+y, yc-x, RED); 
//     putpixel(xc-y, yc-x, RED); 
// } 

// // Function for circle-generation 
// // using Bresenham's algorithm 
// void circleBres(int xc, int yc, int r) 
// { 
//     int x = 0, y = r; 
//     int d = 3 - 2 * r; 
//     drawCircle(xc, yc, x, y); 
//     while (y >= x) 
//     { 
//         // for each pixel we will 
//         // draw all eight pixels 
        
//         x++; 

//         // check for decision parameter 
//         // and correspondingly 
//         // update d, x, y 
//         if (d > 0) 
//         { 
//             y--; 
//             d = d + 4 * (x - y) + 10; 
//         } 
//         else
//             d = d + 4 * x + 6; 
//         drawCircle(xc, yc, x, y); 
//         delay(50); 
//     } 
// } 


// // Driver code 
// int main() 
// { 
//     int xc = 50, yc = 50, r = 30; 
//     int gd = DETECT, gm; 
//     initgraph(&gd, &gm, ""); // initialize graph 
//     circleBres(xc, yc, r); // function call 
//     return 0; 
// } 


//C++ Implementation for drawing line 
// #include <graphics.h> 
  
// // driver code 
// int main() 
// { 
//     // gm is Graphics mode which is a computer display 
//     // mode that generates image using pixels. 
//     // DETECT is a macro defined in "graphics.h" header file 
//     int gd = DETECT, gm; 
  
//     // initgraph initializes the graphics system 
//     // by loading a graphics driver from disk 
//     initgraph(&gd, &gm, ""); 
  
//     // line for x1, y1, x2, y2 
//     line(150, 150, 450, 150); 
  
//     // line for x1, y1, x2, y2 
//     line(150, 200, 450, 200); 
  
//     // line for x1, y1, x2, y2 
//     line(150, 250, 450, 250); 

//     circle(250,50,50);
  
//     getch(); 
  
//     // closegraph function closes the graphics 
//     // mode and deallocates all memory allocated 
//     // by graphics system . 
//     closegraph(); 
// }

/*BRESENHAAM ALGORITHM FOR LINE DRAWING*/
#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<direct.h>
//#include <filesystem>

using namespace std;
void bhm_line(int,int,int,int,int);
int main()
{
 int ghdriver=DETECT,ghmode,errorcode,x1,x2,y1,y2,x3,y3;
 initgraph(&ghdriver,&ghmode,"..\\bgi");
 errorcode = graphresult();
 if(errorcode !=grOk)
 {
  cout<<"Graphics error:%s\n"<<grapherrormsg(errorcode);
  cout<<"Press any key to halt:";
  getch();
  exit(1);
 }
system("cls");
 cout<<"Enter the coordinates (x1,y1): ";
 cin>>x1>>y1;
 cout<<"Enter the coordinates (x2,y2): ";
 cin>>x2>>y2;
  cout<<"Enter the coordinates (x2,y2): ";
 cin>>x3>>y3;
 bhm_line(x1,y1,x2,y2,WHITE);
 bhm_line(x2,y2,x3,y3,WHITE);
 getch();
}
void bhm_line(int x1,int y1,int x2,int y2,int c)
{
 int x,y,dx,dy,dx1,dy1,px,py,xe,ye,i;
 dx=x2-x1;
 dy=y2-y1;
 dx1=fabs(dx);
 dy1=fabs(dy);
 px=2*dy1-dx1;
 py=2*dx1-dy1;
 if(dy1<=dx1)
 {
  if(dx>=0)
  {
   x=x1;
   y=y1;
   xe=x2;
  }
  else
  {
   x=x2;
   y=y2;
   xe=x1;
  }
  putpixel(x,y,c);
  for(i=0;x<xe;i++)
  {
   x=x+1;
   if(px<0)
   {
    px=px+2*dy1;
   }
   else
   {
    if((dx<0 && dy<0) || (dx>0 && dy>0))
    {
     y=y+1;
    }
    else
    {
     y=y-1;
    }
    px=px+2*(dy1-dx1);
   }
   delay(10);
   putpixel(x,y,c);
  }
 }
 else
 {
  if(dy>=0)
  {
   x=x1;
   y=y1;
   ye=y2;
  }
  else
  {
   x=x2;
   y=y2;
   ye=y1;
  }
  putpixel(x,y,c);
  for(i=0;y<ye;i++)
  {
   y=y+1;
   if(py<=0)
   {
    py=py+2*dx1;
   }
   else
   {
    if((dx<0 && dy<0) || (dx>0 && dy>0))
    {
     x=x+1;
    }
    else
    {
     x=x-1;
    }
    py=py+2*(dx1-dy1);
   }
   delay(10);
   putpixel(x,y,c);
  }
 }
}
