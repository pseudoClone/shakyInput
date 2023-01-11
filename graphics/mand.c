#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
void main()
{
 float xc,yc,rx,ry,x,y,p1o,p2o;
 int gd=DETECT;
 int gm;
 initgraph(&gd,&gm,"c:\\TURBOC3\\bgi");
 printf("Enter the major and minor radius");
 scanf("%f%f",&rx,&ry);
 xc=getmaxx()/2;
 yc=getmaxy()/2;
 x=0;
 y=ry;
// putpixel(xc,yc+ry);
// putpixel(xc,yc-ry);
 //initial decision parameter to R1
p1o=pow(ry,2)-(pow(rx,2)*ry)+(0.25*pow(rx,2));
 do{
 if(p1o<0)
 {
  x=x+1;
  p1o=p1o+2*pow(ry,2)*x +2*pow(ry,2)+pow(ry,2);
 }
 else
 {
  x=x+1;
  y--;
  p1o=p1o+2*pow(ry,2)*x+2*pow(ry,2)-2*pow(rx,2)*y+2*pow(rx,2)+pow(ry,2);
 }
 putpixel(xc+x,yc+y,15);
 putpixel(xc-x,yc-y,15);
 putpixel(xc-x,yc+y,15);
 putpixel(xc+x,yc-y,15);
 }while((2*pow(ry,2)*x) < (2*pow(rx,2)*y));
 //Parameter for region 2
  p2o=pow(ry,2)*pow((x+0.5),2)+pow(rx,2)*pow((y-1),2)-pow(rx,2)*pow(ry,2);
  while(y>0){
  if(p2o>0)
  {
   x=x;
   y=y-1;
   p2o=p2o-2*pow(rx,2)*y+ 2* pow(rx,2)+pow(rx,2);
  }
  else{
   x=x+1;
   y--;
   p2o=p2o+2*pow(ry,2)*x+2*pow(ry,2)-2*pow(rx,2)*y+2*pow(ry,2)+pow(rx,2);
  }
 putpixel(xc+x,yc+y,15);
 putpixel(xc-x,yc-y,15);
 putpixel(xc-x,yc+y,15);
 putpixel(xc+x,yc-y,15);
  }
  getch();
  closegraph();
}
