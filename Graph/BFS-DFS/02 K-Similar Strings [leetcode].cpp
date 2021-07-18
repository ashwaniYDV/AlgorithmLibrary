// https://leetcode.com/problems/k-similar-strings/
// https://www.youtube.com/watch?v=SAe1UqL2n-o

/*
Problem:
Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times 
so that the resulting string equals s2.
Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.
Constraints:
1 <= s1.length <= 20
s2.length == s1.length
s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
s2 is an anagram of s1.
*/

/*
Logical Thinking:
In fact, the essence of the problem is to get the minimum number of swaps A needs to make itself equal to B.
It is a shortest-path problem so we can utilize BFS. 
The graph we build sets all possible strings that can be swapped from A as nodes, and an edge exists if one string can be transformed into the other by one swap. 
We start at A, and target at B.
However, that will cause TLE.
We set all possible strings that can be formed by swapping the positions of two letters in A' one time as neighbours of A', 
however, only those can make A and B differ less are meaningful neighbours. 
That is, if A'[i] != B[i] but A'[j] == B[i], the string formed by swap(A[i], A[j]) is a meaningful neighbour of A'. 
Please note that we just need to swap the first pair (A'[i], A'[j]) we meet because the order of swap doesn't matter.
*/


class Solution {
public:
    vector<string> getNeighbours(string A, string B) { 
        vector<string> neighbours;
        int i;
        for (i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                break;
            }
        }
                
        for (int j = i + 1; j < A.size(); j++) {
            if (A[j] == B[i]) {
                swap(A[i], A[j]);             
                neighbours.push_back(A);
                swap(A[i], A[j]);
            }
        }     
        return neighbours;
    }
    int kSimilarity(string A, string B) {
        queue<pair<string, int>> q;
        map<string, int> vis;
        
        q.push({A, 0});
        vis[A] = 1;

        while (!q.empty()) {
            string u = q.front().first;
            int level = q.front().second;
            q.pop();
            if (u == B) {
                return level;
            }
            for(string v: getNeighbours(u, B)) {
                if (!vis[v]) {
                    q.push({v, level+1});
                    vis[v] = 1;
                }
            }
        }

        return -1;
    }
};

















// Method 2: BFS with whole level at a time
class Solution {
public:
    vector<string> getNeighbours(string A, string B) { 
        vector<string> neighbours;
        int i;
        for (i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                break;
            }
        }
                
        for (int j = i + 1; j < A.size(); j++) {
            if (A[j] == B[i]) {
                swap(A[i], A[j]);             
                neighbours.push_back(A);
                swap(A[i], A[j]);
            }
        }     
        return neighbours;
    }
    int kSimilarity(string A, string B) {
        queue<string> q;
        map<string, int> vis;
        
        q.push(A);
        vis[A] = 1;
        int level = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string u = q.front();
                q.pop();
                if (u == B) {
                    return level;
                }
                for(string v: getNeighbours(u, B)) {
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
            level++;
        }

        return -1;
    }
};
