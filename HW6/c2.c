#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int absNumber(int a);
int powerNumber(int a, int b);
int main() 
{
    int Number = 0;
    int SterP = 0;
    scanf("%d%d",&Number,&SterP);
    if(absNumber(Number) <= 1000 && SterP >= 0)
        printf("%d\n",
           powerNumber(Number, SterP));
    return 0;
}

int absNumber(int a)
{
    int b = 0;
    b = abs(a);
    return b;
}

int powerNumber(int a, int b)
{
    return pow(a,b);
}
