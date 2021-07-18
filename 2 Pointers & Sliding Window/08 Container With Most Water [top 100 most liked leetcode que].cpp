// https://leetcode.com/problems/container-with-most-water/
// https://youtu.be/1jTzmre77Pc

/*
Open link to see diagram.

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

Example 2:
Input: height = [1,1]
Output: 1

Example 3:
Input: height = [4,3,2,1,4]
Output: 16

Example 4:
Input: height = [1,2,1]
Output: 2
*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), res = 0;
        int left = 0, right = n - 1;

        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            res = max(res, area);

            if (height[left] >= height[right]) right--;
            else left++;
        }

        return res;
    }
};
