/* #include <stdio.h> */
/* #include <math.h> */
/* #include <stdlib.h> */

/* #define f(x) pow(x,3) + pow(x,2) - 1 */
/* #define g(x) 1/sqrt(x+1) */

/* int main(int argc, char *argv[]) */
/* { */
/*   float x0, epsilon, x1; */
/*   int i = 1; */
    
/*   fputs("Enter the initial guess:\x20", stdout); */
/*   scanf("%lf", &x1); */
/*   fputs("Enter the tolorable error:\x20", stdout); */
/*   scanf("%lf", &epsilon); */
/*   do */
/*     { */
/*       x1 = g(x0); */
/*       i++; */
/*       x0 = x1; */
/*     } */
/*   while(fabs(f(x1)) > epsilon); */
/*   printf("\nThe root is: %lf\n", x1); */
/*   return 0; */
/* } */


#include<stdio.h>
#include<math.h>
#define f(x) pow(x,3)+pow(x,2)-1
#define g(x) 1/(sqrt(x+1))
int main(int argc,char **argv)
{
    float x0,x1,epsilon;
    int step=1;
    
    printf("Enter the initial guesses:\x20");
    scanf("%f",&x0);
    printf("Enter tolorable guess:");
    scanf("%f", &epsilon);

    do
    {
     x1=g(x0);
     step=step+1;
     x0=x1;   
    }
    while(fabs(f(x1))>epsilon);

    printf("The root is:%f\n",x1);
    printf("The total no.of iteration is:%d\n",step);

    return 0;
}

