// https://youtu.be/9UEHPiK53BA
// https://leetcode.com/problems/distinct-subsequences-ii/

// Distinct Subsequences II (Method 1)
class Solution {
public:
    const int MOD = 1e9+7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0); // dp is of n+1 size sicnce dp[0] is for blank subsequence
        dp[0] = 1;

        map<char, int> lastOccurrence;

        for(int i = 1; i <= n; i++) {
            char ch = s[i - 1];
            dp[i] = (2 * dp[i - 1]) % MOD;
            if(lastOccurrence.count(ch)) {
                dp[i] -= lastOccurrence[ch];
            }
            dp[i] = (dp[i] + MOD) % MOD;

            lastOccurrence[ch] = dp[i - 1];
        }

        // (dp[n] - 1) since we have included the empty subsequence in our answer too 
        return (dp[n] - 1);
    }
};

// Distinct Subsequences II (Method 2)
class Solution {
public:
    const int MOD = 1e9+7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0); // dp is of n+1 size sicnce dp[0] is for blank subsequence
        dp[0] = 1;

        map<char, int> lastOccurrence;

        for(int i = 1; i <= n; i++) {
            char ch = s[i - 1];
            dp[i] = (2 * dp[i - 1]) % MOD;
            if(lastOccurrence.count(ch)) {
                int j = lastOccurrence[ch];
                dp[i] -= dp[j - 1];
            }
            dp[i] = (dp[i] + MOD) % MOD;

            lastOccurrence[ch] = i;
        }

        // (dp[n] - 1) since we have included the empty subsequence in our answer too 
        return (dp[n] - 1);
    }
};
