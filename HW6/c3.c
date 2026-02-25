#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//int absNumber(int a);
//int powerNumber(int a, int b);
int middle(int a,int b);
int main() {
    unsigned int Number1 = 0;
    unsigned int Number2 = 0;
    scanf("%d%d",&Number1,&Number2);
    printf("%d\n",middle(Number1,Number2));
    return 0;
}

int middle(int a,int b)
{
    return ((a+b)/2);
}

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
