#include <stdio.h>
#include <stdlib.h>

int gcd(size_t n1, size_t n2)
{
	if(n2 == 0)
		return n1;
	return (gcd(n2, n1 % n2));
	
	/* return (n2 != 0) ? gcd(n2, n1 % n2) : n1; */
}


int main(int argc, char *argv[])
{
	size_t num_1, num_2;
	fputs("Enter the numbers for HCF: ", stdout);
	scanf("%d%d", &num_1, &num_2);
	printf("\n%d\n",gcd(num_1, num_2));
	return 0;
}
