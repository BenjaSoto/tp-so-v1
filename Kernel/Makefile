#globales
CC = gcc
OUTFILE = kernel.out

SRC = $(shell find ./src -type f -iname "*.c") #-exec basename {} \;)
OBJ = $(SRC:%.c=./obj/%.o)



LINK = -lcommons

# Agregado para incluir compartida
SHARED_SRC = $(shell find ../Compartida/src -type f -iname "*.c" ) #-exec basename {} \;)
SHARED_OBJ = $(SHARED_SRC:../Compartida/src/%.c=../Compartida/obj/%.o)



CFLAGS = -Wall -g -Iinclude -I../Compartida/include
all: build

build: makefolder $(OBJ) $(SHARED_OBJ)
	$(CC) -o $(OUTFILE) init_kernel.c $(OBJ) $(SHARED_OBJ) $(LINK)

./obj/%.o: ./src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)


../Compartida/obj/%.o: ../Compartida/src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

makefolder:
	if [ ! -d ./obj ]; then mkdir obj; fi
	if [ ! -d ../Compartida/obj ]; then mkdir ../Compartida/obj; fi
