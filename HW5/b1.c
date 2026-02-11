#include <stdio.h>

 int main()
{
    unsigned int a = 1;
    unsigned int b;
    scanf("%d",&b);
    while(b>a)
    {
        printf("%d\t%d\t%d\n",a,a*a,a*a*a);
        a++;
    }
    if(a == b)
        printf("%d\t%d\t%d\n",a,a*a,a*a*a);
}

