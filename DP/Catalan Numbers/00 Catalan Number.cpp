/*
Find nth catalan number?
*/


// Method 1: RECURSIVE
long long catalanRecur(int n) {
  // Base case
  if (n <= 1)
    return 1;

  // catalan(n) is sum of catalan(i)*catalan(n-1-i)
  long long res = 0;
  for (int i = 0; i < n; i++)
    res += catalanRecur(i) * catalanRecur(n - 1 - i);

  return res;
}


// Method 2: DP
long long catalanDP(int n) {
  long long catalan[n + 1];

  catalan[0] = catalan[1] = 1;

  for (int i = 2; i <= n; i++) {
    catalan[i] = 0;
    for (int j = 0; j < i; j++)
      catalan[i] += catalan[j] * catalan[i - 1 - j];
  }

  return catalan[n];
}




/*
Cn= (2n)! / ((n+1)! n!)
*/


// Returns value of Binomial Coefficient C(n, k)
long long binomialCoeff(int n, int k) {
  long long res = 1;

  // Since C(n, k) = C(n, n-k)
  if (k > n - k)
    k = n - k;

  // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
  for (int i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }

  return res;
}

// A Binomial coefficient based function to find nth catalan number in O(n) time
long long catalanBinCof(int n) {
  // Calculate value of 2nCn
  long long c = binomialCoeff(2 * n, n);

  // return 2nCn/(n+1)
  return c / (n + 1);
}
