#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "temp_api.h"

int main(int argc, char *argv[])
{
    TemperatureRecord *temperatureData = NULL;
    int totalRecords = 0;
    char *inputFileName = NULL;
    int selectedMonth = 0;
    int showHelpFlag = 0;
    
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            showHelpFlag = 1;
        }
        else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc)
        {
            inputFileName = argv[++i];
        }
        else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc)
        {
            selectedMonth = atoi(argv[++i]);
            if (!validateMonth(selectedMonth))
            {
                printf("\n[ERROR] Invalid month value. Must be between 1 and 12.\n");
                return 1;
            }
        }
        else
        {
            printf("\n[ERROR] Unknown parameter: %s\n", argv[i]);
            displayUsage();
            return 1;
        }
    }
    
    if (showHelpFlag)
    {
        displayUsage();
        return 0;
    }
    
    if (!inputFileName)
    {
        printf("\n[ERROR] Input file not specified.\n");
        displayUsage();
        return 1;
    }
    
    int loadResult = loadCSVData(inputFileName, &temperatureData, &totalRecords);
    
    if (loadResult < 0)
    {
        if (temperatureData) free(temperatureData);
        return 1;
    }
    
    if (totalRecords == 0)
    {
        printf("\n[ERROR] No valid temperature records found in file.\n");
        if (temperatureData) free(temperatureData);
        return 1;
    }
    
    displayStatistics(temperatureData, totalRecords, selectedMonth);
    
    free(temperatureData);
    return 0;
}