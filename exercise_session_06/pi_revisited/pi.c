#include "mpi.h"
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);

    int nproc, my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    const long long N = 1000000000;
    long double my_sum = 0.0;
    long double global_sum = 0.0;

    long long my_start = my_rank * (N / nproc);
    long long my_end = (my_rank + 1) * (N / nproc);
    if (my_rank == nproc-1) my_end = N;

    for (long long i=my_start; i<my_end; i++) {
	if (i % 2 == 0) my_sum += 1.0 / (2 * i + 1);
	else my_sum -= 1.0 / (2 * i + 1); 
    }

    MPI_Reduce(&my_sum, &global_sum, 1, MPI_LONG_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (my_rank == 0) {
	long double pi = global_sum * 4.0;
	printf("Approximated value of pi = %Lf \n", pi);
    }

    MPI_Finalize();
}
