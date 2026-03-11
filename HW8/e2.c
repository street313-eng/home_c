#include <stdio.h>
#define N 5

void InputArr(int arr[N]);
int MinimumArr(int arr[N]);
int main(void)
{
    int arr[N] = {0};
    InputArr(arr);
    printf("%d",MinimumArr(arr));
    return 0;
}

void InputArr(int arr[N])
{
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
}

int MinimumArr(int arr[N])
{
    int MinElem = arr[0];
    for(int i=0;i<N;i++)
    {
        if(arr[i]<MinElem)
            MinElem = arr[i];
    }
    return MinElem;
}
