#include <stdio.h>
#include <string.h>

int ScanFileInput();
int PrintFileOutput(int a);
char str[1001];
int main(void)
{

    PrintFileOutput(ScanFileInput());
    return 0;
}

int ScanFileInput()
{
    int lenght;
    FILE* fInput = fopen("input.txt","r");

    if(fInput == NULL)
        return -1;

    fgets(str,sizeof(str),fInput);

    fclose(fInput);
    lenght = strlen(str);
    if (lenght > 0 && str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
        lenght--;
    }
    return lenght;
}

int PrintFileOutput(int a)
{
    char LastChar = str[a-1];
    int first = 1;
    FILE* fOutput = fopen("output.txt","w");
    if(fOutput == NULL)
        return -1;
    for (int i = 0; i < a-1; i++)
    {
        if (str[i] == LastChar)
        {
            if (!first)
            {
                fprintf(fOutput, " ");
            }
            fprintf(fOutput, "%d", i);
            first = 0;
        }
    }
    fclose(fOutput);
    return 0;
}
