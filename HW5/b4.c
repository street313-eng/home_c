#include <stdio.h>
#define N 3
 int main()
{
    unsigned int a;
    unsigned int b;
    scanf("%d",&a);
    b = a/100;
    if(b>0 && b<10)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
