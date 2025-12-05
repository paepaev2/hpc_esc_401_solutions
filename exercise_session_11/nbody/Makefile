# module load cray

nbody	: nbody.cpp Makefile
	CC -O3 -march=native -ffast-math -g -fopt-info-vec -o nbody nbody.cpp

clean:
	rm -f nbody nbody1 nbody2 nbody3
