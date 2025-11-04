# Exercise Session 06

---

## **Exercise 1 [Ring and deadlocks]**

---

- `MPI Ssend` and `MPI Recv` <br>
Nothing is printed when running the code because of the deadlock. Every process is stuck waiting for the next process in the ring, but that next process is also stuck waiting. No one can ever proceed to their `MPI_Recv` call, so the entire program hangs forever.
- Divided the processes into `even` and `odd` group. <br>
```bash
[eiger][mrojanap@eiger-ln001 ring_and_deadlocks]$ srun -n 4 ./ring_1
I am processor 0 out of 4, and the sum is 6
I am processor 2 out of 4, and the sum is 6
I am processor 3 out of 4, and the sum is 6
I am processor 1 out of 4, and the sum is 6
```
This solved the deadlock problem because even ranks send first (to odd ranks on thier right), while odd ranks receive first (ready to accept from even ranks on their left). This breaks the circular wait condition since at least some send/receive pairs can complete, allowing the communication to progress. <br>
It's not an optimal solution because it serializes the communication; only half the processes can communicate simultaneously. The even processes can't receive until their send is done, and the odd processes can't send until their receive is done. <br>
- `Irecv-Isend-Waitall` and `Isend-Irecv-Waitall` are better than synchronous communication in this problem because it eliminates the circular wait. After each process proposes its requests, all requests are performed simultaneously without waiting for another process to start a call.


---

## **Exercise 2 [π revisited]**

---

```bash
[eiger][mrojanap@eiger-ln001 exercise_session_06]$ srun -n 128 ./pi
srun: job 5897752 queued and waiting for resources
srun: job 5897752 has been allocated resources
Approximated value of pi = 3.141593
```

---

## **Exercise 3 [MPI Poisson solver]**

---

```{bash}
[eiger][mrojanap@eiger-ln004 poisson_MPI]$ grep "Step " log_1_proc.txt | tail -n 1
Step 19366, Diff=9.99451e-09
[eiger][mrojanap@eiger-ln004 poisson_MPI]$ grep "Step " log_4_proc.txt | tail -n 1
Step 19366, Diff=9.99451e-09
[eiger][mrojanap@eiger-ln004 poisson_MPI]$ grep "Step " log_128_proc.txt | tail -n 1
Step 19366, Diff=9.99451e-09
```
- Performance: <br>
`n=1` <br>
- real	0m14.077s
- user	0m0.035s
- sys	0m0.235s
<br>
`n=4` <br>
- real	0m16.886s
- user	0m0.059s
- sys	0m0.620s
<br>
`n=128` <br>
-real	1m18.292s
-user	0m1.706s
-sys	0m16.442s
<br>
Adding more processes makes the program run slower because of a performance bottleneck from communication time. Even though the computation time reduces, it is not enough to pay for the cost of increased communication.
