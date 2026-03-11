#include <stdio.h>
#define N 10

void InputArr(int arr[N]);
int SummPolElem(int arr[N]);


int main(void)
{
    int arr[N] = {0};
    InputArr(arr);
    printf("%d\n",SummPolElem(arr));
    return 0;
}

void InputArr(int arr[N])
{
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
}

int SummPolElem(int arr[N])
{
    int Summ = 0;
    for(int i=0;i<N;i++)
    {
        if(arr[i]>0)
            Summ += arr[i];
    }
    return Summ;
}
