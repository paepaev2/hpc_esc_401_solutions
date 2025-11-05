# Exercise Session 07

---

## **Exercise 1 [Pointers]**

---

Pointer are used extensively both in C and C++. Pointers are variables storing an address of some object (or other variable). Let us define a pointer p to be an integer array with length of 10 with the following values.
p 10 20 30 40 50 60 70 80 90 100
<br>
Answer the following questions: <br>
a. What C/C++ type is p?
> int*
b. What is the type of \*p?
> int
c. What is the type of &p?
> int**
d. What is the value of \*p?
> 10
e. What is the value of p[0]?
> 10
f. What is the value of p[3]?
> 40
g. What is the value of \*(p+5)?
> 60
h. What is the value of \*p+5?
> 15
i. In some languages (e.g. Python), p[-1] = 42 sets the last (10th) element to 42.
What does p[-1] = 42 mean in C/C++?
> `*(p-1) = 42` try to  write the value 42 to the memory location preceding the start of an array `p` (out of bounds), hence `undefined`
j. Let: int \*q = p-1;
What is the value of q[0]. Careful!
> undefined
k. What is the value of \*(q+10)?
> 100
l. What is the value of \*(q+11)?
> undefined
