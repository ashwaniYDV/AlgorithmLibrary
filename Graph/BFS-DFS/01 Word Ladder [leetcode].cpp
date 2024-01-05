// https://leetcode.com/problems/word-ladder/

/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, 
return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/





// Method 1
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        map<string, int> vis;
        vis[beginWord] = 1;
        
        while (!q.empty()) {
            string u = q.front().first;
            int level = q.front().second;
            q.pop();

            if (u == endWord) return level;

            for (int j = 0; j < u.size(); j++) {
                char c = u[j];
                for (int k = 0; k < 26; k++) {
                    u[j] = 'a' + k;
                    if (dict.find(u) != dict.end() && !vis[u]) {
                        q.push({u, level + 1});
                        vis[u] = 1;
                    }
                 }
                u[j] = c;
            }
        }
        return 0;
    }
};





// Method 2
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        // mark as visited by erasing
        dict.erase(beginWord);
        
        while (!q.empty()) {
            string u = q.front().first;
            int level = q.front().second;
            q.pop();

            if (u == endWord) return level;

            for (int j = 0; j < u.size(); j++) {
                char c = u[j];
                for (int k = 0; k < 26; k++) {
                    u[j] = 'a' + k;
                    if (dict.find(u) != dict.end()) {
                        q.push({u, level + 1});
                        // mark as visited by erasing
                        dict.erase(u);
                    }
                 }
                u[j] = c;
            }
        }
        return 0;
    }
};






// Method 2.1
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        // mark as visited by erasing
        dict.erase(beginWord);
        int level = 1;
        
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string u = q.front();
                q.pop();
                
                if (u == endWord) return level;
                
                for (int j = 0; j < u.size(); j++) {
                    char c = u[j];
                    for (int k = 0; k < 26; k++) {
                        u[j] = 'a' + k;
                        if (dict.find(u) != dict.end()) {
                            q.push(u);
                            // mark as visited by erasing
                            dict.erase(u);
                        }
                     }
                    u[j] = c;
                }
            }
            level++;
        }
        return 0;
    }
};
