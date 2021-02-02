// https://youtu.be/WmDEZbTHN5c
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

/*
In this solution map is used when a[i] is huge (i.e 1e9) or when a[i] can contain negative numbers as well.
This solution also works if array contains duplicate +ve, -ve or zero elements.
*/

class Solution {
public:
    static const int N = 1e5+5;
    int BIT[N+5];
    unordered_map<int, int> mp;
    int n;

    void update(int i, int val) {
        while(i <= n) {
            BIT[i] += val;
            i += (i&-i);
        }
    }

    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += BIT[i];
            i -= (i&-i);
        }
        return sum;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int rank = 0;
        set<int> st(nums.begin(), nums.end());
        for(int it: st) {
            mp[it] = ++rank;
        }

        // size of BIT array
        n = rank;

        vector<int> res(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--) {
            res[i] = query(mp[nums[i]] - 1);
            update(mp[nums[i]], 1);
        }
        
        return res;
    }
};
