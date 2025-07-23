CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -O2
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
EXEC = bin/my-calc

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f build/*.o $(EXEC)

$(OBJ): | build
$(EXEC): | bin

build:
	mkdir -p build

bin:
	mkdir -p bin
