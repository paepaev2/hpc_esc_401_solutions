CFLAGS=-O3 -ffast-math -mavx2 -fopenmp
CC=CC

all: init.o io.o jacobi.o main
main.o: main.cpp init.h io.h jacobi.h
	$(CC) $(CFLAGS) -c main.cpp
init.o: init.cpp init.h
	$(CC) $(CFLAGS) -c init.cpp
io.o: io.cpp io.h
	$(CC) $(CFLAGS) -c io.cpp
jacobi.o: jacobi.cpp jacobi.h
	$(CC) $(CFLAGS) -c jacobi.cpp
main: main.o init.o io.o jacobi.o
	$(CC) -fopenmp -o main main.o init.o io.o jacobi.o
clean: 
	rm -f main init.o io.o jacobi.o
