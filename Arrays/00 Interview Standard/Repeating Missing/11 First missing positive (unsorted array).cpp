// https://leetcode.com/problems/first-missing-positive/
// https://leetcode.com/problems/first-missing-positive/solutions/4925619/hard-easy-positioning-elements-at-correct-index/
// https://youtu.be/8g78yfzMlao?si=CVxVARNiEms3M5er

/*
Given an unsorted integer array nums, return the smallest missing positive integer.
NOTE: You must implement an algorithm that runs in O(n) time and uses constant extra space.

Input: nums = [1,2,0]
Output: 3

Input: nums = [3,4,-1,1]
Output: 2

Input: nums = [7,8,9,11,12]
Output: 1
*/


/*
Link => Kth missing positive number in a sorted array (we use binary search here)
*/



// Method 1
/*
We can utilize the fact that the answer lies within the range [1, n+1], where n is the size of the array. 
By rearranging the elements of the array, we can position each positive integer i at index i-1. 
Then, we iterate through the array to find the first index i where nums[i] != i+1, indicating the missing positive integer is i+1.

nums = [1 3 2 -1 -3 5 5 2 -9 -1]
After swapping
nums = [1 2 3 -1 5 -3 5 2 -9 -1]
Output: 4

Time = O(n), Space = O(1)
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
    
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != (i + 1)) return i + 1;
        }

        return n + 1;
    }
};




// Method 2
/*
There are n numbers in the array, the worst-case scenario occurs when all numbers from 1 to n exist in the array.
The first missing positive integer would be n + 1, which is treated as a special value.

The goal is to find the smallest positive integer from 1 to n not appear in the array. 
One approach involves iterating through the array and using a hash table to mark the appearance of each number, but this costs extra space.
Using sign flag, the original array can also be a hash table, if value of nums[id - 1] < 0 then id appears in nums.
Since we are concerned with numbers from 1 to n, any value outside this range in the original array can be assigned any positive number >= n + 1, just serving as a flag.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] >= n+1)
                nums[i] = n + 1;
        }

        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val >= 1 && val <= n) {
                int idx = val - 1;
                if (nums[idx] > 0) nums[idx] *= -1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }

        return n + 1;
    }
};
