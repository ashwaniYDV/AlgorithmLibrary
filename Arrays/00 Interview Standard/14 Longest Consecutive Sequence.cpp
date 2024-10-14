// https://leetcode.com/problems/longest-consecutive-sequence/

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. 

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
0 <= nums.length <= 105
-10^9 <= nums[i] <= 10^9
*/




/*
Efficient solution: 
We first insert all elements in a HashSet. 
Then check all the possible starts of consecutive subsequences.

Algorithm: 
1) Create an empty hash.
2) Insert all array elements to hash.
3) Do following for every element arr[i]
4) Check if this element is the starting point of a subsequence. 
   To check this, simply look for arr[i] - 1 in the hash, if not found, then this is the first element of a subsequence.
5) If this element is the first element, then count the number of elements in the consecutive starting with this element. 
   Iterate from arr[i] + 1 till the last element that can be found.
6) If the count is more than the previous longest subsequence found, then update this.
*/

// Time = O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        // initialize result by 0
        int res = 0;

        for (int x: nums) {
            // if cur ele is a candidate for starting a sequence, then previous ele should not exist
            if (st.count(x - 1)) {
                continue;
            }
            
            // stores the length of subsequence, starting with the current element
            int cnt = 1;

            // check for presence of elements `x+1`, `x+2`, `x+3`, … ,`x+len` in `st`
            while (st.count(x + cnt)) {
                cnt++;
            }

            res = max(res, cnt);
        }

        // return result
        return res;
    }
};






// Time = O(nlogn)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        sort(nums.begin(), nums.end());
        
        int mx = 1, mxSoFar = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1] + 1) {
                mxSoFar++;
            } else if(nums[i] == nums[i-1]) {
                // do nothing
            } else {
                mxSoFar = 1;
            }
            mx = max(mx, mxSoFar);
        }
        
        return mx;
    }
};
