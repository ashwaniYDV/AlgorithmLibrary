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
    int ladderLength(string source, string target, vector < string > & wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue < pair < string, int >> q;
        q.push({source, 1});
        // mark as visited by erasing
        dict.erase(source);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            string u = node.first;
            int dis = node.second;
            if (u == target) {
                return dis;
            }

            for (int i = 0; i < u.size(); i++) {
                char c = u[i];
                for (int j = 0; j < 26; j++) {
                    u[i] = 'a' + j;
                    if (dict.find(u) != dict.end()) {
                        q.push({u, dis + 1});
                        // mark as visited by erasing
                        dict.erase(u);
                    }
                 }
                u[i] = c;
            }
        }

        return 0;
    }
};




// Method 2
class Solution {
public: 
    vector<string> getChild(string & src, const vector < string > & words) {
        vector < string > child;

        for (string w: words) {
            int cnt = 0;
            if (w.size() != src.size()) continue;

            for (int i = 0; i < src.size(); i++) {
                if (src[i] != w[i]) {
                    cnt++;
                }
                if (cnt > 1) break;
            }

            if (cnt == 1) child.push_back(w);
        }

        return child;
    }

    int ladderLength(string source, string target, vector < string > & words) {
        unordered_set < string > vis;
        queue < pair < string, int >> q;
        q.push({source, 1});
        vis.insert(source);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            string u = node.first;
            int dis = node.second;
            if (u == target) {
                return dis;
            }

            vector < string > child = getChild(u, words);

            for (string v: child) {
                if (vis.count(v) == 0) {
                    vis.insert(v);
                    q.push({v, dis + 1});
                }
            }
        }

        return 0;
    }
};





// Method 1.2
class Solution {
public:
    int ladderLength(string source, string target, vector < string > & wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue <string> q;
        q.push(source);
        // mark as visited by erasing
        dict.erase(source);

        int level = 1;

        while (!q.empty()) {
            int n = q.size();
            for (int z = 0; z < n; z++) {
                string u = q.front();
                q.pop();

                if (u == target) {
                    return level;
                }

                for (int i = 0; i < u.size(); i++) {
                    char c = u[i];
                    for (int j = 0; j < 26; j++) {
                        u[i] = 'a' + j;
                        if (dict.find(u) != dict.end()) {
                            q.push(u);
                            // mark as visited by erasing
                            dict.erase(u);
                        }
                    }
                    u[i] = c;
                }
            }
            level++;
        }

        return 0;
    }
};