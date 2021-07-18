// https://codeforces.com/problemset/problem/1263/D

/*
One unknown hacker wants to get the admin's password of AtForces testing system, 
to get problems from the next contest. 
To achieve that, he sneaked into the administrator's office and stole a piece of paper 
with a list of 𝑛 passwords — strings, consists of small Latin letters.

Hacker went home and started preparing to hack AtForces. 
He found that the system contains only passwords from the stolen list 
and that the system determines the equivalence of the passwords 𝑎 and 𝑏 as follows:
* two passwords 𝑎 and 𝑏 are equivalent if there is a letter, that exists in both 𝑎 and 𝑏;
* two passwords 𝑎 and 𝑏 are equivalent if there is a password 𝑐 from the list, which is equivalent to both 𝑎 and 𝑏.

If a password is set in the system and an equivalent one is applied to access the system, 
then the user is accessed into the system.

For example, if the list contain passwords "a", "b", "ab", "d", 
then passwords "a", "b", "ab" are equivalent to each other, 
but the password "d" is not equivalent to any other password from list. 

In other words, if:
* admin's password is "b", then you can access to system by using any of this passwords: "a", "b", "ab";
* admin's password is "d", then you can access to system by using only "d".

Only one password from the list is the admin's password from the testing system. 
Help hacker to calculate the minimal number of passwords, required to guaranteed access to the system. 
Keep in mind that the hacker does not know which password is set in the system.
*/


/*
we have to find number of connected components
*/


#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e5+5;
int n, m;
 
string a[N];
 
struct DSU {
    vector<int> par;
    DSU(int n) {
        par.resize(n+1, -1);
    }
    int findParent(int a) {
        if(par[a] < 0) return a;
        return par[a] = findParent(par[a]);
    }
    bool unionSet(int a, int b){
        a = findParent(a);
        b = findParent(b);
        if(a == b) return 0;
        if(par[a] > par[b]) swap(a,b);
        par[a] += par[b];
        par[b] = a;
        return 1;
    }
    bool sameSet(int x, int y) { 
        return findParent(x) == findParent(y); 
    }
    int size (int x) { 
        return -par[findParent(x)]; 
    }
};

int32_t main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
 
    DSU dsu(n);
 
    for(char ch = 'a'; ch <= 'z'; ch++) {
    	int pos = -1;
    	for(int i = 0; i < n; i++) {
    		// check if ch exists in a[i]
    		// if(a[i].find(ch) != string::npos) {
    		if(a[i].find(ch) < n) {
				pos = i;
				break;
			}
    	}

    	if(pos == -1) continue;
 
    	for(int i = pos + 1; i < n; i++) {
    		// check if ch exists in a[i]
    		// if(a[i].find(ch) != string::npos) {
    		if(a[i].find(ch) < n) {
				dsu.unionSet(pos, i);
    		}
    	}
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
    	if (dsu.findParent(i) == i) cnt++;
    }
    cout << cnt << endl;
}