CPP = g++
CPPFLAGS = -std=c++23 -Wall -Wextra -pedantic -fconcepts-diagnostics-depth=2
SRCS = test.cpp ../../lista2/Task1/GF.cpp

all: test

test: $(SRCS)
	$(CPP) $(CPPFLAGS) -o $@ $^

clean:
	rm -f test