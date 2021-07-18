// https://leetcode.com/problems/majority-element/
// https://youtu.be/nP_ns3uSh80

/*
Given an integer array containing duplicates, 
return the majority element if present. 
A majority element appears more than ⌊n / 2⌋ times (rounded down).
*/


// Boyer–Moore majority vote algorithm
// Assumption: Frequency of majority element > n / 2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int num1 = 0, cnt1 = 0;

        for (int val : nums) {
            if (num1 == val) {
                cnt1++;
            } else if (cnt1 == 0) {
                num1 = val;
                cnt1++;
            } else {
                cnt1--;
            }
        }

        // based on assumption we can directly return ans
        // return num1;

        // second iteration to simply counts the frequency of that value to confirm
        cnt1 = 0;
        for (int val : nums) {
            if (num1 == val) cnt1++;
        }
        if (cnt1 > n / 2) return num1;
        return -1;
    }
};



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int num1 = 0, cnt1 = 0;

        for (int val : nums) {
            if (cnt1 == 0) {
                num1 = val;
                cnt1 = 1;
            } else if (num1 == val) {
                cnt1++;
            } else {
                cnt1--;
            }
        }

        return num1;
    }
};



// Assumption: Frequency of majority element > n / 2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n / 2];
    }
};