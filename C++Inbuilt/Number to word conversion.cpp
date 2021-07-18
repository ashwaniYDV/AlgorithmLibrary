// https://leetcode.com/problems/integer-to-english-words/

/*
Example 1:
Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:
Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Example 4:
Input: num = 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
 

Constraints:
0 <= num <= 2^31 - 1
*/


class Solution {
public:
    string LESS_THAN_20[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string TENS[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string THOUSANDS[4] = {"", "Thousand", "Million", "Billion"};

    string trimEndingSpcaes(string s) {
        int n = s.size();
        int i = n - 1, cnt = 0;
        while (i >= 0 && s[i] == ' ') {
            i--;
            cnt++;
        }
        s = s.substr(0, n - cnt);
        return s;
    }

    string helper(int num) {
        if (num == 0)
            return "";
        else if (num < 20)
            return LESS_THAN_20[num] + " ";
        else if (num < 100)
            return TENS[num / 10] + " " + helper(num % 10);
        else
            return LESS_THAN_20[num / 100] + " Hundred " + helper(num % 100);
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        int i = 0;
        string res = "";

        while (num > 0) {
            if (num % 1000 != 0) {
                res = helper(num % 1000) + THOUSANDS[i] + " " + res;
            }
            num /= 1000;
            i++;
        }

        return trimEndingSpcaes(res);
    }
};
