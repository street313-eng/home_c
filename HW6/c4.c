#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//int absNumber(int a);
//int powerNumber(int a, int b);
//int middle(int a,int b);
int FuncCalc(int a);
int main() {
    int NumberX = 0;
    //int Result = 0;
    int Max = 0;
    scanf("%d",&NumberX);
    Max = NumberX;
    while( NumberX != 0)
    {
        FuncCalc(NumberX);
        if(FuncCalc(NumberX) > Max)
            Max = FuncCalc(NumberX);
        scanf("%d",&NumberX);
        //printf("%d\n",FuncCalc(NumberX));
    }

    printf("%d\n",Max);
    return 0;
}

int FuncCalc(int a)
{
    if(a<2 && a>=-2)
        return a*a;
    else if(a>=2)
        return (a*a+4*a+5);
    else if(a<-2)
        return 4;
}

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
