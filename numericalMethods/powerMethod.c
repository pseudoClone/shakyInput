#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  /* Variables */
  
  int i, j, k, n;
  float epsilon, arr[30][30], xpp[n], lamo, temp, X_NEW[n], lamn;
  
  printf("Enter the order of matrix equation:");
  scanf("%d", &n);

  printf("Enter tolerable error: ");
  scanf("%f", &epsilon);


  /* Getting the values */
  for(i = 1; i <= n; ++i)
    {
      for(j = 1; j <= n; ++j)
      {
	printf("Enter arr[%d][%d]:", i, j);
	scanf("%d", &arr[i][j]);
      }
    }
  getchar();
      

  /* Initial vector guess */
  for(i = 1; i <= n; ++i)
    scanf("%d", &xpp[i]);

  lamo = 1;

  
 prince:
  
  for(i = 1; i <= n; ++i)
    {
      temp = 0.0;
      for(j = 1; j <= n; ++j)
	temp += (arr[i][j] * xpp[j]);
      
      X_NEW[i] = temp;
    }

  /* Replace X with X_NEW */
  for(i = 1; i <= n; ++i)
    xpp[i] = X_NEW[i];

  
  /* Finding largest */
  lamn = fabs(xpp[1]);

  for(i = 2; i <= n; ++i)
    if(fabs(xpp[i]) > lamn)
      lamn = fabs(xpp[i]);

  /* Normalization */

  for(i = 1; i <= n; ++i)
    xpp[i] = xpp[i] / lamn;

  /* Diplay */

  printf("\n%f\n", lamn);
  for(i = 1; i <= n; ++i)
    {
      printf("%f\n", xpp[i]);
    }


  /* Checking accuracy */

  if(fabs(lamn - lamo) > epsilon)
    {
      lamo = lamn;
      goto prince;
    }
  
  
  return 0;
}
