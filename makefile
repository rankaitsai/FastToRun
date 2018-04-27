.PHONY: directories clean
CC=g++
CFLAGS=-std=c++11
LIBS=-lgtest -lpthread
OBJ=obj
EXE=exe
BIN=bin
SRC=src
TEST=test

all: directories $(BIN)/ut_all

$(BIN)/ut_all: $(OBJ)/ut_main.o
	$(CC) $(CFLAGS) -o $@ $(OBJ)/ut_main.o $(LIBS)
	
$(OBJ)/ut_main.o: $(TEST)/ut_main.cpp $(TEST)/ut_ftr.h
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p bin obj exe

clean:
	rm -rf $(OBJ) $(BIN) $(EXE)

stat:
	wc $(SRC)/*.h $(SRC)/*.cpp $(TEST)/*.h $(TEST)/*.cpp
