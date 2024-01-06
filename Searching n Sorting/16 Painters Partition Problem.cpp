// https://www.scaler.com/problems/painters-partition-problem

/*
Given 2 integers A and B and an array of integers C of size N. Element C[i] represents the length of ith board.
You have to paint all N boards [C0, C1, C2, C3 … CN-1]. 
There are A painters available and each of them takes B units of time to paint 1 unit of the board.
Calculate and return the minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of the board.

NOTE:
a) 2 painters cannot share a board to paint. That is to say, a board cannot be painted partially by one painter, and partially by another.
b) A painter will only paint contiguous boards. This means a configuration where painter 1 paints boards 1 and 3 but not 2 is invalid.
*/

const int mod = 10000003;
bool check(long long A, long long B, vector < int > & C, long long mid) {
   long long cnt = 1;
   long long n = C.size();
   long long tmp = 0;
   for (int i = 0; i < n; ++i) {
      if (tmp + C[i] * B > mid) {
         tmp = C[i] * B;
         cnt++;
      } else tmp += C[i] * B;
   }
   if (cnt <= A) return true;
   else return false;
}

int Solution::paint(int A, int B, vector < int > & C) {
   int n = C.size();
   long long low = 0;
   long long high = 0;
   for (int i = 0; i < n; ++i) {
      high += C[i];
      low = max(low, (long long) C[i]);
   }
   low = low * B;
   high = high * B;
   while (low < high) {
      long long mid = low + (high - low) / 2;
      if (check(A, B, C, mid)) high = mid;
      else low = mid + 1;
   }
   return low % mod;
}
