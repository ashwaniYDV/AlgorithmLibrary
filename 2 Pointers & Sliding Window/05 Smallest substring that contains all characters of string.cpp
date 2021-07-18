// https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1

// Smallest window that contains all characters of string itself

/*
Given a string 's'. Find the smallest window length that contains all the characters of the given string at least one time.

Example 1:
Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"

Example 2:
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"

Example 3:
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"
*/





class Solution{
public:
    const int MAX_CHARS = 256;
    
    int findSubString(string str) {
        int n = str.length();
        if (n <= 1) return n;

        // Count all distinct characters in input str
        set<char> st;
        for (char x : str) st.insert(x);
        int dist_count = st.size();


        int left = 0, start_index = 0, min_len = INT_MAX, count = 0;
        int hash_str[MAX_CHARS] = { 0 };

        for (int right = 0; right < n; right++) {
            hash_str[str[right]]++;

            if (hash_str[str[right]] == 1) count++;

            // if all the characters are matched
            if (count == dist_count) {
                // Try to minimize the window
                // i.e., check if any character is occurring more no. of times than its occurrence in pattern
                while (hash_str[str[left]] > 1) {
                    hash_str[str[left]]--;
                    left++;
                }

                int cur_window = right - left + 1;
                if (min_len > cur_window) {
                    min_len = cur_window;
                    start_index = left;
                }
            }
        }

        // Return substring starting from start_index and length min_len
        // return str.substr(start_index, min_len);
        return min_len;
    }
};







class Solution {
public:
    const int MAX_CHARS = 256;

    string findSubString(string str) {
        int n = str.length();
        if (n <= 1) return str;

        // Count all distinct characters in input str
        set<char> st;
        for (char x : str) st.insert(x);
        int dist_count = st.size();


        int left = 0, start_index = 0, min_len = INT_MAX, count = 0;
        int hash_str[MAX_CHARS] = { 0 };

        for (int right = 0; right < n; right++) {
            hash_str[str[right]]++;

            if (hash_str[str[right]] == 1) count++;

            // if all the characters are matched
            if (count == dist_count) {
                // Try to minimize the window
                // i.e., check if any character is occurring more no. of times than its occurrence in pattern
                while (hash_str[str[left]] > 1) {
                    hash_str[str[left]]--;
                    left++;
                }

                int cur_window = right - left + 1;
                if (min_len > cur_window) {
                    min_len = cur_window;
                    start_index = left;
                }
            }
        }

        // Return substring starting from start_index and length min_len
        return str.substr(start_index, min_len);
    }
};
