#include <bits/stdc++.h>
using namespace std;
 
int n, m;

bool maxZeroSumSubarray(vector<int>& arr, int& left, int& right, int m) {
    map<int, int> prefSumPos;
    int sum = 0;
    int max_length = 0;
 
    for (int i = 0; i < m; i++) {
        sum += arr[i];
 
        if (arr[i] == 0 && max_length == 0) {
            left = i;
            right = i;
            max_length = 1;
        }
        if (sum == 0) {
            left = 0;
            right = i;
            max_length = i + 1;
        }
 
        if (prefSumPos.find(sum) != prefSumPos.end()) {
            int oldMaxLength = max_length;
            max_length = max(max_length, i - prefSumPos[sum]);
 
            if (oldMaxLength < max_length) {
                left = prefSumPos[sum] + 1;
                right = i;
            }
        } else {
            prefSumPos[sum] = i;
        }
    }
 
    return (max_length != 0);
}
 
void findZeroSum(vector<vector<int>>& matrix) {
    int maxArea = INT_MIN;
    int maxTop, maxBottom, maxLeft, maxRight;
 
    int top, bottom, left, right;
    vector<int> arr;
 
    for (top = 0; top < n; top++) {
        arr = vector<int>(m, 0);
 
        for (bottom = top; bottom < n; bottom++) {

            for (int j = 0; j < m; j++) {
                arr[j] += matrix[bottom][j];
            }
 
            bool isZeroSum = maxZeroSumSubarray(arr, left, right, m);
            int curArea = (bottom - top + 1) * (right - left + 1);
 
            if (isZeroSum && curArea > maxArea) {
                maxArea = curArea;
                maxLeft = left;
                maxRight = right;
                maxTop = top;
                maxBottom = bottom;
            }
        }
    }
 
    for(int i = maxTop; i <= maxBottom; i++) {
        for(int j = maxLeft; j <= maxRight; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main() {
    vector<vector<int>> matrix = {{ 9, 7, 16, 5 }, 
                                { 1, -6, -7, 3 },
                                { 1, 8, 7, 9 }, 
                                { 7, -2, 0, 10 } };
    n = matrix.size(), m = matrix[0].size();
    findZeroSum(matrix);
}
