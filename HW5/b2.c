#include <stdio.h>

 int main()
{
    unsigned int a;
    unsigned int b;
    scanf("%d%d",&a,&b);
    while(b>a)
    {
        printf("%d\t",a*a);
        a++;
    }
    if(a == b)
        printf("%d\n",a*a);
}

