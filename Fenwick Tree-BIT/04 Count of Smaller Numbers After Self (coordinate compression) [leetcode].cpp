// https://youtu.be/WmDEZbTHN5c
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

/*
Given an integer array nums, return an integer array counts 
where counts[i] is the number of smaller elements to the right of nums[i].

Input: nums = [5,2,6,1]
Output: [2,1,1,0]

Input: nums = [-1]
Output: [0]

Input: nums = [-1,-1]
Output: [0,0]
*/


/*
In this solution coordinate compression is used when a[i] is huge (i.e 1e9)
or when a[i] can contain negative numbers as well.
This solution also works if array contains duplicate +ve, -ve or zero elements.
*/

class Solution {
public:
    vector<int> BIT;
    int n;

    void update(int i, int delta) {
        while(i <= n) {
            BIT[i] += delta;
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
        unordered_map<int, int> mp;
        int rank = 0;
        set<int> st(nums.begin(), nums.end());
        for(int it: st) {
            mp[it] = ++rank;
        }
        
        // coordinate compression 
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = mp[nums[i]];
        }

        // size of BIT array
        n = rank;
        BIT = vector<int>(n+1, 0);

        vector<int> res(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--) {
            res[i] = query(nums[i] - 1);
            update(nums[i], 1);
        }
        
        return res;
    }
};







class Solution {
public:
    vector<int> res;
    
    void merge(vector<pair<int, int>>& a, int start, int mid, int end) {
        pair<int, int> temp[end - start + 1];
        int i = start, j = mid + 1, k = 0;
        
        int cnt = 0;
        while (i <= mid && j <= end) {
            if (a[i].first <= a[j].first) {
                res[a[i].second] += cnt;
                temp[k++] = a[i++];
            } else {
                cnt++;
                temp[k++] = a[j++];
            }
        }
        while (i <= mid) {
            res[a[i].second] += cnt;
            temp[k++] = a[i++];
        }
        while (j <= end) {
            temp[k++] = a[j++];
        }

        for (int i = 0; i < k; i++) {
            a[start++] = temp[i];
        }
    }

    void mergesort(vector<pair<int, int>>& a, int l, int r) {
        if (l >= r) return;

        int mid = (l + r) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        
        merge(a, l, mid, r);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {nums[i], i};
        }
        
        res = vector<int>(n, 0);
        mergesort(a, 0, n - 1);
        return res;
    }
};