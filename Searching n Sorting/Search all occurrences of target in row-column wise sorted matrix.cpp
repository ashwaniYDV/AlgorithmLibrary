
void matSearch (vector <vector <int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
    int i = 0, j = m-1;
    while(i < n && j >= 0) {
        if(mat[i][j] == x) {
            cout << "Element " << x << " is found at position (" << i << ", " << j << ")" << endl;
            i++; j--;
        } else if(x > mat[i][j]) {
            i++;
        } else {
            j--;
        }
    }
}
