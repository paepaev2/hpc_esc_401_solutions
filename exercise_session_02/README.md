# Exercise Session 02 #
In this session, you will compile and run your first programs on Eiger. This directory contains two versions of the code that were parallelized using MPI or OpenMP


**Exercise 2**

- module list: list all loaded modules
[eiger][mrojanap@eiger-ln001 exercise_session_02]$ module list

Currently Loaded Modules:
  1) craype-x86-rome                                 6) cce/17.0.0           11) perftools-base/23.12.0
  2) libfabric/1.22.0                                7) cray-dsmml/0.2.2     12) cpe/23.12
  3) craype-network-ofi                              8) cray-libsci/23.12.5  13) cray/23.12
  4) xpmem/2.9.6-1.1_20240510205610__g087dc11fc19d   9) cray-mpich/8.1.28
  5) PrgEnv-cray/8.5.0                              10) craype/2.7.30

- module avail: list all modules that can be loaded in the current environment
- module spider: list all modules, including dependencies and available versions


**Exercise 3**
- run sinfo:
[eiger][mrojanap@eiger-ln001 exercise_session_02]$ sinfo -p debug
PARTITION AVAIL JOB_SIZE  TIMELIMIT   CPUS  S:C:T   NODES STATE      NODELIST
debug     up    1-10          30:00    256 2:64:2       1 down*      nid002245
debug     up    1-10          30:00    256 2:64:2      11 idle       nid[002236-002244,002246-002247

To print only any user's job: squeue -u username

- To redirect output and error:
#SBATCH --output=output.log
#SBATCH --error=errors.log

- sbatch run_mpi.job
Process rank: 0
pi is approximately 3.1415926542564838, Error is 0.0000000006666907
Computed in 0.03795 seconds

- sbatch run_omp.job
pi is approximately 3.1415926542564683, Error is 0.0000000006666752
Computed in 0.1124 seconds

- squeue customized:
squeue -o "%i %u %p %a %j %D %t %r %S %L %Q"


**Exercise 4**
- OpenMP with OMP_NUM_THREADS=1 and 10
OMP_NUM_THREADS=1 
Thread rank: 0
pi is approximately 3.1415926542566006, Error is 0.0000000006668075
Computed in 4.449 seconds -> slower??

OMP_NUM_THREADS=10
Thread rank: 0
Thread rank: 3
Thread rank: 9
Thread rank: 8
Thread rank: 1
Thread rank: 6
Thread rank: 4
Thread rank: 5
Thread rank: 2
Thread rank: 7
pi is approximately 3.1415926542564856, Error is 0.0000000006666925
Computed in 0.4462 seconds

OMP_NUM_THREADS=1 is slower since there are less parallel jobs.

- Change -O3 to -O0 in the OpenMP version (Makefile) and run it again with 128 threads:
pi is approximately 3.1461132582725404, Error is 0.0045206046827473
Computed in 23.58 seconds

Flag -O0 is much slower than -O3 and the error is more off.




