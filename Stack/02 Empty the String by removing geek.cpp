// https://practice.geeksforgeeks.org/contest-problem/fd770d72234779237440bd0600297944b4f0754d/1/

/*
Given a String S, In one operation we can delete any occurences of "geek" as a substring in the String. 
Find the number of delete operations you have to perform to make the String Empty. 

Input:
S = "gegeekek"
Output:
2

Input:
S = "geekkgee"
Output:
-1
*/

class Solution {
  public:
    int makeStringEmpty(string s) {
        int n = s.size();
    	stack<char> st;
    
    	int res = 0;
    
    	for(int i = 0; i < n; i++) {
    		st.push(s[i]);
    
    		string temp = "";
    		if(st.size() >= 4) {
    			if(st.top() == 'k') {
    				temp += "k";
    				st.pop();
    				if(st.top() == 'e') {
    					temp += "e";
    					st.pop();
    					if(st.top() == 'e') {
    						temp += "e";
    						st.pop();
    						if(st.top() == 'g') {
    							temp = "";
    							st.pop();
    							res++;
    						}
    					}
    				}
    			}
    		}
    
    		for(int i = 0; i < temp.size(); i++) {
    			st.push(temp[i]);
    		}
    	}
    
    	if(st.size()) {
    		return -1;
    	}
    
    	return res;
    }
};
