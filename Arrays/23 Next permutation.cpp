// https://youtu.be/JDOXKqF60RQ?si=J1UP_GzRsWXZtYU6


// https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return;

        // Find longest non-increasing suffix
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        // longest non-increasing suffix = nums[pivot+1 ... n-1]
        
        // Are we at the last permutation already?
        if (pivot == -1) {
            // return the first permutation
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Find rightmost element greater than the pivot
        for (int i = n - 1; i >= 0; i--) {
            if(nums[i] > nums[pivot]) {
                // Now str[i] will become the new pivot
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        
        // Reverse the suffix
        reverse(nums.begin() + pivot + 1, nums.end());
        // Successfully computed the next permutation
    }
};








// https://leetcode.com/problems/next-greater-element-iii/

/*
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. 
If no such positive integer exists, return -1.
Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

Example 1:
Input: n = 12
Output: 21

Example 2:
Input: n = 21
Output: -1

Constraints:
1 <= n <= 2^31 - 1


NOTE: stoi  = for int
      stoll = for long long 
*/

// Method 1
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(str.begin(), str.end());
        auto res = stoll(str);
        
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};


// Method 2
class Solution {
public:
    bool nextPermutation(string& str) {
        int n = str.size();
        if(n == 0) return false;

        // Find longest non-increasing suffix
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if(str[i] < str[i + 1]) {
                pivot = i;
                break;
            }
        }
        // longest non-increasing suffix = str[pivot+1 ... n-1]
        
        // Are we at the last permutation already?
        if (pivot == -1) {
            return false;
        }
        
        // Find rightmost element greater than the pivot
        for (int i = n - 1; i >= 0; i--) {
            if(str[i] > str[pivot]) {
                // Now str[i] will become the new pivot
                swap(str[i], str[pivot]);
                break;
            }
        }
        
        // Reverse the suffix
        reverse(str.begin() + pivot + 1, str.end());
        // Successfully computed the next permutation
        return true;
    }

    int nextGreaterElement(int n) {
        string str = to_string(n);
        
        bool flag = nextPermutation(str);
        if(!flag) return -1;
        
        long long res = stoll(str);

        return (res > INT_MAX) ? -1 : res;
    }
};
