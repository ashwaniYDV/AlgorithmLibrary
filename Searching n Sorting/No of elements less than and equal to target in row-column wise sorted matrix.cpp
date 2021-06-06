int countNoOfEleUptoTarget(vector<vector<int>> &mat, int target) {
    int n = mat.size(), m = mat[0].size();
    int i = n-1, j = 0, cnt = 0;
    while(i >= 0 && j < m) {
        if(mat[i][j] <= target) {
            cnt += i + 1;
            j++;
        } else {
            i--;
        }
    }
    return cnt;
}

void solve() {
    matrix a = {{ -4, -3, -1, 3, 4 },
                { -3, -2, 2, 3, 5 },
                { -1, 1, 3, 5, 8 },
                { 3, 4, 7, 8, 9 }};
    cout << countNoOfEleUptoTarget(a, 3);
}
