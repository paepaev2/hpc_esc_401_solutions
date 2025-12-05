# Exercise Session 11

---

## **Exercise 1 [Introduction to Perftools-Lite]**

---

- Which parts of the code took the most CPU time?
From Table 2 (Sample Profile by Group, Function, and Line):

100% of CPU time was spent in the main function (specifically the forces function call)
Within the hot code paths:
Line 38: 2.9% (37 samples) - auto dx = plist[j].x - plist[i].x;
Line 39: 23.6% (302 samples) - auto dy = plist[j].y - plist[i].y;
Line 40: 56.7% (725 samples) - auto dz = plist[j].z - plist[i].z;
Combined: 83.2% in the distance calculation
16.8% in STL vector operations

This makes sense because
1. O(N^2) complexity: The forces() function has nested loops computing all pairwise interactions for N=50,000 particles, resulting in 2.5 billion operations
2. Lines 38-40 dominate because they're in the innermost loop and involve memory accesses to plist[j] and plist[i]
3. Memory bandwidth: The code is memory-bound, repeatedly accessing particle data from different memory locations
4. Execution time: 12.84 seconds for a simple calculation indicates the quadratic scaling

- What you can learn about the performance of your code
1. Performance Hotspot: 83.2% of CPU time is spent in the forces() function's nested loop:
Line 40 (dz calculation): 56.7% of samples
Line 39 (dy calculation): 23.6% of samples
Line 38 (dx calculation): 2.9% of samples
2. Why These Lines Dominate:
- The O(N^2) algorithm performs 2.5 billion pairwise calculations (50,000^2)
- Memory-bound workload: The CPU spends most time waiting for data from memory
- Poor cache locality due to random access patterns in the nested loop
- Line 40 shows highest samples because it's where memory latency becomes most visible
3. Energy Analysis:
- Memory consumed 1,528 J (51% of total energy)
- This confirms the code is memory-bandwidth limited, not compute-limited
