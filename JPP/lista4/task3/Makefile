.PHONY: all clean

RUST_SRC := philorun.rs philosophers.rs
RUST_OBJ := $(RUST_SRC:.rs=.o)
RUST_BIN := philorun

all: $(RUST_BIN)

$(RUST_OBJ): %.o: %.rs
	rustc -o $@ $<

$(RUST_BIN): $(RUST_OBJ)
	rustc -o $(RUST_BIN) $(RUST_OBJ)

run: $(RUST_BIN)
	./$(RUST_BIN)

clean:
	rm -f $(RUST_BIN) $(RUST_OBJ)
