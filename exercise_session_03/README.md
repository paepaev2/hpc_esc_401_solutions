# Exercise Session 03 #
In this session, you will work on modularization of the code and compilation optimization. Moreover, you will parallelize a simple code and successively plot its speedup. 

In this folder you can find:

* cpi.c : the serial version of last week parallel code, needed for Exercise 1
* cpi_mpi.c : the MPI version of cpi code, for Exercise 1
* sum.c : the code needed for Exercise 2 


**Exercise 1 [Linking]**
[eiger][mrojanap@eiger-ln001 exercise_session_03]$ srun cpi_mpi
srun: job 5733979 queued and waiting for resources
srun: job 5733979 has been allocated resources
Process rank: 0
pi is approximately 3.1415926555899709, Error is 0.0000000020001778
Computed in 1.484 seconds
Total execution time (including MPI): 1.616 seconds

The 2 execution times (1.484 and 1.616 seconds) are different because the second one includes the MPI overhead (e.g., MPI_Init and MPI_Finalize).
