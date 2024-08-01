libs = -lglfw -lGL
CC = gcc

app: main.c
	- $(CC) -o todo main.c $(libs)
	
clean:
	- rm -f todo