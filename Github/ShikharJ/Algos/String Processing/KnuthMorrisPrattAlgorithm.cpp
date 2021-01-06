/*
Knuth-Morris-Pratt Algorithm
----------------------------
The Knuth–Morris–Pratt Algorithm searches for occurrences of a
word within a main text string by employing the observation that
when a mismatch occurs, the word itself embodies sufficient
information to determine where the next match could begin, thus
bypassing re-examination of previously matched characters.
----------------------------
Time Complexity : O(m+n)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

int n, m;
string needle, haystack;
int parse[1000];
vector<int> matches;

void KMP(){
	for (int i = 0; i < m; i++){
		parse[i] = -1;
	}
	for (int i = 0, j = -1; i < m;){
		while (j > -1 and needle[i] != needle[j]){
			j = parse[j];
		}
		i++;
		j++;
		parse[i] = j;
	}
	for (int i = 0, j = 0; i < n;){
		while (j > -1 and haystack[i] != needle[j]){
			j = parse[j];
		}
		i++;
		j++;
		if (j == m){
			matches.push_back(i - m);
			j = parse[j];
		}
	}
}