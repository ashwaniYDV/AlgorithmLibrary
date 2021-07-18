// https://www.interviewbit.com/problems/min-xor-value/
// https://youtu.be/OZ2jghS0t24?si=jdsJAsdceN30AYcR

/*
Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. 
*/


// Method 1
/*
Intuition
=========
sorted nums = [a, b, c]

If
    a <= b <= c
then
    a^b < a^c
    b^c < a^c


*/

int Solution::findMinXor(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int res = INT_MAX;
    for(int i = 1; i < nums.size(); i++) {
        res = min(res, nums[i - 1] ^ nums[i]);
    }
    return res;
}



// Method 2
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

    int findMinXor(TrieNode* root, int x) {
        TrieNode* itr = root;
        // Do XOR from root to a leaf path 
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            // Find i-th bit in x 
            int bitIdx = getBitIdx(x, i);
            // Move to the child whose XOR with f is 0. 
            if ((itr -> children[bitIdx])) {
                itr = itr -> children[bitIdx];
            } else {
				ans = ans + (1 << i);
                itr = itr -> children[bitIdx ^ 1];
            }
        }
        return ans;
    }

    int findMinimumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        insert(root, nums[0]);

        int res = INT_MAX;
        for(int i = 1; i < nums.size(); i++) {
            res = min(res, findMinXor(root, nums[i]));
            insert(root, nums[i]);
        }
        return res;
    }
};