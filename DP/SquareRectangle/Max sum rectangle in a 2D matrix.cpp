// https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/
// https://youtu.be/yCQN096CwWM

// Time = O(n^3)
#include <bits/stdc++.h>
using namespace std;
 
int n, m;

int kadane(vector<int>& arr, int& left, int& right, int m) {
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN;
 
    // Just some initial value to check for all negative values case
    right = -1;
 
    // local variable
    int local_left = 0;
 
    for (int i = 0; i < m; ++i) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            local_left = i + 1;
        } else if (sum > maxSum) {
            maxSum = sum;
            left = local_left;
            right = i;
        }
    }
 
    // There is at-least one non-negative number
    if (right != -1) return maxSum;
 
    // Special Case: When all numbers in arr[] are negative
    maxSum = arr[0];
    left = right = 0;
 
    // Find the maximum element in array
    for (int i = 1; i < m; i++) {
        if (arr[i] > maxSum) {
            maxSum = arr[i];
            left = right = i;
        }
    }
    return maxSum;
}
 
void findMaxSum(vector<vector<int>>& matrix) {
    int maxSum = INT_MIN;
    int maxLeft, maxRight, maxTop, maxBottom;
 
    int left, right, top, bottom;
    vector<int> arr;
 
    for (top = 0; top < n; top++) {
        arr = vector<int>(m, 0);
 
        for (bottom = top; bottom < n; bottom++) {

            for (int j = 0; j < m; j++) {
                arr[j] += matrix[bottom][j];
            }
 
            int curSum = kadane(arr, left, right, m);
 
            if (curSum > maxSum) {
                maxSum = curSum;
                maxLeft = left;
                maxRight = right;
                maxTop = top;
                maxBottom = bottom;
            }
        }
    }
 
    cout << "Max sum is: " << maxSum << endl;

    for(int i = maxTop; i <= maxBottom; i++) {
        for(int j = maxLeft; j <= maxRight; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main() {
    vector<vector<int>> matrix = { { 1, 2, -1, -4, -20 },
                                 { -8, -3, 4, 2, 1 },
                                 { 3, 8, 10, 1, 3 },
                                 { -4, -1, 1, 7, -6 } };
    n = matrix.size(), m = matrix[0].size();
    findMaxSum(matrix);
}




























class Solution {
public:
    int n, m;
    
    int kadane(vector<int>& arr, int& left, int& right, int m) {
        // initialize sum, maxSum and
        int sum = 0, maxSum = INT_MIN;
     
        // Just some initial value to check for all negative values case
        right = -1;
     
        // local variable
        int local_left = 0;
     
        for (int i = 0; i < m; ++i) {
            sum += arr[i];
            if (sum < 0) {
                sum = 0;
                local_left = i + 1;
            } else if (sum > maxSum) {
                maxSum = sum;
                left = local_left;
                right = i;
            }
        }
     
        // There is at-least one non-negative number
        if (right != -1) return maxSum;
     
        // Special Case: When all numbers in arr[] are negative
        maxSum = arr[0];
        left = right = 0;
     
        // Find the maximum element in array
        for (int i = 1; i < m; i++) {
            if (arr[i] > maxSum) {
                maxSum = arr[i];
                left = right = i;
            }
        }
        return maxSum;
    }
    
    int maximumSumRectangle(int n, int m, vector<vector<int>> matrix) {
        this->n = n, this->m = m;
        int maxSum = INT_MIN;
        int maxLeft, maxRight, maxTop, maxBottom;
     
        int left, right, top, bottom;
        vector<int> arr;
     
        for (top = 0; top < n; top++) {
            arr = vector<int>(m, 0);
     
            for (bottom = top; bottom < n; bottom++) {
    
                for (int j = 0; j < m; j++) {
                    arr[j] += matrix[bottom][j];
                }
     
                int curSum = kadane(arr, left, right, m);
     
                if (curSum > maxSum) {
                    maxSum = curSum;
                    maxLeft = left;
                    maxRight = right;
                    maxTop = top;
                    maxBottom = bottom;
                }
            }
        }
        return maxSum;
    }
};
