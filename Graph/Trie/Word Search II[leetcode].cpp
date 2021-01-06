// Method 1: Trie + DFS + Backtracking

class Solution {
    int n, m;
    vector<string> ans;
    
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
    
    void solve(vector<vector<char>>& board,int i,int j,node *curr) {
        int index = board[i][j] - 'a';
        
        //Base case: If the trie doesn't have the current char OR cell is Visited
        if(board[i][j] == '#' || curr->child[index] == NULL)  
            return;
        
        curr = curr->child[index];
        if(curr->ends > 0) {
            ans.push_back(curr->word);
            curr->ends -=1;
        }
        
        char temp = board[i][j];   //Store current char
        board[i][j] = '#';  //Mark current node visited
        
        if(i > 0)     //TOP
            solve(board, i - 1, j, curr);
        if(i < n - 1)   //DOWN
            solve(board, i+1, j, curr);
        if(j > 0)     //LEFT
            solve(board, i, j - 1, curr);
        if(j < m - 1)   //RIGHT
            solve(board, i, j + 1, curr);
        
        board[i][j] = temp;    //Mark current node as Unvisited by restoring the value
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
        n = board.size();
        m = board[0].size();
        
        //Insert all words in TRIE
        for(string s: words)
            insert(s);
        
        //Now search words
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                solve(board, i, j, root);
        }
        return ans;
    }
};



// Method 2: DFS + Backtracking

class Solution {
public:
    int n, m, len;
    string word;

    bool dfs(int i, int j, int pos, vector<vector<char>>& board){
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#') return false;

        if(board[i][j] != word[pos]) return false;

        if(pos == len - 1){
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool res = dfs(i + 1, j, pos + 1, board) || 
                   dfs(i - 1, j, pos + 1, board) || 
                   dfs(i, j + 1, pos + 1, board) || 
                   dfs(i, j - 1, pos + 1, board);

        board[i][j] = temp;

        return res;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        vector<string> ans;
        for(string str: words){
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
