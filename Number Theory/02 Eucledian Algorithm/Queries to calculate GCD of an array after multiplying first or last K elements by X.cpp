// https://www.geeksforgeeks.org/queries-to-calculate-gcd-of-an-array-after-multiplying-first-or-last-k-elements-by-x/

/*
Efficient Approach: The above approach can be optimized by storing the prefix and suffix GCD arrays of the given array 
and solving each query in O(1) time by following the below steps:

Initialize an array prefix[] and suffix[] of size N to store the prefix and suffix GCD arrays of the given array.
Traverse the array from the front and the back and find the prefix and suffix GCD at each index and store it in prefix[] and suffix[] respectively.
Now, traverse the array queries[] and for each query {a, K, X} perform the following:
If the value of K is N then print the value of prefix[N – 1] * X as the result.
If the value of a is 1, then find the GCD of prefix[K – 1] * X and suffix[K] as the result as the prefix[K – 1] * X is the new GCD of first K numbers and suffix[K + 1] is the GCD of the remaining array elements.
If the value of a is 2, then find the GCD of prefix[N – K – 1] and suffix[N – K] * X as the result as the prefix[N – K – 1] * X is the new GCD of first K numbers and suffix[N – K] is the GCD of the remaining array elements.
*/
