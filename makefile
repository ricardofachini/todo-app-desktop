lgfw = -lglfw -lGL
leif = -lleif -lclipboard -lm -lxcb
CC = gcc

all: main.c
	- $(CC) -o todo main.c $(lgfw) $(leif)

run:
	- ./todo

clean:
	- rm -f todo