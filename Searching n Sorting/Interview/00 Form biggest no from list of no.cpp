// https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
// https://leetcode.com/problems/largest-number/

/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.

Input: nums = [10,2]
Output: "210"

Input: nums = [3,30,34,5,9]
Output: "9534330"
*/

class Solution {
public:
    static bool compare(int X, int Y) {
        string XY = to_string(X).append(to_string(Y));
        string YX = to_string(Y).append(to_string(X));
        return XY > YX;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string res = "";
        for(auto x: nums) {
            res += to_string(x);
        }
        return (res[0] == '0') ? "0" : res;
    }
};
