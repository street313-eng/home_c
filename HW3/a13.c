#include <stdio.h>

int main()
{
    int a, b, c, d;
    scanf("%d",&a);
    d = a%10;
    c = (a/10)%10;
    b = (a/100)%10;
    printf("%d\n",b*c*d);
    return 0;
}
