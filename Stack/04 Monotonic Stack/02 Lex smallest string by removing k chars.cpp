// https://practice.geeksforgeeks.org/problems/mila-and-strings0435/1

/*
Given a string S consisting of only lowercase characters. 
Find the lexicographically smallest string after removing exactly k characters from the string.
*/

class Solution {
  public:
     string lexicographicallySmallest(string s, int k) {
        int n = s.size();
        
        if(k >= n)
            return "-1";
            
        stack<char> st;  // monotonic increasing stack [a, b, c, ...]
        
        for(int i = 0; i < n; i++) {
            char ch = s[i];

            // keep the stack monotonic increasing
            while(!st.empty() && st.top() > ch && k > 0) {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        
        // remove remaining elements
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
