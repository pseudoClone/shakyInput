#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>



int i, gx , ymax;
int startx, starty;

int state=0;


void flower_draw(int i)
{
	setcolor(GREEN);
	line(gx / 2,ymax / 2, gx / 2, ymax / 2 + 100);

	setcolor(BROWN);
	setfillstyle(SOLID_FILL, YELLOW);

	fillellipse(gx / 2, ymax / 2,10 + 1.8 * i, 5 + .6 * i);
	fillellipse(gx / 2, ymax / 2, 5 + .6 * i, 10 + 1.8 * i);
	setcolor(BROWN);
	setfillstyle(SOLID_FILL , RED);
	fillellipse(gx / 2,ymax / 2, 5 + .6 * i, 5 + .6 * i);
}

void bee_draw(int i)
{
	startx += 2;
	starty += 7 * sin(i);

	setcolor(BROWN);
	setfillstyle(SOLID_FILL, BLUE);
	fillellipse(startx, starty, 12, 5);
	setcolor(BLUE);
	
	fillellipse(startx, starty, 5, 10 * (i % 2));
	fillellipse(startx + 8, starty - 3, 1, 1);
	fillellipse(startx + 8, starty + 3, 1, 1);

	line(startx + 9, starty - 2, startx + 11, starty - 5);
	line(startx + 9, starty + 2, startx + 11, starty + 5);
}

void main()
{
	int max, may, i, t;
	int gm = DETECT, gd;
	initgraph(&gm, &gd, "C:\\TURBOC3\\BGI");

	gx = getmaxx();
	ymax = getmaxy();

	startx = gx / 2 - 100;
	starty = ymax / 2;

	setbkcolor(WHITE);
	printf("START?");
	cleardevice();
	getch();

	for(i = 0;i < 20; ++i)
	{
		delay(120);
		cleardevice();
		flower_draw(i);
	}
	t = i;

	for(i = 0; startx + i < gx - 60; ++i)
	{
		delay(90);
		cleardevice();
		flower_draw(t);
		bee_draw(i);
		if(state == 0 && abs(startx-gx/2) < 10
		   && abs(starty - ymax / 2) < 15)
		{
			delay(2500);
			state=1;
		}
	}
	getch();
	closegraph();

}
