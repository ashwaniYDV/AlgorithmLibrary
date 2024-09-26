// https://leetcode.com/problems/largest-rectangle-in-histogram/

/*
Using NSL and NSR positions concept with slight midifications.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        
        stack<int> st;
        
        // Fill left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = 0;
            } else {
                left[i] = st.top() + 1;
            }
            st.push(i);
        }
        
        // Clear stack (reusing)
        while (!st.empty()) {
            st.pop();
        }
        
        // Fill right
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n - 1;
            } else {
                right[i] = st.top() - 1;
            }
            st.push(i);
        }
        
        // Stores mxArea
        int mxArea = 0;
        for(int i = 0; i < n; i++) {
            mxArea = max(mxArea, heights[i] * (right[i] - left[i] + 1));
        }
        return mxArea;
    }
};






/*
Brute force soln
Time = O(n^2))
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int mxArea = 0;
        
        for(int i = 0; i < n; i++) {
            int h = heights[i];
            int left = 0, right = 0;
            
            for(int l = i - 1; l >= 0; l--) {
                if(heights[l] >= h) {
                    left++;
                } else {
                    break;
                }
            }
            for(int r = i + 1; r < n; r++) {
                if(heights[r] >= h) {
                    right++;
                } else {
                    break;
                }
            }
            
            int currArea = h * (left + right + 1);
            mxArea = max(mxArea, currArea);
        }
        
        return mxArea;
    }
};
