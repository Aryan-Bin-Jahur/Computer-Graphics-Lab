// C-program for circle drawing 
// using Bresenham’s Algorithm 
// in computer-graphics 
#include <iostream> 
#include <direct.h> 
#include <graphics.h> 
#include<conio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;


// Function to put pixels 
// at subsequence points 
void drawCircle(int xc, int yc, int x, int y) 
{ 
	putpixel(xc+x, yc+y, WHITE); 
	putpixel(xc-x, yc+y, WHITE); 
	putpixel(xc+x, yc-y, WHITE); 
	putpixel(xc-x, yc-y, WHITE); 
	putpixel(xc+y, yc+x, WHITE); 
	putpixel(xc-y, yc+x, WHITE); 
	putpixel(xc+y, yc-x, WHITE); 
	putpixel(xc-y, yc-x, WHITE); 
} 
void halfCircle(int xc, int yc, int x, int y) 
{ 
	putpixel(xc+x, yc+y, WHITE); 
	//putpixel(xc-x, yc+y, YELLOW); 
	putpixel(xc+x, yc-y, WHITE); 
	//putpixel(xc-x, yc-y, YELLOW); 
	putpixel(xc+y, yc+x, WHITE);  
	//putpixel(xc-y, yc+x, BLUE); 
	putpixel(xc+y, yc-x, WHITE); 
	//putpixel(xc-y, yc-x, GREEN); 
} 

// Function for circle-generation 
// using Bresenham's algorithm 
void circleBres(int xc, int yc, int r) 
{ 
	int x = 0, y = r; 
	int d = 3 - 2 * r; 

	drawCircle(xc, yc, x, y); 
	while (y >= x) 
	{ 
		// for each pixel we will 
		// draw all eight pixels 
		
		x++; 

		// check for decision parameter 
		// and correspondingly 
		// update d, x, y 
		if (d > 0) 
		{ 
			y--; 
			d = d + 4 * (x - y) + 10; 
		} 
		else
			d = d + 4 * x + 6; 

		drawCircle(xc, yc, x, y); 
		delay(10); 
	} 
} 

void halfCircleBres(int xc, int yc, int r) 
{ 
	int x = 0, y = r; 
	int d = 3 - 2 * r; 

	halfCircle(xc, yc, x, y); 
	while (y >= x) 
	{ 
		// for each pixel we will 
		// draw all eight pixels 
		
		x++; 

		// check for decision parameter 
		// and correspondingly 
		// update d, x, y 
		if (d > 0) 
		{ 
			y--; 
			d = d + 4 * (x - y) + 10; 
		} 
		else
			d = d + 4 * x + 6; 
		
		halfCircle(xc, yc, x, y); 
		delay(10); 
	} 
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


// Driver code 
int main() 
{ 
	//int xc = 300, yc = 250, r = 50; 
	int l,e,h,c;
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, ""); // initialize graph 

	cout<<"Enter the number of letters:"<<endl;
	cin>>l;
	while(l--){

	cout<<"Enter the number of edges:"<<endl;
	cin>>e;
	cout<<"Enter the number of half circle:"<<endl;
	cin>>h;
	cout<<"Enter the number of circle:"<<endl;
	cin>>c;
	while(e--){

		int x0,x1,y0,y1;
		cout<<"Enter cordinates of the line: ";
		cin>>x0>>y0>>x1>>y1;
		bhm_line(x0,y0,x1,y1,WHITE);


	}

	while(h--){

		int xc,yc,r;
		cout<<"Enter cordinates of the half-circle: ";
		cin>>xc>>yc>>r;
		halfCircleBres(xc, yc, r);


	}
	while(c--){

		int xc,yc,r;
		cout<<"Enter cordinates of the circle: ";
		cin>>xc>>yc>>r;
		circleBres(xc, yc, r);


	}

	}

	


	getch(); // function call 
	return 0; 
} 
