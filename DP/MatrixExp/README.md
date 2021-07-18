# Matrix Exponentiation

## Theory
* It is used to solve some linear recurrences.
* Eg: fib[n] = fib[n - 1] + fib[n - 2] 

```
Eg: Linear recurrence is given as follows:-
         n
F(n)  =  ∑ F(n-i)  = F(n-1) + F(n-2) + ... + F(1) + F(0) 
        i=1

F[X] = T * F[X-1]
(T = transaformation matrix)

|F(n+1)|   |1 1 1 1 1 1|   | F(n) |   
| F(n) |   |1 0 0 0 0 0|   |F(n-1)|
|F(n-1)| = |0 1 0 0 0 0| * |   .  |
|   .  |   |0 0 1 0 0 0|   |   .  |
|   .  |   |0 0 0 1 0 0|   |   .  |
| F(1) |   |0 0 0 0 1 0|   | F(0) |

|F6|   |1 1 1 1 1 1|   |F5|   
|F5|   |1 0 0 0 0 0|   |F4|
|F4| = |0 1 0 0 0 0| * |F3|
|F3|   |0 0 1 0 0 0|   |F2|
|F2|   |0 0 0 1 0 0|   |F1|
|F1|   |0 0 0 0 1 0|   |F0|

Time Complexity = O(M^3 * log(N))
(M = size of transformation matrix)
```


## Resources
* [Utkarsh Gupta Unacademy](https://unacademy.com/class/matrix-exponentiation-and-matrix-operations/VOM2NSM6)