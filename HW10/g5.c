#include <stdio.h>
#include <string.h>

int ScanFileInput();
int PrintFileOutput();
char str[1001];
char str1[101];
char str2[101];
int cnt1[256] = {0};
int cnt2[256] = {0};
int res[256];
int res_cnt = 0;

int main(void)
{
    ScanFileInput();
    PrintFileOutput();
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
        str[lenght - 1] = '\0';

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a')
        {
            str[i] = 'b';
        }
        else if (str[i] == 'b')
        {
            str[i] = 'a';
        }
        else if (str[i] == 'A')
        {
            str[i] = 'B';
        }
        else if (str[i] == 'B')
        {
            str[i] = 'A';
        }
    }
    return 0;
}

int PrintFileOutput()
{
    FILE* fOutput = fopen("output.txt","w");
    if(fOutput == NULL)
        return -1;
    fprintf(fOutput,"%s",str);
    fclose(fOutput);
    return 0;
}
