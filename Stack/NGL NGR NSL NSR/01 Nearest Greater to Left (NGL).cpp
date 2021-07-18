class Solution {
public:
    vector < int > nearestGreaterToLeft(vector < int > A) {
        int n = A.size();
        vector < int > res(n);
        stack < int > st;
        for (int i = 0; i < n; i++) {
            while (st.size() && st.top() <= A[i]) {
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
