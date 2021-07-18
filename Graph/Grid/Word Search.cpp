// https://leetcode.com/problems/word-search/

/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
*/

/*
NOTE:-
Word Search 2 is a trie problem(hard)
https://leetcode.com/problems/word-search-ii/
*/

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int n, m, len;
    string word;
    
    bool isValid(int i, int j, vector<vector<char>>& board) {
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#') return false;
        return true;
    }

    bool dfs(int i, int j, int pos, vector<vector<char>>& board) {
        if(!isValid(i, j, board)) return false;

        if(board[i][j] != word[pos]) return false;

        if(pos == len - 1) {
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '#';
        bool res = false;
        
        for(int k = 0; k < 4; k++) {
            res = res || dfs(i + dx[k], j + dy[k], pos+1, board);
        }

        board[i][j] = temp;

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        len = word.size();
        this->word = word;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 0, board)) return true;
                }
            }
        }
        return false;
    }
};
