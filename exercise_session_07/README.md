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

### Answer the following questions: <br>
**a. What data type is M (integer, pointer to integer, . . . )?**
> pointer to pointer to integer (`int**`)

**b. What are `M`, `*M`, `**M`?**
> - `M` (`int**`) = memory address where `M[0]` is stored
> - `*M` (`int*`) = `M[0]`
> - `**M` (`int`) = `M[0][0]` = `0`

**c. What is `M[1][3]`, `*(M[0]+1)`, `*(*(M+1)+3)`?**
> - `M[1][3]` = `8`
> - `*(M[0]+1)` = `M[0][1]` = `1`
> - `*(*(M+1)+3)` = `M[1][3]` = `8`

**d. Are the `M[0]` and `M[1]` arrays stored next to each other in the memory? In other words,
is it true that `*(M[0]+5)==M[1][0]`?**
> Not necessarily to be stored next to each other, and `*(M[0]+5)` results in `undefined behavior`


---

## **Exercise 3 [Array strides]**

---

### Answer the following questions: <br>
**a. Which variable (x or y) tells you which row it is, and which tells you the column?**
> - row: `y`
> - column: `x`

**b. How many total elements are in the table?**
> 6\*14 = `84`

**c. Are the elements (1, 3) and (1, 4) adjacent in memory, or is it rather (1, 3) and (2, 3)?**
> - row-major: (1, 3) and (1, 4) are adjacent
> - column-major: (1, 3) and (2, 3) are adjacent

**d. Is one of these choices “better”? Why or why not?**
> Neither is generally better. It depends on how data is frequently accessed, `row by row` or `column by column`

**e. From now on assume “row-major” order, meaning that elements in each row are adjacent to each other. The “stride” tells you the distance between elements in the given direction. What is the stride for the x dimension?**
> 1

**f. What is the stride of the y dimension?**
> 14

**g. Remember again that elements are stored adjacent in memory. Assume that rows are stored adjacent to each other. This means that if you have a table of integers (`int *A`) then the element (0, 0) is at A[0], element (0, 1) is at A[1] and so on. Where is element (0, 10)?**
> A[10]

**h. Where is element (3, 0)?**
> A[42]

**i. Where is element (7, 4)?**
> `out of bounds`
