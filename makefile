lgfw = -lglfw -lGL
leif = -lleif -lclipboard -lm -lxcb
CC = gcc

app: main.c
	- $(CC) -o todo main.c $(lgfw) $(leif)

clean:
	- rm -f todo