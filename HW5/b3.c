#include <stdio.h>

 int main()
{
    int a = 0;
    int b = 0;
    int sqrt = 0;
    int sum = 0;
    scanf("%d%d",&a,&b);
    for(int c=a;c<=b;c++)
    {
        sqrt = c * c;
        sum+=sqrt;
    }
    printf("%d\n",sum);
}
