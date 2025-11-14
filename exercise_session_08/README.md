# Exercise Session 08

---

## **Exercise 1 [Compute PI - OpenACC]**

---

```bash
PI = 3.141592653589793 computed in 2.844 seconds
PI = 3.141592653589793 computed in 0.001147 seconds
PI = 3.141592653589793 computed in 0.001139 seconds
PI = 3.141592653589793 computed in 0.001136 seconds
PI = 3.141592653589793 computed in 0.001135 seconds
```

No, each iteration does not have the same runtime.
The first iteration is significantly slower due to the GPU initialization.


---

## **Exercise 2 [Compute PI - CUDA]**

---

```bash
PI = 3.14159265358979 computed in 0.04896 seconds
```

The execution time is not the same with the result from exercise 1 since there is a difference between GPU initialization for OpenAcc and kernel compilation for CUDA.


---

## **Exercise 3 [CUDA - Blocks and Threads per Block]**

---

- As the number of threads or blocks increase, execution time decreases because more parallel work is being done and the GPU utilization is more efficiently done.
- Performance improves rapidly at first, then saturate due to the overhead of between-thread comminucation and poor cache performance within the thread.



