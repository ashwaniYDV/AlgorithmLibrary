// https://www.scaler.com/problems/kth-symbol/

/*
On the first row, we write a 0. Now in every subsequent row, we look at the previous row 
and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

Given row number A and index B, return the Bth indexed symbol in row A. (The values of B are 1-indexed.).

Problem Constraints
1 <= A <= 20
1 <= B <= 2^A - 1
*/



/*
When
A = 1 -> 0
A = 2 ->01
A = 3 ->0110

As we can see that there are two part in string (when A>=2)
first part is repeating of (A-1)th> step and second part is also compliment of (A-1)th step

for A = 3 -> first part - 01 ( it is same as when A == 2) second part- 10 ( compliment of when A == 2)

We know that on every expansion, the length of String is 2(A-1)

so what we can do when B value is <= mid we can search the result in first part of (A-1)th step solve(A-1, B)

and when B > mid we can search the result in (A-1)th step but compliment of that index to get the actual index in 1st part we have to do B - mid.
*/


int kthGrammar(int N, int K) {

  // Base Case

  if (N == 1) {
    return 0;
  }
  int n = pow(2, N - 1);
  int flag;
  // hypothesis design
  if (K <= n / 2) {
    flag = 0;
  } else {
    flag = 1;
    K = K - (n / 2);
  }
  // induction
  int ans = kthGrammar(N - 1, K);
  return (flag == 0) ? ans : !(ans);
}
int Solution::solve(int A, int B) {
  return kthGrammar(A, B);
}







public class Solution {
    public int solve(int A, int B) {
        return solveQ(A, B) ? 1 : 0;
    }
    static boolean solveQ(int n, int k) {

        if (n == 1 && k == 1)
            return false;

        int mid = (int) Math.pow(2, n - 1) / 2;

        if (k <= mid)
            return solveQ(n - 1, k);
        else
            return !solveQ(n - 1, k - mid);
    }
}
