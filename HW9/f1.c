/*#include <stdio.h>
void InputArr(int size, int a[]);
void OutputArr(int size, int a[]);
void sort_array(int size, int a[]);
int main(void)
{
    int N = 0;
    scanf("%d",&N);
    int a[N];
    InputArr(N,a);
    sort_array(N,a);
    OutputArr(N,a);
    return 0;
}

void InputArr(int size, int a[])
{
    for(int i = 0; i < size; i++)
        scanf("%d", &a[i]);
}

void OutputArr(int size, int a[])
{
    for(int i = 0; i < size; i++)
        printf("%d ",a[i]);
}
*/
void sort_array(int size, int a[])
{
    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int sort = a[j];
                a[j] = a[j+1];
                a[j+1] = sort;
            }
        }
    }
}
