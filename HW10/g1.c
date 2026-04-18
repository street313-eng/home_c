#include <stdio.h>
#include <string.h>
int main(void)
{
    unsigned char str[1000] = {0};
    int length = 0;
    FILE* fInput = fopen("input.txt","r");
    if(fInput == NULL)
        return -1;
    fgets (str, sizeof(str), fInput);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    length = strlen(str);
    fclose(fInput);

    FILE* fOutput = fopen("output.txt","w");
    if(fOutput == NULL)
        return -1;
    fprintf(fOutput,"%s, %s, %s %d",str,str,str,length);
    fclose(fOutput);

    return 0;
}
