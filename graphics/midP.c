#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int main()
{
  int gd = DETECT, gm, r, xc,yc, x=0,y,p;

  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  clrscr();

  printf("Enter the radius or circle:");
  scanf("%d",&r);               /*  Getting the radius of circle*/
  y = r;
  p = 1 - r;                    /*  Init Value of decision parameter*/
  printf("Enter the centre of the circle:");
  scanf("%d%d", &xc, &yc);
  while(x <= y)
    { /*  Using symmetry to print it all!  */
      putpixel(x + xc, yc - y,15);
      putpixel(y + xc, yc - x,15);
      putpixel(y + xc, x + yc,15);
      putpixel(x + xc, y + yc,15);
      putpixel(xc - x, y + yc,15);
      putpixel(xc - y, x + yc,15);
      putpixel(xc - y, yc - x,15);
      putpixel(xc - x, yc - y,15);
      if(p < 0)
	{
	  p += 2*x + 1;
	  x++;
	  putpixel(x,y,15);
	}
      else
	{
	  p += 2*x + 1 - 2*y;
	  x++;
	  y--;
	}

    }
  getch();
  closegraph();
  return 0;
}
