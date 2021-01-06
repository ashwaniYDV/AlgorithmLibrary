/*
Method 1: (Bruteforce -> O(n^2))
A simple solution is to one by one consider all bars as starting points and calculate area of all rectangles starting with every bar. 
Finally return maximum of all possible areas. 
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





/*
Method 2: (Divide and Conquer -> O(nLogn))
*/






/*
Method 3: (DP -> O(n))

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);
        
        stack<int> mystack;
        
        // Fill left
        for(int i = 0; i < n; i++) {
            if(mystack.empty()) {
                left[i] = 0;
                mystack.push(i);
            } else {
                while(!mystack.empty() and heights[mystack.top()] >= heights[i]) {
                    mystack.pop();
                }
                left[i] = mystack.empty() ? 0 : mystack.top() + 1;
                mystack.push(i);
            }
        }
        
        //Clear stack (reusing)
        while(!mystack.empty()) {
            mystack.pop();
        }
        
        // Fill right
        for(int i = n - 1; i >=0; i--) {
            if(mystack.empty()) {
                right[i] = n-1;
                mystack.push(i);
            } else {
                while(!mystack.empty() and heights[mystack.top()] >= heights[i]) {
                    mystack.pop();
                }
                right[i] = mystack.empty() ? n - 1 : mystack.top() - 1;
                mystack.push(i);
            }
        }
        
        int mxArea = 0;
        for(int i=0;i<n;++i)
            mxArea = max(mxArea, heights[i] * (right[i] - left[i] + 1));
        return mxArea;
    }
};
