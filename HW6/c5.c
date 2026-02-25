#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//int absNumber(int a);
//int powerNumber(int a, int b);
//int middle(int a,int b);
//int FuncCalc(int a);
int FuncCalcSum(int a);

int main() {
    unsigned int NumberN;
    scanf("%d",&NumberN);
    printf("%d\n",FuncCalcSum(NumberN));
    return 0;
}

int FuncCalcSum(int a)
{
    unsigned int Sum = 0;
    for(int i=1;i<a+1;i++)
        Sum+=i;
    return Sum;
}

/*int FuncCalc(int a)
{
    if(a<2 && a>=-2)
        return a*a;
    else if(a>=2)
        return (a*a+4*a+5);
    else if(a<-2)
        return 4;
}*/

/*int middle(int a,int b)
{
    return ((a+b)/2);
}*/

/*int absNumber(int a)
{
    int b = 0;
    b = abs(a);
    return b;
}*/

/*int powerNumber(int a, int b)
{
    return pow(a,b);
}*/
