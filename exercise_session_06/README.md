# Exercise Session 06

---

## **Exercise 1 [Ring and deadlocks]**

---

- `MPI Ssend` and `MPI Recv` <br>
Nothing is printed when running the code because of the deadlock. Every process is stuck waiting for the next process in the ring, but that next process is also stuck waiting. No one can ever proceed to their `MPI_Recv` call, so the entire program hangs forever.
