CC = gcc
CFLAGS = -Wall -Wextra

TEST_FILE_WHOLE = test_whole.c

# List of all source files
SRCS_IMPL_WHOLE = library_whole.c $(TEST_FILE_WHOLE)

# Targets
TARGET_IMPL_WHOLE = test_impl_whole

.PHONY: all clean

all: $(TARGET_IMPL_WHOLE)

$(TARGET_IMPL_WHOLE): $(SRCS_IMPL_WHOLE)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET_IMPL_WHOLE) 