#include <stdio.h>
#include "stdlib.h"
#include <math.h>
int main()
{
    int i;
    float yp;
    float fx[7];
    int n;
    float x[7];
    int x1;
    float l[50];
    //int l[1];
    int p;
    int j;
    printf("Enter the number of value->");
    scanf("%d",&n);
    for(i=0;i<7;i++)
    {
        printf("x[%d]->",i);
        scanf("%f",&x[i]);
        printf("\n");
        printf("fx[%d]->",i);
        scanf("%f",&fx[i]);
        printf("\n");
    }
    printf("Enter the value of x for which y is to be calculated");
    scanf("%d",&x1);
    for(i=0;i<n;i++)
    {
        l[i]=1;
        //p=1;
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                //p= p* ((x1-x[j])/(x[i]-x[j]));
                l[i]= l[i]* ((x1-x[j])/(x[i]-x[j]));
            }
        }
    yp=yp+l[i]*fx[i];
    //p=p+fx[i]*l[i];
    }
    printf("%f",yp);
return 0;
}
