CPP = g++
CPPFLAGS = -Wall -O3 -std=c++23

TEST_FILE = test.cpp 
SRCS = GF.cpp $(TEST_FILE)

TARGET = test 

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CPP) $(CPPFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)