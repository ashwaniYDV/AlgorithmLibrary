// https://www.scaler.com/problems/first-non-repeating-character/

/*
Given a string A denoting a stream of lowercase alphabets.
You have to make new string B. B is formed such that we have to find first non-repeating character 
each time a character is inserted to the stream and append it at the end to B. if no non-repeating character is found then append '#' at the end of B.

Problem Constraints
1 <= |A| <= 100000

Input 1:
A = "abadbc"
Output 1:
"aabbdd"
Explanation:
"a"      -   first non repeating character 'a'
"ab"     -   first non repeating character 'a'
"aba"    -   first non repeating character 'b'
"abad"   -   first non repeating character 'b'
"abadb"  -   first non repeating character 'd'
"abadbc" -   first non repeating character 'd'



Input 2:
A = "abcabc"
Output 2:
"aaabc#"
Explanation 2:
"a"      -   first non repeating character 'a'
"ab"     -   first non repeating character 'a'
"abc"    -   first non repeating character 'a'
"abca"   -   first non repeating character 'b'
"abcab"  -   first non repeating character 'c'
"abcabc" -   no non repeating character so '#'
*/



string Solution::solve(string A) {
    unordered_map < char, int > mp;
    queue < char > q;
    string ans;
    for (auto c: A) {
        mp[c]++;
        q.push(c);
        while (!q.empty() && mp[q.front()] > 1)
            q.pop();
        if (!q.empty())
            ans.push_back(q.front());
        else
            ans.push_back('#');
    }
    return ans;
}
