# Exercise Session 04 #

<br>
**Exercise 1 [File permissions]** <br>
- All other users cannot access my $HOME directory, and vice versa. <br>
Members in my group can read and execute my $SCRATCH directory, and not write. Other users don't have any permission on this directory. <br>
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ ls -ld $HOME <br>
drwx------ 2 mrojanap uzh8 4096 Oct 16 13:18 /users/mrojanap <br>
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ ls -ld $SCRATCH <br>
drwxr-x---+ 2 mrojanap uzh8 4096 Sep 18 11:23 /capstor/scratch/cscs/mrojanap <br>

- Default permission of newly created file is -rw-r--r-- <br>
[eiger][mrojanap@eiger-ln004 measured]$ ls -l $HOME <br>
total 0 <br>
drwx------ 2 mrojanap uzh8 4096 May  5  2010 bin <br>
-rw-r--r-- 1 mrojanap uzh8    0 Oct 16 13:31 ex04_create_new_file_permission.txt <br>
drwxr-xr-x 2 mrojanap uzh8 4096 Oct 16 13:03 hpc_esc_401_2025 <br>
drwxr-xr-x 2 mrojanap uzh8 4096 Oct 16 13:05 hpc_esc_401_solutions <br>
drwxr-xr-x 2 mrojanap uzh8 4096 Sep 19 14:25 plots <br>

- No. I don't have any permission on this directory (all read, write, and execute, also access and examine what files are inside). Only the owner is allowed to do so. <br>
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ ls -ld /users/meberlei <br>
drwx------ 2 meberlei uzh8 4096 Oct 15 11:28 /users/meberlei <br>

- Command used to set the access permissions for a directory so only the owner has (full) access: rwx------ = (4+2+1) || 0 || 0 <br>
chmod 700 file <br>

- Create a text file on $SCRATCH: <br>
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ cd $SCRATCH <br>
[eiger][mrojanap@eiger-ln004 mrojanap]$ touch group_can_write.txt <br>
[eiger][mrojanap@eiger-ln004 mrojanap]$ chmod 660 group_can_write.txt <br>
[eiger][mrojanap@eiger-ln004 mrojanap]$ ls -l group_can_write.txt <br>
-rw-rw----+ 1 mrojanap uzh8 0 Oct 16 13:48 group_can_write.txt <br>

- Create a file and set its permissions to 000: <br>
I cannot read, write, or execute it. However, it's not lost. I can still change its permission so that I can have an access again. <br>
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ touch permission_000.txt <br>
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ chmod 000 permission_000.txt <br>
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ cat permission_000.txt <br>
cat: permission_000.txt: Permission denied <br>
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ vim permission_000.txt <br>
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ chmod 700 permission_000.txt <br>
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ cat permission_000.txt <br>
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ vim permission_000.txt <br>
[eiger][mrojanap@eiger-ln004 exercise_session_04]$ cat permission_000.txt <br>
permission = 700 <br>

<br>
**Exercise 2 [Bash scripting 1 - Regex - grep]** <br>
- Regex
1) end with 00: grep 00$ binary.txt
2) start and end with 1: grep ^1.\*1$ binary.txt
3) contain the pattern 110: grep .\*110.\* binary.txt
4) contain at least three times a 1: grep .\*1.\*1.\*1.\* binary.txt
5) contain at least three consecutive 1s: grep .\*111.\* binary.txt



