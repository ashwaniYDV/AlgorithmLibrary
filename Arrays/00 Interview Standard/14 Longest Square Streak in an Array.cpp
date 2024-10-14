// https://leetcode.com/problems/longest-square-streak-in-an-array/description/

/*
You are given an integer array nums. 
A subsequence of nums is called a square streak if:
a) The length of the subsequence is at least 2, and 
b) after sorting the subsequence, each element (except the first element) is the square of the previous number.
Return the length of the longest square streak in nums, or return -1 if there is no square streak.


Input: nums = [4,3,6,16,8,2]
Output: 3
Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
- 4 = 2 * 2.
- 16 = 4 * 4.
Therefore, [4,16,2] is a square streak.
It can be shown that every subsequence of length 4 is not a square streak.

Input: nums = [2,3,5,6,7]
Output: -1
Explanation: There is no square streak in nums so return -1.
 

Constraints:
2 <= nums.length <= 10^5
2 <= nums[i] <= 10^5
*/


// Method 1: Time = O(n)
class Solution {
public:
    const int N = 1e5;

    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int maxLength = 0;

        for (int x: nums) {
            // if cur ele is a candidate for starting a sequence, then previous ele (i.e. sqrt of x) should not exist
            int sqrtX = sqrt(x);
            if (sqrtX * sqrtX == x && st.count(sqrtX)) {
                continue;
            }
            
            int cnt = 1;
            long long squareX = (long long)x * x;

            while (squareX <= N && st.count(squareX)) {
                cnt++;
                squareX *= squareX;
            }

            maxLength = max(maxLength, cnt);
        }

        return maxLength > 1 ? maxLength : -1;
    }
};




// Method 2.1: Time = O(nlogn)
class Solution {
public:
    const int N = 1e5;
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> dp(N+1, -1);
        for(int x: nums) dp[x] = 1;

        int res = -1;
        for(int x: nums) {
            long long squareRoot = sqrt(x);
            if(squareRoot * squareRoot != x) continue;

            if(dp[squareRoot] != -1) {
                dp[x] = max(dp[x], dp[squareRoot] + 1);

                res = max(res, dp[x]);
            }
        }

        return res;
    }
};

// Method 2.2: Time = O(nlogn)
class Solution {
public:
    const int N = 1e5;
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> dp(N+1, -1);
        for(int x: nums) dp[x] = 1;

        int res = -1;
        for(int x: nums) {
            long long square = (long long)x * x;
            if(square >= N) continue;

            if(dp[square] != -1) {
                dp[square] = max(dp[square], dp[x] + 1);

                res = max(res, dp[square]);
            }
        }

        return res;
    }
};
