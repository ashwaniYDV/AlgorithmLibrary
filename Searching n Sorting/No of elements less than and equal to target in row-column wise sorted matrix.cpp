class Solution {
public:
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
};
