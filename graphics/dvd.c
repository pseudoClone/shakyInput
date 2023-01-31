#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int main()
{
	int gd = DETECT, gm;
	char T = 't', B = 'b', R = 'r', L = 'l';

	int gx = getmaxx() , gy = getmaxy();

	int x = 0, y = 0, top = 60, right = 60, bottom = 60, left = 60;

	int x0 = gx - 60, y0 = gy - 60;

	if(abs(x - y) % gcd(x0, y0) == 0) {
	  //corner reached
	  if(abs(x - y) / gcd(x0, y0) % 2 == 0) {
	    printf("  %c  ", (((lcm(x0, y0) / y0) % 2 == 0) ? T : B));
	    printf("  %c  ", (((lcm(x0, y0) / x0) % 2 == 0) ? L : R));

	    printf(" %c ", T);
	    printf(" %c ", L);

	  } else {

	    printf("  %c  ", (((lcm(x0, y0) / y0) % 2 != 0) ? T : B));
	    printf("  %c  ", (((lcm(x0, x0) / y0) % 2 == 0) ? L : R));
	    
	  }
	  
	}
	

	
	getch();

	closegraph();
	
	return 0;
}
