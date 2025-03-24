// https://leetcode.com/problems/merge-intervals/

class Solution {
public:    
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n = a.size();
        if (n == 0) return {};
        
        // sort on the basis of starting of interval
        sort(a.begin(), a.end(), [](vector<int>& a1, vector<int>& a2) {
        return a1[0] < a2[0];
    });
        
        vector<vector<int>> res;
        res.push_back(a[0]);
        
        for (int i = 1; i < n; i++) {
            // res.back.end < a[i].start
            if (res.back()[1] < a[i][0]) {
                res.push_back(a[i]);
            } else {
                // res.back.end = max(res.back.end, a[i].end)
                res.back()[1] = max(res.back()[1], a[i][1]);
            }
        }
        
        return res;
    }
};
