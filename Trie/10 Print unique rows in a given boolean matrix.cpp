// https://www.geeksforgeeks.org/print-unique-rows/
// https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1

/*
Given a binary matrix, print all unique rows of the given matrix. 

Input:
        {0, 1, 0, 0, 1}
        {1, 0, 1, 1, 0}
        {0, 1, 0, 0, 1}
        {1, 1, 1, 0, 0}
Output:
    0 1 0 0 1 
    1 0 1 1 0 
    1 1 1 0 0 
*/


struct TrieNode {
    map<char, TrieNode*> children;
    bool isWordEnd;
    TrieNode() {
        isWordEnd = false;
    }
};

void insert(TrieNode *root,  const string key) {
    TrieNode *cur = root;
    for (char ch: key) {
        if (!cur->children[ch]) {
            cur->children[ch] = new TrieNode();
        }
        cur = cur->children[ch];
    }
    cur->isWordEnd = true;
}

bool search(TrieNode *root, const string key) {
    TrieNode *cur = root;
    for (char ch: key) {
        if (!cur->children[ch]) {
            return false;
        }
        cur = cur->children[ch];
    }
    return (cur && cur->isWordEnd);
}

/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col) {
    vector<vector<int>> res;
    TrieNode* root = new TrieNode();
    
    for(int i = 0; i < row; i++) {
        string temp;
        for(int j = 0; j < col; j++) {
            if(M[i][j] == 1)
                temp.push_back('1');
            else
                temp.push_back('0');
        }
        
        if(search(root, temp)) continue;
        
        insert(root, temp);
        vector<int> vec;
        for(int j = 0; j < col; j++) {
            vec.push_back(M[i][j]);
        }
        res.push_back(vec);
    }
    
    return res;
}
