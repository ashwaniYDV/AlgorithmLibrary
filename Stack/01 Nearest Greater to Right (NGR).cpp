// https://www.interviewbit.com/problems/nextgreater/

/*
Given an array, find the next greater element G[i] for every element A[i] in the array.  
The Next greater Element for an element A[i] is the first greater element on the right side of A[i] in array. 
*/

vector<int> Solution::nextGreater(vector<int> &A) {
    int n = A.size();
    vector<int> res(n);
    stack<int> st;
    for(int i = n-1; i >= 0; i--) {
        while(st.size() && st.top() <= A[i]) {
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
