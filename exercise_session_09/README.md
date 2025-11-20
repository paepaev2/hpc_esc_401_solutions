# Exercise Session 09

---

## **Exercise 1 [axpy]**

---

See the result in `./axpy/output_axpy_openacc.log`
- CPU time increases as the problem size increases.
- GPU time is constant ~ `2.5 - 2.8` s and more than the CPU time due to the initialization overhead.


---

## **Exercise 2 [basics/blur]**

---

- The problem with `blur_twice_gpu_naive`:
    - The compiler tries to execute the loop on the GPU, but the arrays in, out, and buffer are host CPU pointers. The GPU tries to access memory addresses that don't exist in its memory space, causing the illegal address error. 
    - The data is copied to the GPU, processed, and copied back to the CPU `twice` in each iteration of the outer loop because there are 2 separated inner loops without keeping the data on the GPU.

- `blur_twice_gpu_nocopies`: Keep the data (`in`, `out`, `buffer`) on the GPU for the entire duration of all iterations, so the data is copied to the GPU `once` at the beginning and copied back `once` at the end while the naive implementation does `twice`.

- Execution time
    - For small size problems: The GPU overhead dominates, making CPU faster.
    - For large size problems: The GPU's parallel processing overcomes the overhead, making significant speedups compared to CPU.
