// https://leetcode.com/problems/repeated-string-match/

/*
Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. 
If it is impossible for b to be a substring of a after repeating it, return -1.

Note: string "abc" repeated 0 times is "",  repeated 1 time is "abc" and repeated 2 times is "abcabc". 

Example 1:
Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

Example 2:
Input: a = "a", b = "aa"
Output: 2
*/


/*
First of all, we need tmp (repeats of A) to be at least as long as B:
A: "abc"
tmp: "abc" "abc"
B: "abc abc" - in this case we need 2 copies of a;

A:"abc"
tmp:"abc" "abc" "abc"
B: "c abc ab" - in this case we need 3 copies of a

We can tell we need at least 1 extra copy, B.length() / A.length() + 1 works fine when a.len / a.len == 0
But:
a: "abc"
tmp: "abc" "abc" "abc"
b: "c abc a" - in this case we still need 3 copies of a, but a.len / b.len (5/3) only give you 1
That's why we want to add at least 2 copies.



Note: std::find() for string used KMP inbuilt 
*/


class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string tmp = A;
        int res = 1;
        while(tmp.size() < B.size()) {
            tmp += A;
            res++;
        }
        
        if(tmp.find(B) != string::npos) {
            return res;
        }
        
        tmp += A;
        res++;
        if(tmp.find(B) != string::npos) {
            return res;
        }
            
        return -1;
    }
};
















class Solution {
public:
    vector<int> prefix_function(string &s) {
        int n = (int)s.length();
        vector<int> pi(n, 0);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi[i] = j;
        }
        return pi;
    }

    int repeatedStringMatch(string A, string B) {
        int a = A.size(), b = B.size();
        // Making LPS array using string B
        vector<int>lps = prefix_function(B);

        // Search pattern 'B' in string 'A' in a circular fashion
        // 'i' represents the starting index of pattern 'B' in string 'A'
        // 'j' points to the current index in both strings 'A' and 'B'
        // (i + j) % a represents circular next index in 'A', as if it were linearly repeted

        int i = 0, j = 0;
        while (i < a) {
            // check for next in both
            if (B[j] == A[(i + j) % a]) {
                j++;
            } else {
                // even if no match found for the first letter of the pattern increment 'i'
                if (j == 0) {
                    i++;
                } else {
                    /* This else part is for case like:
                       A = "aaac", B = "aac"
                       A = "aaac", B = "aacaaac"
                    */
                    // updating 'i' here helps to keep pointed to the same position in 'A'
                    i += (j - lps[j - 1]);
                    j = lps[j - 1];
                    cout << i << " " << j << " ";
                }
            }

            if (j == b) {
                if ((i + j) % a) {
                    return (i + j) / a + 1;
                }
                return (i + j) / a;
            }
        }

        return -1;
    }
};
