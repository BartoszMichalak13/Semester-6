# Makefile

# its imperfect as it need files from task2 aka run make in task2 and then here

# Compiler
CC = gcc
ADA_CC = gnatmake

# Compiler flags
CFLAGS = -Wall -Wextra
ADA_FLAGS = -Wall

# Source files
C_SRC = test.c wrapper.c
# ADA_SRC_PATH := $(shell realpath --relative-to $(my_library.adb))
ADA_SRC = ../task2/my_library.adb
ADA_LOCAL = my_library.o

# Object files
C_OBJ = $(C_SRC:.c=.o)
ADA_OBJ = $(ADA_SRC:.adb=.o)

# Executable
TARGET = test

all: $(TARGET)


$(TARGET): $(C_OBJ) $(ADA_OBJ)
	$(ADA_CC) -c $(ADA_SRC)
	$(ADA_CC) -c $(ADA_SRC:.adb=.o)
	$(CC) -o $(TARGET) $(C_OBJ) $(ADA_OBJ) -lgnat

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.adb
	$(ADA_CC) $<

clean:
	$(RM) $(C_OBJ) $(ADA_OBJ) $(TARGET) *.ali *.o