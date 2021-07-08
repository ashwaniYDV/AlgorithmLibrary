class Solution {
public:
    vector < int > nearestSmallerToRight(vector<int> A) {
        int n = A.size();
        vector < int > res(n);
        stack < int > st;
        for (int i = n - 1; i >= 0; i--) {
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
