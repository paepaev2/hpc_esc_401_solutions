 # Exercise Session 05

---

## **Exercise 1 [Serial 2D Poisson solver]**

---

- `init_f` <br>
Initializes the main f by setting the fixed boundary condition values on the grid's edges and filling the interior points with the problem's source term. <br>
- `jacobi_step` <br>
Performs a single iteration by assigning the old solution (`u_old`) with `u_new` and applying the Jacobi formula to calculate a new solution (`u_new`) for all interior points. <br>
- `norm_diff` <br>
Compares the `u_new` and `u_old` by calculating their difference to see if the solution has converged (the change is small enough to stop). <br>


---

## **Exercise 3 [OpenMP and race conditions]**

---

- `#pragma omp parallel for` in first and second loop
```bash
[eiger][mrojanap@eiger-ln002 race_conditions]$ gcc -fopenmp parallel.c -o parallel
[eiger][mrojanap@eiger-ln002 race_conditions]$ ./parallel
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 17056
true number of 0s in file: 646016
```
The counted number of zeros are wrong almost every time.
