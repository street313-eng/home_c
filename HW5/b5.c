#include <stdio.h>
#define N 3
 int main()
{
    int a = 0;
    int sum = 0;
    int len = 0;
    scanf("%d",&a);
    while(a != 0)
    {
        len = a%10;
        sum += len;
        a /= 10;
    }
    printf("%d\n",sum);
    return 0;
}
