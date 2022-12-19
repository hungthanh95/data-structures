BIN_DIR = bin
TEST_DIR = test
GRAPH = graph

CC = g++
CCFLAGS = -Wall -O0 -g

EXECUTABLES = $(GRAPH) StackArray QueueArray

all: $(EXECUTABLES)

$(GRAPH): $(GRAPH)/Graph.cpp
	mkdir -p $(BIN_DIR)
	$(CC) $(CCFLAGS) $^ -o $(BIN_DIR)/$@

StackArray: stack/StackArray.cpp
	$(CC) $(CCFLAGS) $^ -o $(BIN_DIR)/$@

QueueArray: queue/QueueArray.cpp
	$(CC) $(CCFLAGS) $^ -o $(BIN_DIR)/$@


.PHONY: clean format

clean:
	rm -rf $(BIN_DIR)/*

format:
	clang-format -style=file -i *.c *.h