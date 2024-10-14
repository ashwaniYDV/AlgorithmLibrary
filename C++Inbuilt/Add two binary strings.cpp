// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";

        // Traverse both strings starting from last characters
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            if (i >= 0) {
                carry += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                carry += b[j] - '0';
                j--;
            }

            // If current digit sum is 1 or 3, add 1 to result
            result += char(carry % 2 + '0');

            // Compute carry
            carry /= 2;

        }
        reverse(result.begin(), result.end());
        return result;
    }
};