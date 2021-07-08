// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int largestRectangleAreaInHisto(vector<int>& heights) {
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        
        vector<vector<int>> heights(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0) {
                    heights[i][j] = matrix[i][j] - 48;
                } else {
                    if(matrix[i][j] == '0') {
                        heights[i][j] = 0;
                    } else {
                        heights[i][j] += (1 + heights[i - 1][j]);
                    }
                }
            }
        }
        
        int mxArea = 0;
        for(int i = 0; i < n; i++) {
            mxArea = max(mxArea, largestRectangleAreaInHisto(heights[i]));
        }
    
        return mxArea;
    }
};

































// https://practice.geeksforgeeks.org/problems/max-rectangle/1
class Solution {
public:
    int largestRectangleAreaInHisto(vector < int > & heights) {
        int n = heights.size();
        vector < int > left(n), right(n);

        stack < int > st;

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
        for (int i = n - 1; i >= 0; i--) {
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
        for (int i = 0; i < n; i++) {
            mxArea = max(mxArea, heights[i] * (right[i] - left[i] + 1));
        }
        return mxArea;
    }

    int maxArea(int matrix[MAX][MAX], int n, int m) {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        vector < int > heights(m);
        int mxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights[j] = matrix[i][j];
            }
            mxArea = max(mxArea, largestRectangleAreaInHisto(heights));
        }

        return mxArea;
    }
};
