/*
Trie
----
The trie data structure holds a compact representation of all prefixes
of a given dictionary of strings, enabling linear-time lookups.
----
Time Complexity : Insertion : O(n)
				  Find : O(n)
Space Complexity : O(n)
*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct TrieNode{
	bool leaf;
	unordered_map<char, TrieNode *> child;

	TrieNode() : leaf(false){}
};

TrieNode *root;

void insert(TrieNode *x, string s, size_t position){
	if (position == s.size()){
		x->leaf = true;
	} else {
		char current = s[position];
		if (x->child[current] == NULL){
			x->child[current] = new TrieNode();
		}
		insert(x->child[current], s, position + 1);
	}
}

bool find(TrieNode *x, string s, size_t position){
	if (position == s.size()){
		return x->leaf;
	}
	if (x->child[s[position]] == NULL){
		return false;
	}
	return find(x->child[s[position]], s, position + 1);
}