.PHONY: all clean

# Compiler and compiler flags
HC = ghc
HCFLAGS = -Wall 

# Source files
SRC = functions.hs

# Output executable
EXE = functions

all: $(EXE)

$(EXE): $(SRC)
	$(HC) $(HCFLAGS) -o $@ $<

clean:
	rm -f $(EXE) *.o *.hi
