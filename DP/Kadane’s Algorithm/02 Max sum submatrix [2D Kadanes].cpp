// https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/
// https://youtu.be/yCQN096CwWM

/*
Given a 2D array, find the maximum sum submatrix in it. 
*/

// Time = O(n^3)
class Solution {
public:
    int n, m;
    
    int kadane(vector<int>& arr, int& start, int& end, int m) {
        int maxEndingHere = 0, maxSoFar = INT_MIN;
        int beg = 0;
     
        for (int i = 0; i < m; ++i) {
            maxEndingHere += arr[i];
            
            if (maxEndingHere > maxSoFar) {
                maxSoFar = maxEndingHere;
                start = beg;
                end = i;
            }
            
            if (maxEndingHere < 0) {
                maxEndingHere = 0;
                beg = i + 1;
            }
        }
        
        return maxSoFar;
    }
    
    int maximumSumRectangle(int n, int m, vector<vector<int>> matrix) {
        this->n = n, this->m = m;
        int res = INT_MIN;
        int resLeft, resRight, resTop, resBottom;
     
        int left, right, top, bottom;
     
        for (top = 0; top < n; top++) {
            vector<int> arr(m, 0);
     
            for (bottom = top; bottom < n; bottom++) {
    
                for (int j = 0; j < m; j++) {
                    arr[j] += matrix[bottom][j];
                }
     
                int curSum = kadane(arr, left, right, m);
     
                if (curSum > res) {
                    res = curSum;
                    resLeft = left;
                    resRight = right;
                    resTop = top;
                    resBottom = bottom;
                }
            }
        }
        return res;
    }
};
