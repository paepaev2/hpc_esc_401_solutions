// Using CUDA device to calculate pi - with configurable blocks and threads
#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
extern "C" double getTime(void);

#define NBIN 1000000000  // Number of bins

// Kernel that executes on the CUDA device
__global__ void cal_pi(double *sum, int nbin, double step, int nthreads, int nblocks) {
	int i;
	double x;
	int idx = blockIdx.x*blockDim.x+threadIdx.x;  // Sequential thread index across the blocks
	for (i=idx; i< nbin; i+=nthreads*nblocks) {
		x = (i+0.5)*step;
		sum[idx] += 4.0/(1.0+x*x);
	}
}

// Main routine that executes on the host
int main(int argc, char *argv[]) {
	// Read NUM_BLOCK and NUM_THREAD from command line arguments
	int NUM_BLOCK, NUM_THREAD;
	
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <NUM_BLOCK> <NUM_THREAD>\n", argv[0]);
		fprintf(stderr, "Example: %s 112 16\n", argv[0]);
		return 1;
	}
	
	NUM_BLOCK = atoi(argv[1]);
	NUM_THREAD = atoi(argv[2]);
	
	if (NUM_BLOCK <= 0 || NUM_THREAD <= 0) {
		fprintf(stderr, "Error: NUM_BLOCK and NUM_THREAD must be positive integers\n");
		return 1;
	}
	
	dim3 dimGrid(NUM_BLOCK,1,1);  // Grid dimensions
	dim3 dimBlock(NUM_THREAD,1,1);  // Block dimensions
	double *sumHost, *sumDev;  // Pointer to host & device arrays
	double pi = 0;
	int tid;

	double step = 1.0/NBIN;  // Step size
	size_t size = NUM_BLOCK*NUM_THREAD*sizeof(double);  //Array memory size
	sumHost = (double *)malloc(size);  //  Allocate array on host
	cudaMalloc((void **) &sumDev, size);  // Allocate array on device
   	double start = getTime();

	// Initialize array in device to 0
	cudaMemset(sumDev, 0, size);
	// Do calculation on device
	cal_pi <<<dimGrid, dimBlock>>> (sumDev, NBIN, step, NUM_THREAD, NUM_BLOCK); // call CUDA kernel
	// Retrieve result from device and store it in host array
	cudaMemcpy(sumHost, sumDev, size, cudaMemcpyDeviceToHost);
	for(tid=0; tid<NUM_THREAD*NUM_BLOCK; tid++)
		pi += sumHost[tid];
	pi *= step;

	// Print results
	double delta = getTime() - start;
	printf("Configuration: NUM_BLOCK=%d, NUM_THREAD=%d (Total threads=%d)\n", 
	       NUM_BLOCK, NUM_THREAD, NUM_BLOCK*NUM_THREAD);
	printf("PI = %.16g computed in %.4g seconds\n", pi, delta);
	
	// Cleanup
	free(sumHost);
	cudaFree(sumDev);

	return 0;
}
