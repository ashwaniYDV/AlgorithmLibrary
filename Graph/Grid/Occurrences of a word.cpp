// https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1

/*
Find the number of occurrences of a given search word in  a 2d-Array of characters 
where the word can go up, down, left, right and around 90 degree bends.
*/


class Solution{
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int n, m, len;
    string word;
    int res = 0;
    
    bool isValid(int i, int j, vector<vector<char>>& board) {
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#') return false;
        return true;
    }

    void dfs(int i, int j, int pos, vector<vector<char>>& board) {
        if(!isValid(i, j, board)) return;

        if(board[i][j] != word[pos]) return;

        if(pos == len - 1) {
            res++;
            return;
        }

        char temp = board[i][j];
        board[i][j] = '#';
        
        for(int k = 0; k < 4; k++) {
            dfs(i + dx[k], j + dy[k], pos+1, board);
        }

        board[i][j] = temp;
    }

    int findOccurrence(vector<vector<char> > &board, string word){
        n = board.size();
        m = board[0].size();
        len = word.size();
        this->word = word;
        
        res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    dfs(i, j, 0, board);
                }
            }
        }
        return res;
    }
};
