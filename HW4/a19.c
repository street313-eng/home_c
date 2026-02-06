#include <stdio.h>

 int main()
{
    unsigned int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>0 && b>0 && c>0)
    {
		if((a+b)>c && (a+c)>b && (c+b)>a)
            printf("YES");
        else
            printf("NO");
    }
}
