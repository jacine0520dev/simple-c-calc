CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
EXEC = bin/my-calc

# Windows cross-compile
WCC = x86_64-w64-mingw32-gcc
WEXEC = bin/my-calc.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Windows target
windows: $(SRC)
	$(WCC) $(CFLAGS) $(SRC) -o $(WEXEC)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f build/*.o $(EXEC) $(WEXEC)

$(OBJ): | build
$(EXEC): | bin

build:
	mkdir -p build

bin:
	mkdir -p bin
