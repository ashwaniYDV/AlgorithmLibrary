// https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679

/*
You are given two positive integers 'n' and 'm'. 
You have to return the 'nth' root of 'm', i.e. 'm(1/n)'. 
If the 'nth root is not an integer, return -1.

Input: ‘n’ = 3, ‘m’ = 27
Output: 3
Explanation: 3rd Root of 27 is 3, as (3)^3 equals 27.
*/


int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
  int lo = 1, hi = m;
  while(lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int check = func(mid, n, m);

      if(check == 1) return mid;

      if(check == 0) {
          lo = mid + 1;
      } else {
          hi = mid - 1;
      }
  }

  return -1;
}




// this will not work since it will iverflow
int binExp(int a, int b) {
  long long res = 1;
  while(b) {
    if (b & 1) res *= a;
      a *= a;
      b /= 2;
  }
  return res;
}

int NthRoot(int n, int m) {
  int lo = 1, hi = m;
  while(lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int midPowN = binExp(mid, n);

      if(midPowN == m) return mid;

      if(midPowN < m) {
          lo = mid + 1;
      } else {
          hi = mid - 1;
      }
  }

  return -1;
}