cpi: cpi.o gettime.o
	gcc -o cpi cpi.o gettime.o
cpi.o: cpi.c gettime.h
	gcc -O3 -ffast-math -mavx2 -c -o cpi.o cpi.c
gettime.o: gettime.c gettime.h
	gcc -O3 -ffast-math -mavx2 -c -o gettime.o gettime.c
cpi_mpi: cpi_mpi.o gettime.o
	mpicc -o cpi_mpi cpi_mpi.o gettime.o
cpi_mpi.o: cpi_mpi.c gettime.h
	mpicc -O3 -ffast-math -mavx2 -c -o cpi_mpi.o cpi_mpi.c
all: cpi cpi_mpi
clean:
	rm -f cpi cpi.o gettime.o cpi_mpi cpi_mpi.o
