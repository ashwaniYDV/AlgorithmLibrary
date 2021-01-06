// https://leetcode.com/problems/wiggle-subsequence/

// same concept of valley as in 'buy and sell stocks at any number of times' problem 

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        
        //Removing consecutive duplicates
        for(int i = 0; i < n; i++)    if(a.size() == 0 || nums[i] != a[a.size()-1])   a.push_back(nums[i]);
        
        n = a.size();
        if(n < 2)   return n;
        
        //A subsequence will have atlesast 2 size (i.e first and last element)
        int count = 2;
                
        for(int i = 1; i < n-1; i++) {
            // valleys and peaks will occur when we count element to answer
            //either current element is smaller or greater than both adjacent elements
            if((a[i] - a[i-1] < 0 && a[i+1] - a[i] > 0) || (a[i] - a[i-1] > 0 && a[i+1] - a[i] < 0)) 
                count++;
        }
        
        return count;
    }
};
