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
