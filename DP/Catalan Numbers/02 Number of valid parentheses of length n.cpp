/*
Find the total number of valid parenthesis expressions of length N.

For N=6, we have the following 5 valid parentheses expressions.

( ( ( ) ) )
( ( ) ( ) )
( ( ) ) ( )
( ) ( ( ) )
( ) ( ) ( )
*/

/*
This is mainly an application of Catalan Numbers.
Total possible valid expressions for input n is:
n/2’th Catalan Number if n is even, and
0 if n is odd.
*/

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

unsigned long int findWays(unsigned n) {
  if (n & 1) return 0;
  return catalanDP(n / 2);
}





// Method 2
int ans = 0;
int helper(int left, int right) {
  if (left == 0 && right == 0) {
    ans++;
  }
  if (left > right) {
    return 0;
  }

  if (left > 0) {
    helper(left - 1, right);
  }
  if (right > 0) {
    helper(left, right - 1);
  }
  return ans;
}

int Validparentheses(int n) {
  if (n % 2) return 0;
  return helper(n / 2, n / 2);
}