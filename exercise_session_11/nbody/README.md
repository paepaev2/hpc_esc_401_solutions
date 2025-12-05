# Exercise Session 11

---

## **Exercise 1 [Introduction to Perftools-Lite]**

---

### **Which parts of the code took the most CPU time?**

From **Table 2 (Sample Profile by Group, Function, and Line):**

- **100% of CPU time** was spent in the `main` function, specifically inside the **`forces()`** function.
- Hot code paths:
  - **Line 38:** 2.9% (37 samples) — `auto dx = plist[j].x - plist[i].x;`
  - **Line 39:** 23.6% (302 samples) — `auto dy = plist[j].y - plist[i].y;`
  - **Line 40:** 56.7% (725 samples) — `auto dz = plist[j].z - plist[i].z;`
- **Total:**
  - **83.2%** spent on distance calculations (`dx`, `dy`, `dz`)
  - **16.8%** spent in STL vector operations

**Why this happens:**

1. **O(N²) complexity:**  
   `forces()` computes all pairwise interactions for **N = 50,000** particles → **2.5 billion operations**.

2. **Innermost loop dominates:**  
   Lines 38–40 run for every pair and frequently load data from memory.

3. **Memory bandwidth bottleneck:**  
   The code is **memory-bound**, not compute-bound.

4. **Execution time fits this behavior:**  
   The full computation takes **12.84 seconds**, consistent with quadratic scaling.

---

### **What you can learn about the performance of your code**

1. **Performance Hotspots**
   - Line 40 (dz): **56.7%**
   - Line 39 (dy): **23.6%**
   - Line 38 (dx): **2.9%**

2. **Why these lines dominate**
   - O(N²) → **2.5 billion** iterations.
   - **Memory-bound workload:** CPU waits for memory more than it computes.
   - **Poor cache locality:** Accessing `plist[j]` for each `i` is costly.
   - Line 40 shows the most samples likely due to repeated memory latency at that point.

3. **Energy Analysis**
   - Memory consumed **1,528 J (51% of total energy)**.
   - This confirms the program is **memory-bandwidth limited**, not CPU-limited.


---

## **Exercise 2 [Single and Double precision]**

---

- `sqrt`:
```bash
[eiger][mrojanap@eiger-ln003 nbody]$ time ./nbody

real	0m12.761s
user	0m12.753s
sys	0m0.004s
```

- `sqrtf`:
```bash
[eiger][mrojanap@eiger-ln003 nbody]$ time ./nbody

real	0m7.199s
user	0m7.191s
sys	0m0.005s
```

---

## **Exercise 3 [Vectorisation]**

---

- After adding -fopt-info-vec, the compiler reports:
    - Only STL library code (vector resize, random number generation) got vectorized
    - The critical forces() function loops (lines 42 and 44) were NOT vectorized
    - The compiler reports: "missed: couldn't vectorize loop" and "missed: data ref analysis failed"

- **No improvement in vectorization.** Even with the Structure of Arrays (SoA) layout providing contiguous memory access, the compiler still cannot auto-vectorize the force calculation loops
    - Data dependency analysis failure: the compiler cannot prove vectorization is safe
    - Complex control flow: the if (i==j) continue statement
    - Loop-carried dependencies: the reduction operations (ax += ... )
    - Complex arithmetic: sqrtf() and divisions combined with other factors

- Time the code: not expected
Timing: 7.104 seconds (no improvement from sqrtf version)
    - The SoA layout alone doesn't improve performance if vectorization doesn't happen
    - While SoA provides better memory layout (a prerequisite for SIMD), it doesn't guarantee vectorization
    - The compiler needs additional help (pragmas, intrinsics, or code restructuring) to vectorize this particular loop
    - Since 99% of runtime is in the non-vectorized forces() function, we see no speedup


---

## **Exercise 4 [Eliminate Divergence]**

---

```bash
[eiger][mrojanap@eiger-ln003 nbody]$ time ./nbody

real	0m1.530s
user	0m1.528s
sys	0m0.001s
```


