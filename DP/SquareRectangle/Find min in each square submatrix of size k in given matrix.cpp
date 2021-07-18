// https://www.geeksforgeeks.org/smallest-element-from-all-square-submatrices-of-size-k-from-a-given-matrix/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > matrixMinimum(vector<vector<int> > nums, int K) {
    int n = nums.size(), m = nums[0].size();

    // Stores the required smallest elements
    vector<vector<int> > res(n - K + 1, vector<int>(m - K + 1));

    // Update the smallest elements row-wise
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - K + 1; j++) {
            int mn = INT_MAX;
            for (int k = j; k < j + K; k++) {
                mn = min(mn, nums[i][k]);
            }
            nums[i][j] = mn;
        }
    }

    // Update the minimum column-wise
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - K + 1; i++) {
            int mn = INT_MAX;
            for (int k = i; k < i + K; k++) {
                mn = min(mn, nums[k][j]);
            }
            nums[i][j] = mn;
        }
    }

    // Store the final submatrix with required minimum values
    for (int i = 0; i < n - K + 1; i++) {
        for (int j = 0; j < m - K + 1; j++) {
            res[i][j] = nums[i][j];
        }
    }

    // Return the resultant matrix
    return res;
}

void smallestinKsubmatrices(vector<vector<int> > arr, int K) {
    vector<vector<int> > res = matrixMinimum(arr, K);

    // Print resultant matrix with the minimum values of KxK sub-matrix
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int> > arr = {{-1, 5, 4, 1, -3},
                                {4, 3, 1, 1, 6},
                                {2, -2, 5, 3, 1},
                                {8, 5, 1, 9, -4},
                                {12, 3, 5, 8, 1}};

    // Given K
    int K = 3;
    smallestinKsubmatrices(arr, K);
}
