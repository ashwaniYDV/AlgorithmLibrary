// https://www.geeksforgeeks.org/dyck-path/

/*
Consider a n x n grid with indexes of top left corner as (0, 0). 
Dyck path is a staircase walk from bottom left, i.e., (n-1, 0) to top right, i.e., (0, n-1) 
that lies above the diagonal cells (or cells on line from bottom left to top right).
The task is to count the number of Dyck Paths from (n-1, 0) to (0, n-1).

Examples : 

Input : n = 1
Output : 1

Input : n = 2
Output : 2

Input : n = 3
Output : 5

Input : n = 4
Output : 14
*/
