serial_from_omp: parallel.c
	gcc parallel.c -o serial_from_omp
parallel: parallel.c
	gcc -fopenmp parallel.c -o parallel
serial: serial.c
	gcc serial.c -o serial
clean: 
	rm -f serial serial_from_omp parallel
