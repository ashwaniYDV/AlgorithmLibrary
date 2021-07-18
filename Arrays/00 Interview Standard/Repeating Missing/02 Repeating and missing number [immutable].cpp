// https://leetcode.com/problems/set-mismatch/
// https://youtu.be/2D0D8HE6uak?si=ha0XaguqGRnMZxFI

/*
You are given a read only array of n integers from 1 to n.
Each integer appears exactly once except A which appears twice and B which is missing.
Return A and B.
Note: Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?

Input:[3 1 2 5 3] 
Output:[3, 4] 
*/



// First approach: using sum of squares
class Solution {
public:
    vector<int> findErrorNums(vector<int>& A) {
        long long n = A.size();
        long long sumOfN = (n * (n + 1)) / 2;
        long long sumOfNsq = (n * (n + 1) *(2 * n + 1)) / 6;
        int repeating = 0, missing = 0;
        
        for(int i = 0; i < n; i++){
            sumOfN -= A[i];
            sumOfNsq -= (long long)A[i] * (long long)A[i];
        }
        
        missing = (sumOfN + sumOfNsq / sumOfN) / 2;
        repeating = missing - sumOfN;
        return {repeating, missing};
    }
};


// Second approach: using xor
class Solution {
public:
    vector<int> findErrorNums(vector<int>& A) {
        int n = A.size();
        int xo = 0;
        for (int i = 0; i < n; i++) {
            xo = xo ^ A[i];
            xo = xo ^ (i + 1);
        }
        
        int LSB_mask = 0;
        for(int i = 0; i < 31; i++) {
            int mask = (1 << i);
            if(xo & mask) {
                LSB_mask = mask;
                break;
            }
        }
        
        int x = 0, y = 0;
        
        for (int i = 0; i < n; i++) {
            if (A[i] & LSB_mask)
                x = x ^ A[i];
            else
                y = y ^ A[i];
                
            if ((i + 1) & LSB_mask)
                x = x ^ (i + 1);
            else 
                y = y ^ (i + 1);
        }

        for (int i = 0; i, n; i++) {
            if (A[i] == x) {
                return {x, y};
            } else if (A[i] == y) {
                return {y, x};
            }
        }
        return {-1, -1};
    }
};



class Solution {
public:
    vector<int> findErrorNums(vector<int>& A) {
        int n = A.size();
        int xo = 0;
        for (int i = 0; i < n; i++) {
            xo = xo ^ A[i];
            xo = xo ^ (i + 1);
        }
        
        int LSB_mask = xo & (~(xo - 1));
        
        int x = 0, y = 0;
        
        for (int i = 0; i < n; i++) {
            if (A[i] & LSB_mask)
                x = x ^ A[i];
            else
                y = y ^ A[i];
                
            if ((i + 1) & LSB_mask)
                x = x ^ (i + 1);
            else 
                y = y ^ (i + 1);
        }

        for (int i = 0; i, n; i++) {
            if (A[i] == x) {
                return {x, y};
            } else if (A[i] == y) {
                return {y, x};
            }
        }
        return {-1, -1};
    }
};