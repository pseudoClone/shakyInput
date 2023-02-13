#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	float coolArray[3][4], ratio, xpp[3];
	int i, j, k, n; // Iterators and order

	fputs("Enter the order:", stdout);
	scanf("%d", &n);

  
  
	/* Input for values */
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n + 1; ++j)
		{
			printf("Enter a[%d][%d]:", i,j);
			scanf("%f", &coolArray[i][j]);
		}
      
	}


	/* Actual Gauss Elimination */

	//Error checking
	for(i = 1; i <= n - 1; ++i)
	{
		if(coolArray[i][i] == 0)
		{
			printf("\nMathematical Error\n");
			return 0;
		}
		for(j = i + 1; j <= n; ++j)
		{
			ratio = coolArray[j][i]/coolArray[i][i];
			for(k = 1; k <= n + 1; ++k)
				coolArray[j][k] = coolArray[j][k] - ratio * coolArray[i][k];
		}
	}


	/* Obtaining solution by back substitution */

  
	xpp[n] = coolArray[n][n + 1] / coolArray[n][n];

	for(i = n - 1; i >= 1; --i)
	{
		xpp[i] = coolArray[i][n + 1];
		for(j = i + 1; j <= n; ++j)
			xpp[i] = xpp[i] - coolArray[i][j] * xpp[j];
		xpp[i] = xpp[i] / coolArray[i][i];
	}
	/* Diplay  */

	printf("\n");
	for(i = 1; i <= n; ++i)
		printf("%f\n", (xpp[i]));
  
	return 0;
}
