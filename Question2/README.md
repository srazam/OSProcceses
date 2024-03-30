##Purpose of Program 
Forking a child process until it becomes a zombie process and will stay in the system for about 15 seconds. 

##To compile: 
gcc process.c -o process 

##To run the program in the background: 
Enter: ./process& 
Enter: ps -l 

##Results: 
In the "S" column of the table, you should see a "Z", indicating that that process is a child. The process ID is the respective PID and the parent of that process ID is the respective PPID. The table will look like so: 

F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD 

0 S  1000     688     507  0  80   0 -  1691 do_wai pts/4    00:00:00 bash 

0 S  1000    3316     688  0  80   0 -   694 hrtime pts/4    00:00:00 process 

1 Z  1000    3318    3316  0  80   0 -     0 -      pts/4    00:00:00 process <defunct> <- Zomebie process 

0 R  1000    3362     688  0  80   0 -  1871 -      pts/4    00:00:00 ps 

##Important Note 
Make sure to kill the zombie process to ensure that not too many zombie's exist in the system. Enter the following in the terminal: 

kill -9 PPID 