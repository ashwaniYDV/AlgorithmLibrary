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
