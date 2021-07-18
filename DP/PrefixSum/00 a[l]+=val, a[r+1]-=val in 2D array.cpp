// https://practice.geeksforgeeks.org/problems/queries-on-a-matrix0443/1

/*
You are given a matrix of dimension n*n. 
All the cells are initially, zero. 
You are given Q queries, which contains 4 integers a b c d 
where (a,b) is the TOP LEFT cell and (c,d) is the Bottom Right cell of a submatrix. 
Now, all the cells of this submatrix have to be incremented by one. 
After all the Q queries have been performed. 
Your task is to find the final resulting Matrix.
*/



// Not optimized solution
class Solution {
public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));

        // ham har row ke lie 1D array wala logic laga denge seperately
        for(auto it: Queries) {
            int x1 = it[0];
            int y1 = it[1];
            int x2 = it[2];
            int y2 = it[3];
            
            for(int i = x1; i <= x2; i++) {
                mat[i][y1]++;
                if(y2 + 1 < n) {
                    mat[i][y2 + 1]--;
                }
            }
        }
        
        // ham har row ke lie 1D array wala logic ki tarah add kar denge
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                mat[i][j] += mat[i][j - 1];
            }
        }

        return mat;
    }
};






// optimized solution
// https://codeforces.com/blog/entry/75093
class Solution {
public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));

        for(auto it: Queries) {
            int x1 = it[0];
            int y1 = it[1];
            int x2 = it[2];
            int y2 = it[3];

            // mat[x1][y1]++;
            // mat[x1][y2 + 1]--;
            // mat[x2 + 1][y1]--;
            // mat[x2 + 1][y2 + 1]++;
            
            mat[x1][y1]++;
            
            if (y2 + 1 < n)
                mat[x1][y2 + 1]--;
            
            if (x2 + 1 < n)
                mat[x2 + 1][y1]--;

            if (x2 + 1 < n && y2 + 1 < n)
                mat[x2 + 1][y2 + 1]++;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // mat[i][j] += (mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1]);
                
                if (i - 1 >= 0 && j - 1 >= 0)
                    mat[i][j] -= mat[i - 1][j - 1];
                if (i - 1 >= 0)
                    mat[i][j] += mat[i - 1][j];
                if (j - 1 >= 0)
                    mat[i][j] += mat[i][j - 1];
            }
        }

        return mat;
    }
};