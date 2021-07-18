// https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

/*
Given a binary string of 0s and 1s. The task is to find the maximum difference of the number of 0s and the number of 1s 
(number of 0s – number of 1s) in the substrings of a string.
Note: In the case of all 1s, the answer will be -1.

Example 1:
Input : S = "11000010001" 
Output : 6 
Explanatio: From index 2 to index 9, there are 7 0s and 1 1s, so number of 0s - number of 1s is 6. 

Example 2:
Input: S = "111111"
Output: -1
Explanation: S contains 1s only 
*/

class Solution {
public:
    int maxSubstring(string s) {
        int n = s.size();
        int current_sum = 0, max_sum = 0;

        for (int i = 0; i < n; i++) {
            current_sum += (s[i] == '0' ? 1 : -1);

            if (current_sum < 0) current_sum = 0;

            max_sum = max(current_sum, max_sum);
        }

        // return -1 if string does not contain any zero
        // that means all ones otherwise max_sum
        return max_sum == 0 ? -1 : max_sum;
    }
};
