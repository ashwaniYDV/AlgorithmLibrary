// Missing String
// https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/missing-string-c28c0934/
// B. Prinzessin der Verurteilung
// https://codeforces.com/contest/1536/problem/B

/*
Given a string consisting of lowercase letters only, find the typographically smallest string not present as a substring in it.

S1 is considered typographically smaller than S2 if either:
i) |S1| < |S2|
ii) |S1| = |S2| and S1 is lexicographically smaller then S2
*/


/*
Case 1:
|S| ≤ 1000

Let’s brute force check all substrings of length <= 3 and print the lexicographically smallest one that doesn’t appear as a substring in the input. 
We can guarantee that we will come across the answer due to the pigeonhole principle. 
There are at most n + (n-1) + (n-2) = 3n-3 possible substrings of length 3 or shorter in the input. 
There exist 26 + 26*26 + 26*26*26 = 18278 total substrings of length 3 or shorter. 
It is impossible for the input to contain all 18278 substrings in a single input, as 3n - 3 < 18278 for n ≤ 1000.

Final runtime looks something like O(18278n) or O(n) depending on how you implement substring checking.



Case 1:
|S| ≤ 100000

Let’s brute force check all substrings of length <= 4.
There are at most n + (n-1) + (n-2) + (n-3) = 4n-6 possible substrings of length 4 or shorter in the input. 
There exist 26 + 26*26 + 26*26*26 + 26*26*26*26 = 475254 total substrings of length 4 or shorter. 
It is impossible for the input to contain all 475254 substrings in a single input, as 4n - 6 < 475254 for n ≤ 100000.
*/

string s, cur, ans;
set<string> subStrs;
bool found;
int len;
 
void go(int pos) {
    if(pos == len) {
        if(subStrs.count(cur)) return;
 
        ans = cur;
        found = true;
        return;
    }
    for(char c = 'a'; c <= 'z'; c++) {
        cur[pos] = c;
        go(pos + 1);
        if(found) return;
    }
}
 
void solve() {
    // initialize
    found = false;
    subStrs.clear();
    s = "", cur = "", ans = "";
 
    cin >> n;
    cin >> s;
    
    // generating substrings of length size before hand and putting in a set one by one for all size
    for(int size = 1; size <= 3; size++) {
        subStrs.clear();
        for(int i = 0; i + size - 1 < n; i++) {
            subStrs.insert(s.substr(i, size));
        }
        cur.push_back('a');
        len = size;
        go(0);

        if(found) {
            cout << ans << endl;
            return;
        }
    }
}
 
signed main() {
    IOS
    int t = 1;
    cin >> t;
    f(i, t) {
        solve();
    }
}
