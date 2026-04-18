#include <stdio.h>
#include <string.h>

int ScanFileInput();
int PrintFileOutput();
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

    fscanf(fInput, "%s %s", str1, str2);
    fclose(fInput);

    for(int i = 0; i < strlen(str1); i++)
        cnt1[(unsigned char)str1[i]]++;


    for(int i = 0; i < strlen(str2); i++)
        cnt2[(unsigned char)str2[i]]++;

    for(int j = 0; j < 256; j++)
        if(cnt1[j] == 1 && cnt2[j] == 1)
            res[res_cnt++] = (char)j;

    return 0;
}

int PrintFileOutput()
{
    FILE* fOutput = fopen("output.txt","w");
    if(fOutput == NULL)
        return -1;

    for(int i = 0; i < res_cnt; i++)
    {
        if(i > 0)
            fprintf(fOutput," ");
        fprintf(fOutput,"%c",res[i]);
    }
    fprintf(fOutput,"\n");

    fclose(fOutput);
    return 0;
}
