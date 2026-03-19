
/*#include <stdio.h>
void InputArr(int size, int a[]);
void OutputArr(int size, int a[]);
int find_max_array(int size, int a[]);

int main(void)
{
    int N = 0;
    scanf("%d",&N);
    int a[N];
    InputArr(N,a);
    printf("%d ",find_max_array(N,a));
    return 0;
}

void InputArr(int size, int a[])
{
    for(int i = 0; i < size; i++)
        scanf("%d", &a[i]);
}*/

int find_max_array(int size, int a[])
{
    int max_elem_array = a[0];
    for(int i = 0; i<size;i++)
        if(a[i] > max_elem_array)
            max_elem_array = a[i];
    return max_elem_array;
}
