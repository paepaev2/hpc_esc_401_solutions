# Exercise Session 10

---

## **Exercise 4 [Convolutions]**

---

```{bash}
[daint][mrojanap@daint-ln004 convol]$ ./a.out
Convolution took  0.006470 sec. on GPU
Convolution took  0.000000 sec. on CPU
PASSED
```

The GPU time includes kernel launch overhead but not memory allocation and transfer. For very small matrices, this overhead can make the GPU appear slower than the CPU.
