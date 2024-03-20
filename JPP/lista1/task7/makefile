CC = g++
CFLAGS = -I/usr/include/python3.10
LIBS = -lboost_python310 -lpython3.10

test: test2.cpp
	$(CC) -o test test2.cpp $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f test