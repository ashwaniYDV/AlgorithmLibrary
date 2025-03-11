// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/

/*
You are given a string word and a non-negative integer k.
Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

Input: word = "aeioqq", k = 1
Output: 0
Explanation:
There is no substring with every vowel.

Input: word = "aeiou", k = 0
Output: 1
Explanation:
The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Constraints:
5 <= word.length <= 2 * 10^5
word consists only of lowercase English letters.
0 <= k <= word.length - 5
*/

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    long atLeastK(string s, int k) {
        int n = s.size();
        long res = 0;
        int l = 0, r = 0, consonantCount = 0;
        unordered_map<char, int> vowelCount;

        for (int r = 0; r < s.length(); r++) {
            if (isVowel(s[r])) {
                vowelCount[s[r]]++;
            } else {
                consonantCount++;
            }

            // Shrink window while we have a valid substring
            while (vowelCount.size() == 5 and consonantCount >= k) {
                res += n - r;
                if (isVowel(s[l])) {
                    vowelCount[s[l]]--;
                    if (vowelCount[s[l]] == 0) {
                        vowelCount.erase(s[l]);
                    }
                } else {
                    consonantCount--;
                }
                l++;
            }
        }

        return res;
    }

    long countOfSubstrings(string s, int k) {
        return atLeastK(s, k) - atLeastK(s, k + 1);
    }
};
