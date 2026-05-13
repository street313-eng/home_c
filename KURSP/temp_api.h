#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdio.h>
#include <inttypes.h>

#define MAX_STRING_LEN 512
#define MAX_TEMP_VALUE 100
#define MIN_TEMP_VALUE -99
#define INITIAL_CAPACITY 50

#pragma pack(push,1)

// Структура для хранения записи о температуре
typedef struct
{
    unsigned short year;
    unsigned short month;
    unsigned short day;
    unsigned short hour;
    unsigned short minute;
    short temperature;
}TemperatureRecord;

typedef struct
{
    int minTemp;
    int maxTemp;
    float avgTemp;
    int count;
}TemperatureStats;

#pragma pack(pop)

void displayUsage(void);

int validateMonth(int month);

TemperatureStats calculateStats(TemperatureRecord *records, int startIdx, int endIdx);

void printSeparator(char symbol, int length);

void displayStatistics(TemperatureRecord *records, int totalRecords, int targetMonth);

int parseDataLine(char *line, TemperatureRecord *record);

int loadCSVData(const char *filename, TemperatureRecord **dataArray, int *dataSize);

#endif