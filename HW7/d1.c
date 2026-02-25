#include <stdio.h>


int RecursNumber(int n);

int main() {
    int Number = 0;
    scanf("%d",&Number);
    RecursNumber(Number);
    return 0;
}

int RecursNumber(int n)
{
    if(n>1)
        RecursNumber(n-1);
    printf("%d\n",n);
    return 0;
}
