// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int x: nums) mp[x]++;
        
        int res = 0;
        for(auto it: mp) {
            int x = it.first - k;
            if(k == 0) {
                if(mp[x] >= 2) res++;
            } else if(k > 0) {
                if(mp[x] >= 1) res++;
            }
        }
        return res;
    }
};



class Solution {
public:
    int findPairs(vector<int>& A, int B) {
        int n = A.size();
        sort(A.begin(), A.end());
        int i = 0, j = 1;
        int ans = 0;
        while (j < n) {
            if (j == i) {
                j++;
                continue;
            }
            int x = A[i], y = A[j];
            if (y - x == B) {
                // count the pair A[i], A[j] only once
                ans++;
                while (i < n && A[i] == x) i++;
                while (j < n && A[j] == y) j++;
            } else if (y - x > B) {
                i++;
            } else j++;
        }
        return ans;
    }
};
