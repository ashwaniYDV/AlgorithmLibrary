// http://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/venv-pack -f -o env.tar.gz

/*
You are given a 2D integer grid of size m x n and an integer x. 
In one operation, you can add x to or subtract x from any element in the grid.
A uni-value grid is a grid where all the elements of it are equal.
Return the minimum number of operations to make the grid uni-value. 
If it is not possible, return -1;
*/

class Solution {
public:
    vector<int> getSortedVector(vector<vector<int>>& grid) {
        vector<int> a;
        for(auto& it: grid) {
            for(int x: it) {
                a.push_back(x);
            }
        }
        sort(a.begin(), a.end());
        return a;
    }

    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> a = getSortedVector(grid);
        int n = a.size();

        // median will always minimize the number of operations
        int mid = n / 2;
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            int diff = abs(a[i] - a[mid]);
            if(diff % x) return -1;

            res += (diff / x);
        }
        return res;
    }
};