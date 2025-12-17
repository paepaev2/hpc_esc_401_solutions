# Exercise Session 13

---

## **Exercise 2 [Map&reduce]**

---

- How many map and reduction operations were performed? <br>
  `Launched map tasks=7` <br>
  `Launched reduce tasks=1`
- How many lines/entries were treated? <br>
  `Map input records=35371` <br>
  `Map output records=538568` <br>
  `Reduce input records=538568` <br>
  `Reduce output records=47090`
- Which output folder(s)/file(s) were created?
  ```{bash}
  ubuntu@pae-hadoop:~/hpc_esc_401_2025/exercise_session_13$ hadoop fs -ls output
  Found 2 items
  -rw-r--r--   3 ubuntu supergroup          0 2025-12-17 23:09 output/_SUCCESS
  -rw-r--r--   3 ubuntu supergroup     642476 2025-12-17 23:09 output/part-00000
  ```
- Find the file containing the information about the word counts and have a look on the results of map&reduce operation.
  ```{bash}
  ubuntu@pae-hadoop:~/hpc_esc_401_2025/exercise_session_13$ hadoop fs -cat output/part-00000 | head
  0	10
  00	1
  000	6
  000he	1
  000hermansjr000	4
  007cigarjoe	1
  007llisav	4
  00patriot	1
  00rstw00	2
  01101o10	1
  ```
  ```{bash}
  ubuntu@pae-hadoop:~/hpc_esc_401_2025/exercise_session_13$ hadoop fs -cat output/part-00000 | tail
  🙏🏻	1
  🙏🙏🙏	1
  🚀	1
  🚂	1
  🚂☁🇺🇸🇺🇸	1
  🚂🇺🇸🎈	1
  🚂💨💨🇺🇸🇺🇸🇺🇸	1
  🚨breaking🚨	2
  🦃	1
  􏰀	1
  ```
- Visit the hadoop api from your local machine. Can you find the output files?
  <img width="1459" height="556" alt="Screenshot 2568-12-18 at 00 29 31" src="https://github.com/user-attachments/assets/0492216f-b31f-439b-aad3-a235a9810d77" />
