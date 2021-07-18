// https://leetcode.com/problems/wiggle-subsequence/
// https://www.quora.com/Is-it-possible-to-compute-longest-alternating-subsequence-of-a-sequence-O-n-time-If-so-how
// https://www.geeksforgeeks.org/longest-alternating-subsequence/


/*
A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. 
The first difference (if one exists) may be either positive or negative. 
A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. 
The first is not because its first two differences are positive, and the second is not because its last difference is zero.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.


Example 1:
Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).

Example 2:
Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).

Example 3:
Input: nums = [1,2,3,4,5,6,7,8,9]
Output: 2
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 1000
*/









// Method 1 
// Time Complexity: O(n^2), Auxiliary Space: O(n)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        // las[i][0] = Length of the LAS ending at index i and last element is greater than its previous element
        // las[i][1] = Length of the LAS ending at index i and last element is smaller than its previous element
        
        int las[n][2];

        for(int i = 0; i < n; i++)
            las[i][0] = las[i][1] = 1;

        int res = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                // If arr[i] is greater, then check with las[j][1]
                if (nums[j] < nums[i])
                    las[i][0] = max(las[i][0], las[j][1] + 1);

                if(nums[j] > nums[i])
                    las[i][1] = max(las[i][1], las[j][0] + 1);
            }
            res = max({res, las[i][0], las[i][1]});
        }
        
        return res;
    }
};















/*
same concept of valley as in "buy and sell stocks at any number of times" problem 
*/

// Method 2
// Time Complexity: O(n), Auxiliary Space: O(n)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        
        // Removing consecutive duplicates
        for(int i = 0; i < n; i++) {
            if(a.size() == 0 || nums[i] != a.back()) 
                a.push_back(nums[i]);
        }
        
        n = a.size();
        if(n <= 1) return n;
        
        // A subsequence will have atlesast 2 size (i.e first and last element)
        int LAS = 2;
        
        for(int i = 1; i < n-1; i++) {
            // valleys and peaks will occur when we count element to answer
            // either current element is smaller or greater than both adjacent elements
            if((a[i] < a[i-1] && a[i] < a[i+1]) || (a[i] > a[i-1] && a[i] > a[i+1])) 
                LAS++;
        }
        
        return LAS;
    }
};














// Method 3
// Time Complexity: O(n), Auxiliary Space: O(1)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        // "inc" and "dec" intialized as 1 as single element is still LAS
        int inc = 1;
        int dec = 1;

        // Iterate from second element
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                // "inc" changes iff "dec" changes
                inc = dec + 1;
            } 
            if (nums[i] < nums[i - 1]) {
                // "dec" changes iff "inc" changes
                dec = inc + 1;
            }
        }

        // Return the maximum length
        return max(inc, dec);
    }
};
