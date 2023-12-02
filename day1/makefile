
CC = gcc
CFLAGS = -Wall -g
TARGET = day1

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
	rm -rf $(TARGET).dSYM

clean:
	rm -f $(TARGET) $(TARGET).o