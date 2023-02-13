#include <stdio.h>
#include <stdlib.h>


int recMul(int mulNum, int n)
{
	if(n == 0)
		return 1;
	return(mulNum * recMul(mulNum, n - 1 ));
}

int main(int argc, char *argv[])
{
	printf("\n%d\n", recMul(2,3));
	return 0;
}
