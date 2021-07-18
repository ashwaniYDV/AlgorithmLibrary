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
            
        stack<char> stk;
        
        for(int i=0;i<n;i++){
            char ch = s[i];
            while(!stk.empty() && stk.top() > ch && k>0){
                stk.pop();
                k--;
            }
            stk.push(ch);
        }
        
        while(k>0 && !stk.empty()){
            stk.pop();
            k--;
        }
        
        string ans = "";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
