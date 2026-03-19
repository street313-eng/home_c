#include <stdio.h>
#define MAX_LENGHT 1000
#define BASE 10

void countDigits(char* number);

int main(void)
{
    char number[MAX_LENGHT];
    fgets(number,sizeof(number),stdin);
    countDigits(number);
    return 0;
}

void countDigits(char* number)
{
    int cnt[BASE] = {0};
    for (int i = 0; number[i] != '\0'; i++)
    {
        int digit = number[i] - '0';
        cnt[digit]++;
    }

    for (int i = 0; i <= 9; i++) {
        if (cnt[i] > 0) {
            printf("%d %d\n", i, cnt[i]);
        }
    }
}
