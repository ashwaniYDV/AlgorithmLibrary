// https://leetcode.com/problems/longest-substring-of-one-repeating-character/description/

/*
You are given a 0-indexed string s. 
You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.
The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].
Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.


Example 1:
Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
Output: [3,3,4]
Explanation: 
- 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
- 2nd query updates s = "bbbccc". 
  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
- 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
Thus, we return [3,3,4].

Example 2:
Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
Output: [2,3]
Explanation:
- 1st query updates s = "abazz". The longest substring consisting of one repeating character is "zz" with length 2.
- 2nd query updates s = "aaazz". The longest substring consisting of one repeating character is "aaa" with length 3.
Thus, we return [2,3].
 

Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters.
k == queryCharacters.length == queryIndices.length
1 <= k <= 10^5
queryCharacters consists of lowercase English letters.
0 <= queryIndices[i] < s.length
*/


class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;

        int prefix;
        int suffix;
        int best;
        int len;
    };

    vector<Node> st;
    string s;

    Node newNode(char ch) {
        return {ch, ch, 1, 1, 1, 1};
    }

    Node merge(Node& A, Node& B) {
        Node res;

        res.len = A.len + B.len;

        res.leftChar = A.leftChar;
        res.rightChar = B.rightChar;

        res.prefix = A.prefix;
        res.suffix = B.suffix;

        res.best = max(A.best, B.best);

        if (A.rightChar == B.leftChar) {

            // Sequence crossing the boundary
            res.best = max(res.best, A.suffix + B.prefix);

            // Entire A is same character
            if (A.prefix == A.len) {
                res.prefix = A.len + B.prefix;
            }

            // Entire B is same character
            if (B.suffix == B.len) {
                res.suffix = B.len + A.suffix;
            }
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            st[node] = newNode(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        st[node] = merge(st[2 * node], st[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            st[node] = newNode(ch);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, r, idx, ch);
        }

        st[node] = merge(st[2 * node], st[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        int n = s.size();

        st.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> res;

        for (int i = 0; i < queryCharacters.size(); i++) {
            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, idx, ch);

            res.push_back(st[1].best);
        }

        return res;
    }
};
