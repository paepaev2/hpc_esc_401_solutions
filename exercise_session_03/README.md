# Exercise Session 03 #
In this session, you will work on modularization of the code and compilation optimization. Moreover, you will parallelize a simple code and successively plot its speedup. 

In this folder you can find:

* cpi.c : the serial version of last week parallel code, needed for Exercise 1
* cpi_mpi.c : the MPI version of cpi code, for Exercise 1
* sum.c : the code needed for Exercise 2 

<br>
**Exercise 1 [Linking]** <br>
[eiger][mrojanap@eiger-ln001 exercise_session_03]$ srun cpi_mpi <br>
srun: job 5733979 queued and waiting for resources <br>
srun: job 5733979 has been allocated resources <br>
Process rank: 0 <br>
pi is approximately 3.1415926555899709, Error is 0.0000000020001778 <br>
Computed in 1.484 seconds <br>
Total execution time (including MPI): 1.616 seconds <br>

> The 2 execution times (1.484 and 1.616 seconds) are different because the second one includes the MPI overhead (e.g., MPI_Init and MPI_Finalize).

<br>
**Exercise 2 [Compiler optimization]** <br>
[eiger][mrojanap@eiger-ln001 exercise_session_03]$ srun sum_O0 <br>
srun: job 5734624 queued and waiting for resources <br>
srun: job 5734624 has been allocated resources <br>
sum=10022429073.341873 <br>
Execution time: 4.925 seconds <br>
[eiger][mrojanap@eiger-ln001 exercise_session_03]$ srun sum_O1 <br>
srun: job 5734649 queued and waiting for resources <br>
srun: job 5734649 has been allocated resources <br>
sum=10022429073.341873 <br>
Execution time: 1.98 seconds <br>
[eiger][mrojanap@eiger-ln001 exercise_session_03]$ srun sum_O2 <br>
srun: job 5734650 queued and waiting for resources <br>
srun: job 5734650 has been allocated resources <br>
sum=10022429073.341873 <br>
Execution time: 1.092 seconds <br>
[eiger][mrojanap@eiger-ln001 exercise_session_03]$ srun sum_O3 <br>
srun: job 5734662 queued and waiting for resources <br>
srun: job 5734662 has been allocated resources <br>
sum=10022429073.341873 <br>
Execution time: 1.087 seconds <br>

- The other ways to get timings: /usr/bin/time -v ./sum_Ox
- How big is the difference in execution time: The significant difference happened between O0 and O2. O3 gave essentially no extra benefit since its execution time is aroud O2.
- How did the compiler optimize the code: <br>
*At -O1*, the compiler simplified expressions and removed obvious redundancies. <br>
*At -O2*, it applied loop optimizations and vectorization (SIMD with AVX2), giving the biggest speedup. <br>
*At -O3*, extra unrolling/inlining were tried, but they didn’t improve runtime beyond what -O2 already achieved.
- To make it faster: improve algorithm, parallelize across cores using OpenMP



