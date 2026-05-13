#include "temp_api.h"

void displayUsage(void)
{
    printf("\n-------------------------------------------------------\n");
    printf("     TEMPERATURE DATA ANALYZER - Command Line Tool       \n");
    printf("---------------------------------------------------------\n\n");
    printf("USAGE:\n");
    printf("  analyzer -f <filename.csv> [-m <month>] [-h]\n\n");
    printf("OPTIONS:\n");
    printf("  -f <file>     Path to input CSV file (required)\n");
    printf("  -m <month>    Month number (1-12) for detailed statistics\n");
    printf("  -h            Show this help message\n\n");
    printf("EXAMPLES:\n");
    printf("  analyzer -f sensor_data.csv\n");
    printf("  analyzer -f data.csv -m 7\n");
    printf("  analyzer -h\n\n");
}

int validateMonth(int month)
{
    return (month >= 1 && month <= 12) ? 1 : 0;
}

TemperatureStats calculateStats(TemperatureRecord *records, int startIdx, int endIdx)
{
    TemperatureStats stats = {MAX_TEMP_VALUE, MIN_TEMP_VALUE, 0.0f, 0};
    
    for (int i = startIdx; i < endIdx; i++)
    {
        stats.count++;
        stats.avgTemp += records[i].temperature;
        
        if (records[i].temperature < stats.minTemp)
            stats.minTemp = records[i].temperature;
        if (records[i].temperature > stats.maxTemp)
            stats.maxTemp = records[i].temperature;
    }
    
    if (stats.count > 0)
        stats.avgTemp /= stats.count;
    
    return stats;
}

void printSeparator(char symbol, int length)
{
    for (int i = 0; i < length; i++)
        printf("%c", symbol);
    printf("\n");
}

void displayStatistics(TemperatureRecord *records, int totalRecords, int targetMonth)
{
    if (totalRecords == 0)
    {
        printf("\n[!] No data available for analysis.\n");
        return;
    }
    
    printf("\n");
    printSeparator('=', 60);
    
    if (targetMonth > 0)
        printf("  STATISTICS FOR MONTH: %d\n", targetMonth);
    else
        printf("  COMPREHENSIVE STATISTICS (All Data)\n");
    
    printSeparator('=', 60);
    printf("%-10s %-15s %-10s %-10s %-8s\n", "Period", "Avg Temp(C)", "Min(C)", "Max(C)", "Records");
    printSeparator('-', 60);
    
    int processedYears[100] = {0};
    int yearCount = 0;
    
    for (int i = 0; i < totalRecords; i++)
    {
        if (targetMonth > 0 && records[i].month != targetMonth)
            continue;
        
        int isUniqueMonth = 1;
        for (int j = 0; j < i; j++)
        {
            if (records[i].year == records[j].year && 
                records[i].month == records[j].month)
            {
                isUniqueMonth = 0;
                break;
            }
        }
        
        if (isUniqueMonth)
        {
            int startIdx = -1, endIdx = -1;
            
            for (int j = 0; j < totalRecords; j++)
            {
                if (records[j].year == records[i].year && 
                    records[j].month == records[i].month)
                {
                    if (startIdx == -1) startIdx = j;
                    endIdx = j + 1;
                }
            }
            
            TemperatureStats stats = calculateStats(records, startIdx, endIdx);
            printf("%04d-%02d       %7.1f      %3d       %3d       %4d\n",
                   records[i].year, records[i].month, 
                   stats.avgTemp, stats.minTemp, stats.maxTemp, stats.count);
        }
        
        if (targetMonth == 0)
        {
            int isUniqueYear = 1;
            for (int j = 0; j < yearCount; j++)
            {
                if (processedYears[j] == records[i].year)
                {
                    isUniqueYear = 0;
                    break;
                }
            }
            
            if (isUniqueYear)
            {
                int startIdx = -1, endIdx = -1;
                processedYears[yearCount++] = records[i].year;
                
                for (int j = 0; j < totalRecords; j++)
                {
                    if (records[j].year == records[i].year)
                    {
                        if (startIdx == -1) startIdx = j;
                        endIdx = j + 1;
                    }
                }
                
                TemperatureStats stats = calculateStats(records, startIdx, endIdx);
                printf("%04d (Year)    %7.1f      %3d       %3d       %4d\n",
                       records[i].year, stats.avgTemp, 
                       stats.minTemp, stats.maxTemp, stats.count);
            }
        }
    }
    
    printSeparator('=', 60);
    printf("\n");
}

