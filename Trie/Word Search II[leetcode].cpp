// https://leetcode.com/problems/word-search-ii/

/*
Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.
*/

// Method 1: Trie + DFS + Backtracking
class Solution {
    int n, m;
    vector<string> ans;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    //TrieNode
    struct node{
        char c;
        int ends;
        string word;
        node *child[26];
        node(char ch){
            c = ch;
            ends = 0;
            word = "";
            for(int i = 0; i < 26;++i)
                child[i] = NULL;
        }
    };
    
    //root
    node *root = new node('/');
    
    //Trie INSERT
    void insert(string s) {
        node *curr = root;
        int index;
        for(char ch: s){
            index = ch - 'a';
            if(curr->child[index] == NULL) {
                curr->child[index] = new node(ch);
            }
            curr = curr->child[index];
        }
        curr->ends += 1;
        curr->word = s;
    }
    
    bool isValid(int i, int j, vector<vector<char>>& board) {
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#') return false;
        return true;
    }
    
    void solve(int i, int j, vector<vector<char>>& board, node *curr) {
        //Base case
        if(!isValid(i, j, board)) return;
        
        int index = board[i][j] - 'a';
        
        //Base case: If the trie doesn't have the current char
        if(curr->child[index] == NULL) return;
        
        // check word
        curr = curr->child[index];
        if(curr->ends > 0) {
            ans.push_back(curr->word);
            curr->ends -=1;
        }
        
        char temp = board[i][j];   //Store current char
        board[i][j] = '#';  //Mark current node visited
        
        for(int k = 0; k < 4; k++) {
            solve(i + dx[k], j + dy[k], board, curr);
        }
        
        //Mark current node as Unvisited by restoring the value
        board[i][j] = temp;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
        n = board.size();
        m = board[0].size();
        
        //Insert all words in TRIE
        for(string s: words) insert(s);
        
        //Now search words
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                solve(i, j, board, root);
            }
        }
        
        return ans;
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();










// Method 2: DFS + Backtracking
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
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        vector<string> ans;
        for(string str: words) {
            len = str.size();
            this->word = str;
            int flag = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(board[i][j] == word[0]){
                        if(dfs(i, j, 0, board)) {
                            ans.push_back(str);
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag) break;
            }
        }
        return ans;
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
