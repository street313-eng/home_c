#include <stdio.h>

int main()
{
    int a, b, c, d, max;
    scanf("%d",&a);
    d = a%10;
    c = (a/10)%10;
    b = (a/100)%10;
    max = c>b? c : b;
    max = max>d? max : d;
    printf("%d\n",max);
    return 0;
}
