void findInRow(vector<vector<int>> &mat, int x, int i, int j) {
    while(j >= 0 && mat[i][j] == x) {
        cout << "Element " << x << " is found at position (" << i << ", " << j << ")" << endl;
        j--;
    }
}

void findInColumn(vector<vector<int>> &mat, int x, int i, int j) {
    while(i < mat.size() && mat[i][j] == x) {
        cout << "Element " << x << " is found at position (" << i << ", " << j << ")" << endl;
        i++;
    }
}

void matSearch (vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
    int i = 0, j = m-1;
    while(i < n && j >= 0) {
        if(mat[i][j] == x) {
            cout << "Element " << x << " is found at position (" << i << ", " << j << ")" << endl;
            findInRow(mat, x, i, j-1);
            findInColumn(mat, x, i+1, j);
            i++; j--;
        } else if(x > mat[i][j]) {
            i++;
        } else {
            j--;
        }
    }
}

void solve() {
    matrix a = {
        { -4, -3, -1, 3, 4 },
        { -3, -2, 2, 3, 5 },
        { -1, 1, 3, 5, 8 },
        { 3, 4, 7, 8, 9 }
    };
    matSearch(a, 3);
}
