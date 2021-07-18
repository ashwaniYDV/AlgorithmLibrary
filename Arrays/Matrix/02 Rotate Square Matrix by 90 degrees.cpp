// https://leetcode.com/problems/rotate-image/
// https://youtu.be/Y72QeX0Efxw


// rotate 90 degree in clockwise direction
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // transpose
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // reverse the rows
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


// rotate 90 degree in anti-clockwise direction
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // transpose
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // reverse the columns
        // reverseColumns(matrix)
    }
};
