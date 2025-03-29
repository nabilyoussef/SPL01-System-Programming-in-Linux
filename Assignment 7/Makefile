CC = gcc
CFLAGS = -Wall -Wextra -std=c11

OBJ = pico.o utilities.o

pico: $(OBJ)
	$(CC) $(OBJ) -o pico
	rm -f *.o
pico.o: pico.c utilities.h
	$(CC) -c pico.c -o pico.o

utilities.o: utilities.c utilities.h
	$(CC) -c utilities.c -o utilities.o

