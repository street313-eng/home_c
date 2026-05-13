CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11
TARGET = tempsensor

all: $(TARGET)

$(TARGET): main.c temp_api.c
	$(CC) $(CFLAGS) main.c temp_api.c -o $(TARGET)

clean:
	del $(TARGET) $(TARGET).exe *.o
