#include <stdio.h>

void RecursNumberBin(int n);

int main()
{
    int Number = 0;
    scanf("%d",&Number);
    RecursNumberBin(Number);
    printf("\n");
    return 0;
}

void RecursNumberBin(int n)
{
    if(n>1)
       RecursNumberBin(n/2);
    printf("%d",n%2);

}
