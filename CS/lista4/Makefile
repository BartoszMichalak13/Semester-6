CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
SOURCE = RSA.c
TARGET = rsa

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) 