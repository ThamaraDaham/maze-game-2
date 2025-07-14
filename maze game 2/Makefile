##
 # File: Makefile
 # File Created: 2021/9/13
 # Author: thamara dham
 # -----
 # Purpose: To run the maze game
##


# Makefile Variables
CC		 = gcc
EXEC	 = maze
 
OBJ 	 = main.o game.o map.o terminal.o

# Add DARK to the CFLAGS and recompile the program
ifdef DARK
CFLAGS = -D DARK
DARK : clean $(EXEC)
endif



$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c map.h terminal.h headerFile.h
	$(CC) $(CFLAGS) main.c -c 

game.o : game.c headerFile.h terminal.h
	$(CC) -c game.c

map.o : map.c map.h 
	$(CC) -c map.c 

terminal.o : terminal.c terminal.h 
	$(CC) -c terminal.c

clean:
	rm -f $(EXEC) $(OBJ)
