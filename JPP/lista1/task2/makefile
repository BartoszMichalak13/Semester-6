# Makefile for compiling Ada code

# Compiler
ADA_COMPILER := gnatmake

# Source files
ADA_SOURCES := my_library.adb test.adb

# Main target
all: test

# Compile Ada sources
%.o: %.adb
	$(ADA_COMPILER) $<

# Link object files to create the executable
test: test.o
	$(ADA_COMPILER) -o my_library.o test.o

# Clean generated files
clean:
	rm -f *.o *.ali test

clean_obj:
	rm -f *.o *.ali
