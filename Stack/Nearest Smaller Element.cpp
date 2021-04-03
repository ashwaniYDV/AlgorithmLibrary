// https://www.interviewbit.com/problems/nearest-smaller-element/


vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> res;
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(st.size() && st.top() >= A[i]) {
            st.pop();
        }
        if(st.size()) {
            res.push_back(st.top());
        } else {
            res.push_back(-1);
        }
        
        st.push(A[i]);
    }
    return res;
}
