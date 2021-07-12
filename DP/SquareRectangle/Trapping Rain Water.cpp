// https://leetcode.com/problems/trapping-rain-water
// https://youtu.be/m18Hntz4go8

/*
Key point: 
For every column i we have to look at the max column height in left (0, ... i-1) and the max column height in right (i+1, ... n).
And then take the min of these two heights and subtract with the current height to get the water height at column i;
Sum these water heights for all columns;
*/


// O(n^2) time, O(1) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        
        // 0th and (n-1)th column will contain no water above it
        // i.e first and last column cannot hold any water since it will flow off from other side
        for(int i = 1; i < n-1; i++) {
            int mxleft = height[i], mxright = height[i];
            
            for(int j = i-1; j >= 0; j--) {
                mxleft = max(mxleft, height[j]);
            }
            
            for(int j = i+1; j < n; j++) {
                mxright = max(mxright, height[j]);
            }
            
            res += (min(mxleft, mxright) - height[i]);
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









// O(n) time, O(1) space

/*
Search from left to right and maintain a max height of left and right separately, which is like a one-side wall of partial container. 
Fix the higher one and flow water from the lower part. 
For example, if current height of left is lower, we fill water in the left bin else if current height of right is lower, we fill water in the right bin. 
Until left pointer meets right pointer, we filled the whole container.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        // maximum element on left and right sides of height[i]
        int left_max = 0, right_max = 0, res = 0;

        int lo = 0, hi = n - 1;
        
        while (lo <= hi) {
            if (height[lo] < height[hi]) {
                if (height[lo] <= left_max) {
                    res += left_max - height[lo];
                }
                left_max = max(left_max, height[lo]);
                lo++;
            } else {
                if (height[hi] <= right_max) {
                    res += right_max - height[hi];
                }
                right_max = max(right_max, height[hi]);
                hi--;
            }
        }

        return res;
    }
};
