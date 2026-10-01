CC = gcc

CFLAGS = -std=c11 -O2 -Wall -Wextra -municode -Iinclude

TARGET = box.exe

SRC = $(shell find src -type f -name '*.c')

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

all: $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean