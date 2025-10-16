# Exercise Session 04 #

<br>
**Exercise 1 [File permissions]** <br>
- All other users cannot access my $HOME directory, and vice versa <br>.
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
