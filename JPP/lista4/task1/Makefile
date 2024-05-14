# Makefile for compiling Ada code

# Compiler
ADA_COMPILER := gnatmake

# Source files
ADA_SOURCES := philosophers.adb philorun.adb

# Main target
all:  philorun

# Compile Ada sources
%.o: %.adb
	$(ADA_COMPILER) $<

# Link object files to create the executable
philorun: philorun.o philosophers.o 
	$(ADA_COMPILER) -o philorun.o philosophers.o 

# Clean generated files
clean:
	rm -f *.o *.ali  philorun

clean_obj:
	rm -f *.o *.ali
