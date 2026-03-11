#include <stdio.h>
#define N 10

void InputArr(int arr[N]);
int MinimumArr(int arr[N]);
int MaximumArr(int arr[N]);
int NumMinimumArr(int arr[N]);
int NumMaximumArr(int arr[N]);
int main(void)
{
    int arr[N] = {0};
    InputArr(arr);
    printf("%d %d %d %d",
           NumMaximumArr(arr),
           MaximumArr(arr),
           NumMinimumArr(arr),
           MinimumArr(arr)
           );
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
        if(arr[i]<MinElem){
            MinElem = arr[i];
        }
    }
    return MinElem;
}

int MaximumArr(int arr[N])
{
    int MaxElem = arr[0];
    for(int i=0;i<N;i++)
    {
        if(arr[i]>MaxElem){
            MaxElem = arr[i];
        }
    }
    return MaxElem;
}

int NumMinimumArr(int arr[N])
{
    int MinElem = arr[0];
    int PosMinElem = 1;
    for(int i=0;i<N;i++)
    {
        if(arr[i]<MinElem){
            MinElem = arr[i];
            PosMinElem = i+1;
        }
    }
    return PosMinElem;
}

int NumMaximumArr(int arr[N])
{
    int MaxElem = arr[0];
    int PosMaxElem = 1;
    for(int i=0;i<N;i++)
    {
        if(arr[i]>MaxElem){
            MaxElem = arr[i];
            PosMaxElem = i+1;
        }
    }
    return PosMaxElem;
}
