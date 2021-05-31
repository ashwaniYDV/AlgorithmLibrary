class Solution {
public:    
    string lcs(string s1, string s2) {
        int n1 = s1.size(), n2=s2.size();
        int dp[n1 + 1][n2 + 1];
        for(int i = 0; i <= n1; i++) {
            for(int j = 0; j <= n2; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int maxLength = dp[n1][n2];
        string ans = "";
        int i = n1, j = n2;
        while(i > 0 && j > 0) {
            if(s1[i - 1] == s2[j - 1]) {
                ans = s1[i-1] + ans;
                i--, j--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        return ans;
    }
    
    string shortestCommonSupersequence(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 == 0) 
            return s2;
        if(n2 == 0)
            return s1;
    
        int i = 0, j = 0;
        string SCS = "";
        for(char c: lcs(s1, s2)) {
            while (s1[i] != c)
                SCS += s1[i++];
            while (s2[j] != c)
                SCS += s2[j++];
            SCS += c;
            i++, j++;
        }
        
        SCS += s1.substr(i) + s2.substr(j);
        return SCS;
    }
};
