CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRC_PETLA = main.c library_petla.c
SRC_REKURENCJA = main.c library_rekurencja.c

# Object files
OBJ_PETLA = $(SRC_PETLA:.c=.o)
OBJ_REKURENCJA = $(SRC_REKURENCJA:.c=.o)

# Executable names
EXEC_PETLA = program_petla
EXEC_REKURENCJA = program_rekurencja

# Targets
all: $(EXEC_PETLA) $(EXEC_REKURENCJA)

$(EXEC_PETLA): $(OBJ_PETLA)
	$(CC) $(CFLAGS) -o $@ $^

$(EXEC_REKURENCJA): $(OBJ_REKURENCJA)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_PETLA) $(OBJ_REKURENCJA) $(EXEC_PETLA) $(EXEC_REKURENCJA)