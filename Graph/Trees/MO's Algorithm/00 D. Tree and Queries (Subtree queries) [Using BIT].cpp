// https://youtu.be/gGhQRhVbu2E
// https://codeforces.com/problemset/problem/375/D

/*
Subtree query question
*/

/*
Problem:
You have a rooted tree consisting of n vertices. Each vertex of the tree has some color. 
We will assume that the tree vertices are numbered by integers from 1 to n. 
Then we represent the color of vertex v as cv. The tree root is a vertex with number 1.
In this problem you need to answer to m queries. Each query is described by two integers vj, kj. 
The answer to query vj, kj is the number of such colors of vertices x, that the subtree of vertex vj contains at least kj vertices of color x.
*/


const int N = 1e5+5;
int n, m;

// sqrt(n)
// int BLK = 555; // gave TLE
int BLK = 600;

struct query {
    int l, r, i, k;
    bool operator<(const query &o) const {
        if((l / BLK) != (o.l / BLK))
            return l < o.l;
        return ((l / BLK) & 1) ? r < o.r : r > o.r;
    }
};

query Q[N];
vector<int> g[N];

// strt time, terminating time, flat tree, color
int S[N], T[N], FT[2*N], col[N];
// node freq, color freq, freq of freq
int nodeF[N], colorF[N], FF[N];
int ans[N];
int timer = 1;

/************************/
int BIT[N];
void update(int i, int val) {
    while(i < N) {
        BIT[i] += val;
        i += (i&-i);
    }
}
int query(int i) {
    int sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i -= (i&-i);
    }
    return sum;
}
/*************************/

// Euler Tour Technique (ETT)
void dfs(int u, int par) {
	S[u] = timer;
	FT[timer] = u;
	timer++;
	
	for(int v : g[u]) {
		if(v != par)
			dfs(v, u);
	}
	
	T[u] = timer;
	FT[timer] = u;
	timer++;
}

void add(int idx) {
	int node = FT[idx];
	int c = col[node];
	nodeF[node]++;
	
	if(nodeF[node] == 2) {
		FF[colorF[c]]--;
		update(colorF[c]+1, -1);  // since BIT is 1 indexed (colorF[c]+1 instead of colorF[c] since colorF[c] can be zero)

		colorF[c]++;

		FF[colorF[c]]++;
		update(colorF[c]+1, +1);
	}
}
 
void remove(int idx) {
	int node = FT[idx];
	int c = col[node];
	nodeF[node]--;
	
	if(nodeF[node] == 1) {
		FF[colorF[c]]--;
		update(colorF[c]+1, -1);

		colorF[c]--;

		FF[colorF[c]]++;
		update(colorF[c]+1, +1);
	}
	
}

int getAns(int l, int r) {
	// since BIT is 1 indexed 
	l++, r++;
	int x = query(r) - query(l-1);
	return x;
}

void solve() {
	int u, v, q, k;
	cin >> n >> q;

	for(int i = 1; i <= n; i++) cin >> col[i];
	for(int i = 1; i <= n-1; i++) cin >> u >> v, g[u].pb(v), g[v].pb(u);

	dfs(1, -1);

	for(int i = 1; i <= q; i++) {
		cin >> u >> k;
		Q[i].l = S[u];
		Q[i].r = T[u];
		Q[i].k = k;
		Q[i].i = i;
	}
	// sort(Q, Q + q);
	sort(Q + 1, Q + q + 1);

	// int ML = 0 , MR = -1;
	int ML = 1 , MR = 0;
	for(int i = 1; i <= q; i++) {
		int L = Q[i].l;
		int R = Q[i].r;
 		k = Q[i].k;

 		// expansion
		while(ML > L)
		ML-- , add(ML);
 	
 		// expansion
		while(MR < R)
		MR++ , add(MR);
 
 		// contraction
		while(ML < L)
		remove(ML) , ML++;
 
 		// contraction
		while(MR > R)
		remove(MR) , MR--;


 		ans[Q[i].i] = getAns(k, n);
	}
 
	for(int i = 1; i <= q; i++) cout << ans[i] << endl;
}
