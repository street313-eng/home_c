#include <stdio.h>
#define N 5

void InputArr(int arr[N]);
float SredneeArr(int arr[N]);

int main(void)
{
    int arr[N] = {0};
    InputArr(arr);
    printf("%.3f",SredneeArr(arr));
    return 0;
}

void InputArr(int arr[N])
{
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
}

float SredneeArr(int arr[N])
{
    float Summ = 0;
    for(int i=0;i<N;i++)
        Summ += arr[i];
    return Summ/N;
}
