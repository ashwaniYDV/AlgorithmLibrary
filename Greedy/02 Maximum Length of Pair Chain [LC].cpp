// https://leetcode.com/problems/maximum-length-of-pair-chain/

/*
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. 
A chain of pairs can be formed in this fashion.
Return the length longest chain which can be formed.
You do not need to use up all the given intervals. 
You can select pairs in any order.

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].

Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int cnt = 1;
        int back = p[0][1];

        for(int i = 1; i < p.size(); i++) {
            if(p[i][0] > back) {
                back = p[i][1];
                cnt++;
            }
        }

        return cnt;
    }
};