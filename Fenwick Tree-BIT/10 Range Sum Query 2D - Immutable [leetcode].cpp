// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
public:
    static const int N = 205;
    int n, m;

    long long BIT[N][N];

    void update(int x, int y, int val) {
        for(int i = x; i <= n; i += (i&-i)) {
            for(int j = y; j <= m; j += (j&-j)) {
                BIT[i][j] += val;
            }
        }
    }

    int query(int x, int y) {
        int sum = 0;
        for(int i = x; i > 0; i -= (i&-i)) {
            for(int j = y; j > 0; j -= (j&-j)) {
                sum += BIT[i][j];
            }
        }
        return sum;
    }
    
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        
        memset(BIT, 0, sizeof BIT);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                update(i+1, j+1, matrix[i][j]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        row2++;
        col1++;
        col2++;
        int res = query(row2, col2) - query(row1-1, col2) - query(row2, col1-1) + query(row1-1, col1-1);
        return res;
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
