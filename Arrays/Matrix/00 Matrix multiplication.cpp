// T = O(n^3)

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n1 = mat1.size();
        int n2 = mat1[0].size();
        int n3 = mat2[0].size();

        vector<vector<int>> res(n1, vector<int>(n3, 0));

        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < n3; j++) {
                for(int k = 0; k < n2; k++) {
                    res[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

        return res;
    }
};