// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/smallest-substring-e1862fcf/

/*
You are given a string s that is made of lowercase English alphabets. Determine the length of the smallest substring 
that contains the maximum number of distinct characters.

Sample Input:
abcda

Sample Output
4
*/


/*
Max number of disctinct characters will be equal to the total no of distinct characters in the given string.
So the solution is to find the smallest substring that contains all the characters of s atleast once.
*/



#include <bits/stdc++.h>
using namespace std;

int n, distinct;
string s;

bool check(int mid) {
	map<char, int> mp;
	for(int i = 0; i < mid; i++) {
		mp[s[i]]++;
	}

	int cnt = mp.size();
	for(int i = mid; i < n; i++) {
		mp[s[i - mid]]--;
		if(mp[s[i - mid]] == 0) {
			mp.erase(s[i - mid]);
		}
		mp[s[i]]++;
		cnt = max(cnt, (int)mp.size());
	}

	return cnt == distinct;
}

void solve() {
	n = s.size();
	set<char> st;
	for(char x: s) st.insert(x);
	distinct = st.size();

	int l = 0, h = n;
	while(l < h) {
		int mid = l + (h - l) / 2;
		if(check(mid)) {
			h = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << l << endl;
}

int main() {
	cin >> s;
// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/smallest-substring-e1862fcf/

/*
You are given a string  that is made of lowercase English alphabets. Determine the length of the smallest substring that contains the maximum number of distinct characters.
*/solve();	


}
