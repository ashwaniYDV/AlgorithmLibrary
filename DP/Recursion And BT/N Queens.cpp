// https://leetcode.com/problems/n-queens/description/

/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard 
such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. 
You may return the answer in any order.
*/


/*
We start by placing one queen in each column.
*/

class Solution {
public:
    int n;
    vector<vector<string>> res;

    bool isSafe(vector<string>& board, int row, int col) { 
        /* Check this row on left side */
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q') return false; 
        }
    
        /* Check upper diagonal on left side */
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false; 
        }
    
        /* Check lower diagonal on left side */
        for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
            if (board[i][j] == 'Q') return false; 
        }
    
        return true; 
    } 
    
    void solveNQUtil(vector<string>& board, int col) { 
        if (col == n) {
            vector<string> temp = board;
            res.push_back(temp);
            return;
        }
    
        for (int i = 0; i < n; i++) { 
            if (isSafe(board, i, col)) { 
                board[i][col] = 'Q'; 
                solveNQUtil(board, col + 1); 
                board[i][col] = '.';
            } 
        } 
    } 

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        res.clear();

        vector<string> board(n, string(n, '.'));

        solveNQUtil(board, 0);
        return res;
    }
};