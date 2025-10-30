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
