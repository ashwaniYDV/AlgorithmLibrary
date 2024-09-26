// https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1

/*
Given an array A of integers of length n, find the nearest smaller number for every element such that the smaller element is on left side. 
If no small element present on the left print -1.

Input: n = 6
a = {1, 5, 0, 3, 4, 5}
Output: -1 1 -1 0 3 4
*/

class Solution {
public:
    vector < int > leftSmaller(int n, int A[]) {
        vector < int > res(n);
        stack < int > st;
        for (int i = 0; i < n; i++) {
            while (st.size() && st.top() >= A[i]) {
                st.pop();
            }
            if (st.size()) {
                res[i] = st.top();
            } else {
                res[i] = -1;
            }

            st.push(A[i]);
        }
        return res;
    }
};














// https://www.interviewbit.com/problems/nearest-smaller-element/

/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.
*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> res(n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(st.size() && st.top() >= A[i]) {
            st.pop();
        }
        if(st.size()) {
            res[i] = st.top();
        } else {
            res[i] = -1;
        }
        
        st.push(A[i]);
    }
    return res;
}
