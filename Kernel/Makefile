#globales
CC = gcc
OUTFILE = kernel.out

SRC = $(shell find ./src -type f -iname "*.c" -exec basename {} \;)
OBJ = $(SRC:%.c=./obj/%.o)

LINK = -lcommons
all: build

build: makefolder $(OBJ)
	$(CC) -o $(OUTFILE) init_kernel.c $(OBJ) $(LINK)

./obj/%.o: ./src/%.c
	$(CC) -c $< -o $@ 

makefolder:
	if [ ! -d ./obj ]; then mkdir obj; fi
