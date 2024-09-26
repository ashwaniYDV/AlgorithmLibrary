// https://leetcode.com/problems/lexicographical-numbers/

/*
Given an integer n, return all the numbers in the range [1, n] 
sorted in lexicographical order.
You must write an algorithm that runs in O(n) time and uses O(1) extra space.

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

Input: n = 2
Output: [1,2]
*/

class Solution {
public:
    void f(int i, int n, vector<int>& res) {
        if(i > n) return;

        for(int j = i; j <= i+9; j++) {
            if(j > n) return;
            res.push_back(j);
            f(j*10, n, res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;

        for(int j = 1; j <= 9; j++) {
            if(j > n) break;
            res.push_back(j);
            f(j*10, n, res);
        }

        return res;
    }
};
