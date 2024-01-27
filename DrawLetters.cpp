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
void rightHalfCircle(int xc, int yc, int x, int y) 
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

void leftHalfCircle(int xc, int yc, int x, int y) 
{ 
	//putpixel(xc+x, yc+y, WHITE); 
	putpixel(xc-x, yc+y, YELLOW); 
	//putpixel(xc+x, yc-y, WHITE); 
	putpixel(xc-x, yc-y, YELLOW); 
	//putpixel(xc+y, yc+x, WHITE);  
	putpixel(xc-y, yc+x, BLUE); 
	//putpixel(xc+y, yc-x, WHITE); 
	putpixel(xc-y, yc-x, GREEN); 
} 
void upperHalfCircle(int xc, int yc, int x, int y) 
{ 
	putpixel(xc+x, yc+y, WHITE); 
	putpixel(xc-x, yc+y, YELLOW); 
	//putpixel(xc+x, yc-y, WHITE); 
	//putpixel(xc-x, yc-y, YELLOW); 
	putpixel(xc+y, yc+x, WHITE);  
	putpixel(xc-y, yc+x, BLUE); 
	//putpixel(xc+y, yc-x, WHITE); 
	//putpixel(xc-y, yc-x, GREEN); 
} 
void lowerHalfCircle(int xc, int yc, int x, int y) 
{ 
	//putpixel(xc+x, yc+y, WHITE); 
	//putpixel(xc-x, yc+y, YELLOW); 
	putpixel(xc+x, yc-y, WHITE); 
	putpixel(xc-x, yc-y, YELLOW); 
	//putpixel(xc+y, yc+x, WHITE);  
	//putpixel(xc-y, yc+x, BLUE); 
	putpixel(xc+y, yc-x, WHITE); 
	putpixel(xc-y, yc-x, GREEN); 
} 

// Function for circle-generation 
// using Bresenham's algorithm 
void circleBres(int xc, int yc, int r,string str) 
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



		if(str=="c"){

		drawCircle(xc, yc, x, y); 
		delay(10);
		 }
		else if(str=="rc"){
            
            rightHalfCircle(xc,yc,x,y);
			delay(10);

		}
			else if(str=="uc"){
            
            upperHalfCircle(xc,yc,x,y);
			delay(10);

		}
			else if(str=="dc"){
            
            lowerHalfCircle(xc,yc,x,y);
			delay(10);

		}
			else if(str=="lc"){
            
            leftHalfCircle(xc,yc,x,y);
			delay(10);

		}
	} 
} 

// void rightHalfCircleBres(int xc, int yc, int r) 
// { 
// 	int x = 0, y = r; 
// 	int d = 3 - 2 * r; 

// 	rightHalfCircle(xc, yc, x, y); 
// 	while (y >= x) 
// 	{ 
// 		// for each pixel we will 
// 		// draw all eight pixels 
		
// 		x++; 

// 		// check for decision parameter 
// 		// and correspondingly 
// 		// update d, x, y 
// 		if (d > 0) 
// 		{ 
// 			y--; 
// 			d = d + 4 * (x - y) + 10; 
// 		} 
// 		else
// 			d = d + 4 * x + 6; 
		
// 		rightHalfCircle(xc, yc, x, y); 
// 		delay(10); 
// 	} 
// } 

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

		string str="start";

		cout<<"What do you want to enter for letter "<<l+1<<"? -"<<endl;
    
    
    while(str!="none"){

    	cout<<"For letter: "<<l+1<<"? -"<<endl;
    	cin>>str;


    if(str=="e"){
    	cout<<"Enter the number of edges:"<<endl;
    	cin>>e;

    	while(e--){

		int x0,x1,y0,y1;
		cout<<"Enter cordinates of the line: ";
		cin>>x0>>y0>>x1>>y1;
		bhm_line(x0,y0,x1,y1,WHITE);


	   }
    }
    else if(str=="rc"){
    	cout<<"Enter the number of right-half circle:"<<endl;
	cin>>h;
	while(h--){

		int xc,yc,r;
		cout<<"Enter cordinates of the right-half-circle: ";
		cin>>xc>>yc>>r;
		circleBres(xc, yc, r,"rc");


	}

    }

     else if(str=="lc"){
    	cout<<"Enter the number of left-half circle:"<<endl;
	cin>>h;
	while(h--){

		int xc,yc,r;
		cout<<"Enter cordinates of the left-half-circle: ";
		cin>>xc>>yc>>r;
		circleBres(xc, yc, r,"lc");


	}

    }

     else if(str=="uc"){
    	cout<<"Enter the number of upper-half-circle:"<<endl;
	cin>>h;
	while(h--){

		int xc,yc,r;
		cout<<"Enter cordinates of the upper-half-circle: ";
		cin>>xc>>yc>>r;
		circleBres(xc, yc, r,"uc");


	}

    }
     else if(str=="dc"){
    	cout<<"Enter the number of lower-half-circle:"<<endl;
	cin>>h;
	while(h--){

		int xc,yc,r;
		cout<<"Enter cordinates of the lower-half-circle: ";
		cin>>xc>>yc>>r;
		circleBres(xc, yc, r,"dc");


	}

    }




    else if(str=="c"){
    	cout<<"Enter the number of circle:"<<endl;
	cin>>c;
	while(c--){

		int xc,yc,r;
		cout<<"Enter cordinates of the circle: ";
		cin>>xc>>yc>>r;
		circleBres(xc, yc, r,"c");


	}
    }
    else
    	cout<<"invalid input"<<endl;
	
	
	
	

	}
	

	}

	


	getch(); // function call 
	return 0; 
} 
