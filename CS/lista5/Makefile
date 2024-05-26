CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -pedantic -g -O3
# SOURCES = rc4.c prints.c rc4KeyCompare.c 
OBJS = main.o prints.o rc4.o rc4KeyCompare.o rc4KeyDetection.o accGen.o bankCrack.o
# CRACK_OBJS = prints.o rc4.o rc4KeyCompare.o rc4KeyDetection.o accGen.o bankCrack.o
TARGET = main
# CRACK = crack

.PHONY: all clean

all: $(TARGET) #$(CRACK)

# %.o: %.c 
# 	$(CC) $(CFLAGS) $<

prints.o: prints.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

rc4KeyCompare.o: rc4KeyCompare.c rc4.o
	$(CC) $(CFLAGS) -c $< -o $@

rc4KeyDetection.o: rc4KeyDetection.c rc4.o
	$(CC) $(CFLAGS) -c $< -o $@

rc4.o: rc4.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

accGen.o: accGen.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

bankCrack.o: bankCrack.c accGen.o
	$(CC) $(CFLAGS) -c $< -o $@ 

main.o: main.c rc4KeyCompare.o rc4KeyDetection.o rc4.o prints.o bankCrack.c accGen.o
	$(CC) $(CFLAGS) -c $< -o $@ 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJS) 

# $(CRACK): $(CRACK_OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^
# 	rm -f $(CRACK_OBJS) 

clean:
	rm -f $(OBJS) 

cleanall:
	rm -f $(OBJS) $(TARGET) 

# UPDATE BASED ON FILES