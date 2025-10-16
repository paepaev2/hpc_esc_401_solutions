 # Exercise Session 04

---

## **Exercise 1 [File permissions]**

---

- All other users cannot access my `$HOME` directory, and vice versa.  
  Members in my group can read and execute my `$SCRATCH` directory, but not write. Other users have no permission on this directory.

```bash
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ ls -ld $HOME
drwx------ 2 mrojanap uzh8 4096 Oct 16 13:18 /users/mrojanap
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ ls -ld $SCRATCH
drwxr-x---+ 2 mrojanap uzh8 4096 Sep 18 11:23 /capstor/scratch/cscs/mrojanap
```

- Default permission of newly created file is `-rw-r--r--`

```bash
[eiger][mrojanap@eiger-ln004 measured]$ ls -l $HOME
total 0
drwx------ 2 mrojanap uzh8 4096 May  5  2010 bin
-rw-r--r-- 1 mrojanap uzh8    0 Oct 16 13:31 ex04_create_new_file_permission.txt
drwxr-xr-x 2 mrojanap uzh8 4096 Oct 16 13:03 hpc_esc_401_2025
drwxr-xr-x 2 mrojanap uzh8 4096 Oct 16 13:05 hpc_esc_401_solutions
drwxr-xr-x 2 mrojanap uzh8 4096 Sep 19 14:25 plots
```

- No. I don't have any permission on /users/meberlei directory (all read, write, and execute, also access and examine what files are inside). Only the owner is allowed to do so.

```bash
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ ls -ld /users/meberlei
drwx------ 2 meberlei uzh8 4096 Oct 15 11:28 /users/meberlei
```

- Command used to set the access permissions for a directory so only the owner has (full) access:  
  `rwx------ = (4+2+1) || 0 || 0`

```bash
chmod 700 file
```

- Create a text file on $SCRATCH:

```bash
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ cd $SCRATCH
[eiger][mrojanap@eiger-ln004 mrojanap]$ touch group_can_write.txt
[eiger][mrojanap@eiger-ln004 mrojanap]$ chmod 660 group_can_write.txt
[eiger][mrojanap@eiger-ln004 mrojanap]$ ls -l group_can_write.txt
-rw-rw----+ 1 mrojanap uzh8 0 Oct 16 13:48 group_can_write.txt
```

---

- Create a file and set its permissions to 000: I cannot read, write, or execute it. However, it's not lost. I can still change its permission so that I can have an access again.

```bash
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ touch permission_000.txt
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ chmod 000 permission_000.txt
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ cat permission_000.txt
cat: permission_000.txt: Permission denied
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ vim permission_000.txt
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ chmod 700 permission_000.txt
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ cat permission_000.txt
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ vim permission_000.txt
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ cat permission_000.txt
permission = 700
```

---

## **Exercise 2 [Bash scripting 1 - Regex - grep]**

---

- Regex binary.txt

1. End with 00:  
   ```bash
   grep 00$ binary.txt
   ```
2. Start and end with 1:  
   ```bash
   grep ^1.*1$ binary.txt
   ```
3. Contain the pattern 110:  
   ```bash
   grep .*110.* binary.txt
   ```
4. Contain at least three times a 1:  
   ```bash
   grep .*1.*1.*1.* binary.txt
   ```
5. Contain at least three consecutive 1s:  
   ```bash
   grep .*111.* binary.txt
   ```

---

## **Exercise 3 [Bash scripting 2 - Is this a prime number?]**

---

- `factor` command: prints prime factors of the input integer
- Output of `factor` command: INPUT_INTEGER: LIST_OF_ITS_PRIME_FACTORS
- 20 vs 31: more than one factor and only one factor, which is itself
```bash
[eiger][mrojanap@eiger-ln001 measured]$ factor 20
20: 2 2 5
[eiger][mrojanap@eiger-ln001 measured]$ factor 31
31: 31
```
- Measure e code performance
```bash
[eiger][mrojanap@eiger-ln001 measured]$ time ./isprime 4230283
4230283 is prime

real	0m0.014s
user	0m0.005s
sys	0m0.008s
[eiger][mrojanap@eiger-ln001 measured]$ time ./isprime 4572862171001
4572862171001 is prime

real	0m0.011s
user	0m0.004s
sys	0m0.007s
```
 
