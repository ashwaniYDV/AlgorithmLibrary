// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

/*
You are given a 0-indexed string s of even length n. 
The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:
  a) It is the empty string, or
  b) It can be written as AB, where both A and B are balanced strings, or
  c) It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.
Return the minimum number of swaps to make s balanced.

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.
*/


// https://youtu.be/W61jIP-O8lw?si=QByNIUz17tbfdlw6
/*
First cancel out all the valid pairs, 
then you will be always left with something like ]]][[[  (i.e. first all closing and then all opening brackets).
Answer = ceil(m/2), where m is the number of pairs left.

Ex: ] ] [ ] ] [ [ [ ] [
---
Remove already balanced pairs:
    ] ] [ ] ] [ [ [ ] [
        ===       ===

    ] ] ] [ [ [

Now, swap these 2 pairs
    ] ] ] [ [ [
    =   = =   =

    [ ] [ ] [ ]

Ans = ceil (3 / 2) = 2
*/
class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        for (char ch: s) {
            if (ch == '[') {
                cnt++;
            } else {
                if (cnt > 0) cnt--;
            }
        }
        return (cnt + 1) / 2;
    }
};
