# # Compiler and flags
CC = gcc
ADA_CC = gnatmake
ADA_BIND = gnatbind
ADA_LINK = gnatlink
CFLAGS = -c -Wall -std=c99
ADA_FLAGS = -c -Wall

ADA_TEST = test_wrapper.adb
LIBRARY_SOURCE = ../task1/library_whole.c

# Targets
all: test_wrapper

test_wrapper: library_whole.o test_wrapper.ali 
	$(ADA_BIND) test_wrapper.ali
	$(ADA_LINK) test_wrapper.ali library_whole.o
	$(ADA_CC) $(ADA_TEST) -largs library_whole.o 

library_whole.o: $(LIBRARY_SOURCE)
	$(CC) $(CFLAGS) $(LIBRARY_SOURCE)

%.ali: %.adb
	$(ADA_CC) $(ADA_FLAGS) $(ADA_TEST)

clean:
	rm -f *.o *.ali test_wrapper

clean_obj:
	rm -f *.o *.ali 