#Compiler flags
RELEASE_FLAGS = -Iinclude -O2 -DNDEBUG -Wall -Wextra
DEBUG_FLAGS = -Iinclude -fsanitize=undefined,address -g -Wall -Wextra -Wpedantic
WIN_DEBUG_FLAGS = -Iinclude -g -Wall -Wextra -Wpedantic

#Directories
SRC = $(wildcard src/*.c)
RELEASE_OBJ = $(patsubst src/%.c, build/release/%.o, $(SRC))
DEBUG_OBJ = $(patsubst src/%.c, build/debug/%.o, $(SRC))
WIN_RELEASE_OBJ = $(patsubst src/%.c, build/win-release/%.o, $(SRC))
WIN_DEBUG_OBJ = $(patsubst src/%.c, build/win-debug/%.o, $(SRC))

#Compiler
LCC = gcc #linux
WCC = x86_64-w64-mingw32-gcc #windows

#Binaries
LEXEC = bin/calc #linux release
LDEXEC = bin/calc-debug #linux debug
WEXEC = bin/calc.exe #windows release
WDEXEC = bin/calc-debug.exe #windows debug

#Default compile (linux)
all: $(LEXEC)
$(LEXEC): $(RELEASE_OBJ)
	$(LCC) $(RELEASE_OBJ) -o $(LEXEC)
#Debug compile (linux)
debug: $(DEBUG_OBJ)
	$(LCC) $(DEBUG_OBJ) $(DEBUG_FLAGS) -o $(LDEXEC)
#Windows compile
windows: $(WIN_RELEASE_OBJ)
	$(WCC) $(WIN_RELEASE_OBJ) -o $(WEXEC)
#Windows debug compile
wdebug: $(WIN_DEBUG_OBJ)
	$(WCC) $(WIN_DEBUG_OBJ) $(WIN_DEBUG_FLAGS) -o $(WDEXEC)

#Patern rules
build/release/%.o: src/%.c | release-build
	$(LCC) $(RELEASE_FLAGS) -c $< -o $@

build/debug/%.o: src/%.c | debug-build
	$(LCC) $(DEBUG_FLAGS) -c $< -o $@

build/win-release/%.o: src/%.c | win-release-build
	$(WCC) $(RELEASE_FLAGS) -c $< -o $@

build/win-debug/%.o: src/%.c | win-debug-build
	$(WCC) $(WIN_DEBUG_FLAGS) -c $< -o $@

#Delete the objs and bins
clean:
	rm -rf build/* bin/*

#Ensure all needed directory exist
$(RELEASE_OBJ): | release-build
$(DEBUG_OBJ): | debug-build
$(WIN_RELEASE_OBJ): | win-release-build
$(WIN_DEBUG_OBJ): | win-debug-build
$(LEXEC): | bin
$(LDEXEC): | bin
$(WEXEC): | bin
$(WDEXEC): | bin
release-build:
	mkdir -p build/release
debug-build:
	mkdir -p build/debug
win-release-build:
	mkdir -p build/win-release
win-debug-build:
	mkdir -p build/win-debug
bin:
	mkdir -p bin
