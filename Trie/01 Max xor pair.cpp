// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Input: nums = [3, 10, 5, 25, 2, 8]
Output: 28
Explanation: 5 XOR 25 = 28.
*/

class Solution {
public:
    struct TrieNode {
        TrieNode* children[2];
    };

    int getBitIdx(int N, int i) {
        return (N & (1 << i)) ? 1 : 0;
    }

    void insert(TrieNode* root, int x) {
        TrieNode * itr = root;
        // padding upto 32 bits 
        for (int i = 31; i >= 0; i--) {
            int bitIdx = getBitIdx(x, i);
            if (!itr -> children[bitIdx])
                itr -> children[bitIdx] = new TrieNode();
            itr = itr -> children[bitIdx];
        }
    }

    int findMaxXor(TrieNode* root, int x) {
        TrieNode* itr = root;
        // Do XOR from root to a leaf path 
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            // Find i-th bit in x 
            int bitIdx = getBitIdx(x, i);
            // Move to the child whose XOR with f is 1. 
            if ((itr -> children[bitIdx ^ 1])) {
                ans = ans + (1 << i);
                itr = itr -> children[bitIdx ^ 1];
            } else {
                itr = itr -> children[bitIdx];
            }
        }
        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        insert(root, nums[0]);

        int res = 0;
        for(int i = 1; i < nums.size(); i++) {
            res = max(res, findMaxXor(root, nums[i]));
            insert(root, nums[i]);
        }
        return res;
    }
};