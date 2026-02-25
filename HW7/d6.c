#include <stdio.h>

void reverse_string(void);

int main()
{
    reverse_string();
    return 0;
}

void reverse_string(void)
{
    char str;
    scanf("%c",&str);
    if(str == '.')
        return;
    reverse_string();
    printf("%c",str);
}
