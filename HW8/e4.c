#include <stdio.h>
#define N 10

void InputArr(int arr[N]);
int MaximumArr(int arr[N]);

int main(void)
{
    int arr[N] = {0};
    InputArr(arr);
    printf("%d\n",MaximumArr(arr));
    return 0;
}

void InputArr(int arr[N])
{
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
}

int MaximumArr(int arr[N])
{
    int MaxElem1 = arr[0];
    int MaxElem2 = arr[1];
    for(int i=2;i<N;i++)
    {
        if(arr[i]>MaxElem1){
            MaxElem2 = MaxElem1;
            MaxElem1 = arr[i];
        }
        else if(arr[i]>MaxElem2)
            MaxElem2 = arr[i];
    }
    return MaxElem1+MaxElem2;
}
