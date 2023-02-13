#include <stdio.h>
#include <stdlib.h>
void move(int disc_num, int source, int auxillary, int dest)
{
	if (disc_num > 1) {
		move(disc_num - 1, source, dest, auxillary);
		printf("Moved disk %d from peg %d to peg %d\n",disc_num, source, dest);
		move(disc_num - 1, auxillary, source, dest);
	} else {
		printf("Moved disk %d from peg %d to peg %d\n", disc_num, source, dest);
	}
}
int main(int argc, char **argv)
{
	size_t discNum;
	fputs("Enter disc number: ", stdout);
	scanf("%d", &discNum);
	move(discNum, 1,2,3);
	return 0;
}
