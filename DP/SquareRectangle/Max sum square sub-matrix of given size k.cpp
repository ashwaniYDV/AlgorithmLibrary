// https://www.geeksforgeeks.org/print-maximum-sum-square-sub-matrix-of-given-size/

#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<vector<int>> matrix, dp;

void preprocess() {
    dp = vector<vector<int>>(n+1, vector<int>(n+1, 0));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] + matrix[i-1][j-1] - dp[i-1][j-1];
            }
        }
    }
}

// query params are 0 based indexed
int getSubMatrixSum(int row1, int col1, int row2, int col2) {
    row1++;
    row2++;
    col1++;
    col2++;
    return dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1-1] + dp[row1-1][col1-1];
}


int main() {
    matrix = {{1, 1, 1, 1, 1},
            {2, 2, 2, 2, 2},
            {3, 8, 6, 7, 3},
            {4, 4, 4, 4, 4},
            {5, 5, 5, 5, 5}};
    k = 3;
    n = matrix.size();

    preprocess();

    int mx = 0;
    array<int, 4> res;

    for (int i = 0; i < n-k+1; i++) {
        for (int j = 0; j < n-k+1; j++) {
            int r1 = i, c1 = j, r2 = i+k-1, c2 = j+k-1;
            int sum = getSubMatrixSum(r1, c1, r2, c2);
            if(sum > mx) {
                mx = sum;
                res = {r1, c1, r2, c2};
            }
        }
    }

    cout << "Max sum = " << mx << endl;

    for (int i = res[0]; i <= res[2]; i++) {
        for (int j = res[1]; j <= res[3]; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
