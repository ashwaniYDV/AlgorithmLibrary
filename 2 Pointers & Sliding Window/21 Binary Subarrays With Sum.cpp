// https://leetcode.com/problems/binary-subarrays-with-sum/description/

/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 
Constraints:
1 <= nums.length <= 3 * 10^4
0 <= goal <= nums.length
*/


// Method 1
class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int goal) {
        int res = 0, sum = 0;
        unordered_map<int, int> mp;

        mp[0] = 1;

        for (int x: a) {
            sum += x;
            res += mp[sum - goal];
            mp[sum]++;
        }

        return res;
    }
};


// Method 2
class Solution {
public:
    int windowSumAtMostK(vector<int>& a, int k) {
        int n = a.size();
        int l = 0, res = 0, sum = 0;

        for(int r = 0; r < n; r++) {
            sum += a[r];

            while(l <= r && sum > k) {
                sum -= a[l];
                l++;
            }

            res += r - l + 1;
        }

        return res;
    }

    int numSubarraysWithSum(vector<int>& a, int goal) {
        return windowSumAtMostK(a, goal) - windowSumAtMostK(a, goal - 1);
    }
};


// Method 3
class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int goal) {
        int l = 0, sum = 0, res = 0;
        int prefixZeros = 0;
        
        for (int r = 0; r < a.size(); ++r) {
            sum += a[r];
            
            while (l < r && (a[l] == 0 || sum > goal)) {
                if (a[l] == 1) {
                    prefixZeros = 0;
                } else {
                    prefixZeros += 1;
                }
                
                sum -= a[l];
                l += 1;
            }
            
            if (sum == goal) {
                res += 1 + prefixZeros;
            }
        }
        
        return res;
    }
};
