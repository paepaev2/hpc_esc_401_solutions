#include "mpi.h"
#include <stdio.h>
#include "init.h"

int start_MPI(int* my_rank, int* size){
	printf("Setting MPI environment\n");
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,size);
	MPI_Comm_rank(MPI_COMM_WORLD,my_rank);

	return 0;
}

int close_MPI(){
	MPI_Finalize();
	return 0;
}

int mpi_get_domain(int nx, int ny, int my_rank, int size, int* min_x, int* max_x, int* min_y, int* max_y){
    // Method II: Share remnant

    int slice_size = nx / size;
    int remnant = nx % size;

    if (my_rank < remnant) {
	*min_x = my_rank * (slice_size + 1);
	*max_x = *min_x + (slice_size + 1);
    } else {
	*min_x = remnant * (slice_size + 1) + (my_rank - remnant) * slice_size;
	*max_x = *min_x + slice_size;
    }

    *min_y = 0;
    *max_y = ny;

    printf("in mpi_get_domain() in mpi_module.cpp,  define corners of the local domains\n");

    printf("I am rank %d and my domain is: xmin, xmax, ymin, ymax: %d %d %d %d\n",my_rank,*min_x,*max_x,*min_y,*max_y);
    return 0;
}

int halo_comm(params p, int my_rank, int size, double** u, double* fromLeft, double* fromRight){
    // Method II: Use non-blocking MPI_Isend, MPI_Irecv, and MPI_Waitall

    int rank_left = (my_rank == 0) ? MPI_PROC_NULL : my_rank - 1;
    int rank_right = (my_rank == size - 1) ? MPI_PROC_NULL : my_rank + 1;

    double* column_to_right = new double [p.ymax - p.ymin];
    for (int j=0;j<(p.ymax - p.ymin);j++) column_to_right[j] = u[p.xmax - p.xmin - 1][j]; 
    double* column_to_left = new double [p.ymax - p.ymin];
    for (int j=0;j<(p.ymax - p.ymin);j++) column_to_left[j] = u[0][j]; 

    MPI_Request requests[4];
    
    MPI_Irecv(fromLeft, p.ymax - p.ymin, MPI_DOUBLE, rank_left, 1, MPI_COMM_WORLD, &requests[0]);
    MPI_Irecv(fromRight, p.ymax - p.ymin, MPI_DOUBLE, rank_right, 0, MPI_COMM_WORLD, &requests[1]);

    MPI_Isend(column_to_left, p.ymax - p.ymin, MPI_DOUBLE, rank_left, 0, MPI_COMM_WORLD, &requests[2]);
    MPI_Isend(column_to_right, p.ymax - p.ymin, MPI_DOUBLE, rank_right, 1, MPI_COMM_WORLD, &requests[3]);

    MPI_Waitall(4, requests, MPI_STATUSES_IGNORE);

    free(column_to_right);
    free(column_to_left);

    printf("mpi_module.cpp, define halo comm:  \n");
    return 0;
}


int ALLREDUCE(double* loc_diff, double* loc_sumdiff){

	MPI_Allreduce(loc_diff, loc_sumdiff, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
	return 0;

	}

