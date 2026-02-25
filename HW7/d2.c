#include <stdio.h>

int RecursNumber(int n);

int main() {
    int Number = 0;
    scanf("%d",&Number);
    printf("%d\n",RecursNumber(Number));
    return 0;
}

int RecursNumber(int n)
{
    static int SumNumber = 0;
    if(n>=1){
        SumNumber+=n;
        RecursNumber(n-1);
    }
    return SumNumber;
}
