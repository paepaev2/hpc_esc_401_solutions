# Exercise Session 07

---

## **Exercise 1 [Pointers]**

---

Pointer are used extensively both in C and C++. Pointers are variables storing an address of some object (or other variable). Let us define a pointer p to be an integer array with length of 10 with the following values. <br>
`p` points to `[10, 20, 30, 40, 50, 60, 70, 80, 90, 100]`
<br>
### Answer the following questions: <br>
**a. What C/C++ type is `p`?**
> `int*`

**b. What is the type of `*p`?**
> `int`

**c. What is the type of `&p`?**
> `int**`

**d. What is the value of `*p`?**
> `10`

**e. What is the value of `p[0]`?**
> `10`

**f. What is the value of `p[3]`?**
> `40`

**g. What is the value of `*(p+5)`?**
> `60`

**h. What is the value of `*p+5`?**
> `15`

**i. In some languages (e.g. Python), `p[-1] = 42` sets the last (10th) element to 42. What does `p[-1] = 42` mean in C/C++?**
> `*(p-1) = 42`. This attempts to write the value 42 to the memory location preceding the start of the array `p` (out of bounds), resulting in **undefined behavior**

**j. Let: `int *q = p-1;` What is the value of `q[0]`? Careful!**
> **Undefined behavior**

**k. What is the value of `*(q+10)`?**
> `100`

**l. What is the value of `*(q+11)`?**
> **Undefined behavior**


---

## **Exercise 2 [More Pointers]**

---
<br>
### Answer the following questions: <br>
**a. What data type is M (integer, pointer to integer, . . . )?**
> pointer to pointer to integer (`int**`)

**b. What are `M`, `*M`, `**M`?**
> `M` (`int**`) = memory address where `M[0]` is stored
> `*M` (`int*`) = `M[0]`
> `**M` (`int`) = `M[0][0]` = `0` 

**c. What is M[1][3], *(M[0]+1), *(*(M+1)+3)?**
> `M[1][3]` = `8`
> `*(M[0]+1)` = `M[0][1]` = `1`
> `*(*(M+1)+3)` = `M[1][3]` = `8`

**d. Are the M[0] and M[1] arrays stored next to each other in the memory? In other words,
is it true that *(M[0]+5)==M[1][0]?**
> Not necessarily to be stored next to each other, and `*(M[0]+5)` results in `undefined behavior`