int parseDataLine(char *line, TemperatureRecord *record)
{
    int year, month, day, hour, minute, temp;
    char separators[] = " \t,;";
    char *token;
    
    token = strtok(line, separators);
    if (!token) return 0;
    year = atoi(token);
    
    token = strtok(NULL, separators);
    if (!token) return 0;
    month = atoi(token);
    
    token = strtok(NULL, separators);
    if (!token) return 0;
    day = atoi(token);
    
    token = strtok(NULL, separators);
    if (!token) return 0;
    hour = atoi(token);
    
    token = strtok(NULL, separators);
    if (!token) return 0;
    minute = atoi(token);
    
    token = strtok(NULL, separators);
    if (!token) return 0;

    char *endptr;
    temp = strtol(token, &endptr, 10);
    if(*endptr != '\0')
    {
        printf("[WARNING] Invalid temperature value: %s\n", token);
        return 0;
    }
        
    if (temp < MIN_TEMP_VALUE || temp > MAX_TEMP_VALUE)
    {
       return 0;
    }
    
    record->year = (unsigned short)year;
    record->month = (unsigned short)month;
    record->day = (unsigned short)day;
    record->hour = (unsigned short)hour;
    record->minute = (unsigned short)minute;
    record->temperature = (short)temp;
    
    return 1;
}

int loadCSVData(const char *filename, TemperatureRecord **dataArray, int *dataSize)
{
    FILE *fileHandle = fopen(filename, "r");
    if (!fileHandle)
    {
        printf("\n[ERROR] Cannot open file: %s\n", filename);
        return -1;
    }
    
    char buffer[MAX_STRING_LEN];
    int recordCount = 0;
    int currentCapacity = INITIAL_CAPACITY;
    int lineNumber = 0;
    int isFirstLine = 1;
    
    *dataArray = (TemperatureRecord*)malloc(currentCapacity * sizeof(TemperatureRecord));
    if (!*dataArray)
    {
        printf("[ERROR] Memory allocation failed\n");
        fclose(fileHandle);
        return -1;
    }
    
    while (fgets(buffer, MAX_STRING_LEN, fileHandle))
    {
        lineNumber++;
        buffer[strcspn(buffer, "\r\n")] = 0;
        
        if (strlen(buffer) == 0)
            continue;
        
        char workBuffer[MAX_STRING_LEN];
        strcpy(workBuffer, buffer);
        
        if (isFirstLine)
        {
            isFirstLine = 0;
            TemperatureRecord testRecord;
            if (parseDataLine(workBuffer, &testRecord))
            {
                if (recordCount >= currentCapacity)
                {
                    currentCapacity *= 2;
                    TemperatureRecord *newArray = (TemperatureRecord*)realloc(*dataArray, 
                        currentCapacity * sizeof(TemperatureRecord));
                    if (!newArray)
                    {
                        printf("[ERROR] Memory reallocation failed\n");
                        free(*dataArray);
                        fclose(fileHandle);
                        return -1;
                    }
                    *dataArray = newArray;
                }
                (*dataArray)[recordCount++] = testRecord;
            }
            else
            {
                printf("[INFO] Skipping header line %d: %s\n", lineNumber, buffer);
            }
        }
        else
        {
            TemperatureRecord newRecord;
            if (parseDataLine(workBuffer, &newRecord))
            {
                if (recordCount >= currentCapacity)
                {
                    currentCapacity *= 2;
                    TemperatureRecord *newArray = (TemperatureRecord*)realloc(*dataArray,
                        currentCapacity * sizeof(TemperatureRecord));
                    if (!newArray)
                    {
                        printf("[ERROR] Memory reallocation failed\n");
                        free(*dataArray);
                        fclose(fileHandle);
                        return -1;
                    }
                    *dataArray = newArray;
                }
                (*dataArray)[recordCount++] = newRecord;
            }
            else
            {
                printf("[WARNING] Line %d: Invalid format or value - %s\n", lineNumber, buffer);
            }
        }
    }
    
    if (recordCount < currentCapacity)
    {
        TemperatureRecord *newArray = (TemperatureRecord*)realloc(*dataArray, 
            recordCount * sizeof(TemperatureRecord));
        if (newArray)
            *dataArray = newArray;
    }
    
    *dataSize = recordCount;
    fclose(fileHandle);
    
    printf("\n[OK] Successfully loaded %d records from %s\n", recordCount, filename);
    return recordCount;
}