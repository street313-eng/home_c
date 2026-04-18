#include <stdio.h>
#include <string.h>

int ScanFileInput();
int PrintFileOutput(int a);

int main(void)
{
    int Number = 0;
    Number = ScanFileInput();
    PrintFileOutput(Number);
    getchar();
    return 0;
}

int ScanFileInput()
{
    int Num = 0;
    FILE* fInput = fopen("input.txt","r");

    if(fInput == NULL)
        return -1;
    fscanf(fInput,"%d",&Num);

    fclose(fInput);
    return Num;
}

int PrintFileOutput(int a)
{
    int digit = 2;
    char letter = 'A';
    char result[27];;
    FILE* fOutput = fopen("output.txt","w");
    if(fOutput == NULL)
        return -1;
    for (int i = 0; i <= a; i++)
    {
        if (i % 2 == 1)
        {
            result[i] = '0' + digit;
            digit += 2;
            if (digit > 8)
                digit = 2;
        }
        else
        {
            result[i] = letter;
            letter++;
        }

    }

    result[a] = '\0';
    fprintf(fOutput, "%s\n", result);
    fclose(fOutput);
    return 0;
}
