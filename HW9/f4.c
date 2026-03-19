
/*#include <stdio.h>
#define MAX_LENGHT 1000
#define BASE 10

void print_digit(char s[]);

int main(void)
{
    char number[MAX_LENGHT];
    fgets(number,sizeof(number),stdin);
    print_digit(number);
    return 0;
}
*/
void print_digit(char s[])
{
    int cnt[10] = {0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            cnt[s[i] - '0']++;
    }

    for (int i = 0; i < 10; i++) {
        if (cnt[i]) {
            printf("%d %d\n", i, cnt[i]);
        }
    }
}
