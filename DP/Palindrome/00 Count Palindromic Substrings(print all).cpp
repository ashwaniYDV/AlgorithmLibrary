// https://www.youtube.com/watch?v=XmSOWnL6T_I&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=6

/*
DP table row index indicate starting index of substring 
and column index represents ending index of that substring.
Since starting index must be less than or equal to ending index of string
thus only upper triangular matrix + principal diagonal of DP table is usefull
and rest lower triangular part of dp table is useless since (i=starting index > j=ending index)
In string of length n there are total n(n+1)/2 substrings 
which are all covered in the upper triangular matrix + principal diagonal cells of DP table
which are n(n+1)/2 in total
Eg: s = abccbc;
         j=0 j=1   j=2    j=3     j=4     j=5
        _______________________________________
    i=0 |_a_|_ab_|_abc_|_abcc_|_abccb_|_abccbc_|
    i=1 |___|_b__|_bc__|_bcc__|_bccb__|_bccbc__|
    i=2 |___|____|_c___|__cc__|__ccb__|__ccbc__|
    i=3 |___|____|_____|__C___|__cb___|__cbc___|
    i=4 |___|____|_____|______|___b___|___bc___|
    i=5 |___|____|_____|______|_______|____c___|
gap = 0 for principal diagonal
gap = 1 for line above principal diagonal 
and so on ...
NOTE:
A substring(i, j) is palindrome if
(s[i] == s[j] && substring(i+1, j-1) is palindrome)
Eg: s = acbca
s[0] = s[4] && substring(1, 3) is palindrome
*/


void AllPalindromicSubstrings(string s){
    int n = s.size();
    bool dp[n][n];
    int count = 0;

    // traversing diagonal wise: 
    // i.e. first principal diagonal (gap = 0) and then
    // diagonal above it (gap = 1) and so on...
    for(int gap = 0; gap < n; gap++) {
        for(int i=0, j=gap;  j<n;  i++, j++) {
            if(gap == 0) {
                dp[i][j] = true;
            } else if(gap == 1) {
                if(s[i] == s[j]) dp[i][j] = true;
                else dp[i][j] = false;
            } else {
                if(s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = true;
                else dp[i][j] = false;
            }

            if(dp[i][j]) count++;
        }
    }

    cout << "Total palindromic substrings = " << count << endl;

    // To print all of them (Use dp table to print them in order as asked in question)
    for(int gap = 0; gap < n; gap++) {
        for(int i=0, j=gap;  j<n;  i++, j++) {
            if(dp[i][j]) {
                // print the substring from index (i...j)
                cout << s.substr(i, j - i + 1) << endl;
            }
        }
    }
}

/*
Input:
abccbc
Output:
Total palindromic substrings = 9 
a
b
c
c
b
c
cc
cbc
bccb
*/
