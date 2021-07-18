// https://www.scaler.com/problems/painters-partition-problem
// https://takeuforward.org/arrays/painters-partition-problem/

/*
Given 2 integers A and B and an array of integers C of size N. 
Element C[i] represents the length of ith board.
You have to paint all N boards [C0, C1, C2, C3 … CN-1]. 
There are A painters available and each of them takes B units of time to paint 1 unit of the board.

Calculate and return the minimum time required to paint all boards if all painters start together under the constraints that any painter will only paint contiguous sections of the board.

NOTE:
a) 2 painters cannot share a board to paint. That is to say, a board cannot be painted partially by one painter, and partially by another.
b) A painter will only paint contiguous boards. This means a configuration where painter 1 paints boards 1 and 3 but not 2 is invalid.
*/

// FFFFFFFTTTTTTT

const int mod = 10000003;
bool check(long long A, long long B, vector < int > & C, long long mid) {
    long long cnt = 1;
    long long sum = 0;
    for (int i = 0; i < C.size(); ++i) {
        sum += C[i] * B;
        if (sum > mid) {
            sum = C[i] * B;
            cnt++;
        }
    }
    return (cnt <= A);
}

int Solution::paint(int A, int B, vector < int > & C) {
   if (A > C.size()) return -1;

    long long low = 0;
    long long high = 0;
    for (int x: C) {
        low = max(low, (long long) x);
        high += x;
    }
    low = low * B;
    high = high * B;

    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (check(A, B, C, mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low % mod;
}