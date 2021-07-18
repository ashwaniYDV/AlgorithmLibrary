// https://leetcode.com/problems/trapping-rain-water
// https://youtu.be/m18Hntz4go8

/*
Key point: 
For every column i we have to look at the max column height in left (0, ... i-1) and the max column height in right (i+1, ... n).
And then take the min of these two heights and subtract with the current height to get the water height at column i;
Sum these water heights for all columns;
*/


// O(n) time, O(1) space [Two pointer technique]
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0, res = 0;

        while(l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            res += (leftMax < rightMax) ? (leftMax - height[l++]) : (rightMax - height[r--]);
        }
        
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0, res = 0;

        while(l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if(leftMax < rightMax) {
                res += leftMax - height[l];
                l++;
            } else {
                res += rightMax - height[r];
                r--;
            }
        }
        
        return res;
    }
};






// O(n) time, O(n) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        
        vector<int> prefixMax(n), suffixMax(n);
        
        prefixMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            prefixMax[i] = max(height[i], prefixMax[i-1]);
        }
        
        suffixMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffixMax[i] = max(height[i], suffixMax[i+1]);
        }
        
        int res = 0;
        
        // 0th and (n-1)th column will contain no water above it
        // i.e first and last column cannot hold any water since it will flow off from other side
        for(int i = 1; i < n-1; i++) {
            int mxleft = prefixMax[i];
            int mxright = suffixMax[i];
            
            res += (min(mxleft, mxright) - height[i]);
        }
        
        return res;
    }
};
