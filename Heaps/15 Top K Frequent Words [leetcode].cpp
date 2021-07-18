// https://leetcode.com/problems/top-k-frequent-words/

/*
Given a non-empty list of words, return the k most frequent elements.
Your answer should be sorted by frequency from highest to lowest. 
If two words have the same frequency, then the word with the lower alphabetical order comes first.
*/

class Solution {
public:
    struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            // min-heap
            if(a.first != b.first) {
                return !(a.first < b.first);
            }
            // sorting in reverse since final answer will also be sorted in reverse
            // so strings will be two times reversed
            return (a.second < b.second);
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string& word : words) {
            mp[word]++;
        }
        
        // min-heap
        priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;
        for(auto it: mp) {
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }
        
        int n = pq.size();
        vector<string> res(n);
        while(!pq.empty()) {
            res[--n] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};
