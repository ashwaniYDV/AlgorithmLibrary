// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

/*
Given a row wise sorted matrix of size n x m where n and m are always odd.
Find the median of the matrix.
*/

/*
For a number to be median there should be exactly (n / 2) numbers which are less than this number. 
So, we try to find the count of numbers less than all the numbers.

Below is the step by step algorithm for this approach: 
a) First, we find the minimum and maximum elements in the matrix. 
b) Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max and get a count of numbers less than our mid. 
c) For a number to be median, there should be (n * m) / 2 numbers smaller than that number. 
   So for every number, we get the count of numbers less than that by using upper_bound() in each row of the matrix, 
   if it is less than the required count, the median must be greater than the selected number, else the median must be less than or equal to the selected number.
*/


// Method 1
// FFFFFFFTTTTTTTTT
class Solution{   
public:
    bool check(int mid, vector<vector<int>> &matrix, int n, int m) {
        int cnt = 0;
        // Find count of elements smaller than or equal to mid
        for (int i = 0; i < n; ++i) {
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        
        int desired = (n * m + 1) / 2;
        return cnt >= desired;
    }
    
    int median(vector<vector<int>> &matrix, int n, int m) {
        int lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < n; i++) {
            // Finding the minimum element
            lo = min(lo, matrix[i][0]);
            // Finding the maximum element
            hi = max(hi, matrix[i][m - 1]);
        }
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid, matrix, n, m))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;

        /*
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid, matrix, n, m))
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return lo;
        */  
    }
};





// Method 2
class Solution {
public:
    int median(vector<vector<int>> &matrix, int n, int m) {
        priority_queue<array<int, 3>, vector<array<int, 3>> , greater<array<int, 3>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int k = (n * m + 1) / 2;
        int res;
        while (k--) {
            int val = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            res = val;

            if (j + 1 < m) {
                pq.push({matrix[i][j + 1], i, j + 1});
            }
        }
        return res;
    }
};
