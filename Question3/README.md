##Purpose of the Program 
Creating a sequence with the following operations: 
- If n is even, n = n/2 
- If n is odd, n = 3*n + 1 
Within the child process after using a fork system call. 

##To compile:  
gcc operation.c -o operation 
 
##To run:  
./operation n  
where n is a number 

##Example Result (if n = 35): 
35 106 53 160 80 40 20 10 5 16 8 4 2 1 