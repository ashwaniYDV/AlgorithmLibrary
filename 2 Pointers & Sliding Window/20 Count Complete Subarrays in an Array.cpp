// https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/

/*
You are given an array nums consisting of positive integers.
We call a subarray of an array complete if the following condition is satisfied:
The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
*/

class Solution {
public:
    int countCompleteSubarrays(vector<int>& a) {
        int n = a.size();
        unordered_set<int> st(a.begin(), a.end());
        int d = st.size();

        unordered_map<int, int> mp;
        int l = 0, res = 0;

        for(int r = 0; r < n; r++) {
            mp[a[r]]++;

            while(mp.size() == d) {
                res += n - r;
                mp[a[l]]--;
                if(mp[a[l]] == 0) mp.erase(a[l]);
                l++;
            }
        }

        return res;
    }
};
