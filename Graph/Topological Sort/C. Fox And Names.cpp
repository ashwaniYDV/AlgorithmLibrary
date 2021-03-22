// https://codeforces.com/problemset/problem/510/C

// DFS Method
const int N = 26+5;
int n, m; 
vi g[N];
int color[N];
vector<int> res;
int impossible = 0;

void dfs(int u) {
	color[u] = 1;

	for(int v: g[u]) {
		if(color[v] == 1) {
			impossible = 1;
			return;
		}
		if(color[v] == 0) {
			dfs(v);
		}
	}

	color[u] = 2;
	res.pb(u);
}

void solve() {
	cin >> n;
	vector<string> a(n);
	f(i, n) cin >> a[i];

	f(i, n) {
		fa(j, i+1, n) {
			string s1 = a[i], s2 = a[j];
			m = min(s1.size(), s2.size());
			int flag = 1;
			f(i, m) {
				if(s1[i] != s2[i]) {
					flag = 0;
					g[s1[i] - 'a'].pb(s2[i] - 'a');
					break;
				}
			}

			if(flag && (s1 > s2)) {
				impossible = 1;
			}
		}
	}
	
	f(i, 26) {
		if(color[i] == 0) {
			dfs(i);
		}
    if(impossible) {
			cout << "Impossible\n";
			return;
		}
	}

	reverse(all(res));
	for(int x: res) cout << (char)(x + 'a');
}

















// Kahn's Method
const int N = 26+5;
int n, m; 
vi g[N];
int in[N];
vector<int> res;
int impossible = 0;

void kahn(int n) {
	queue<int> q;
	for(int i = 0; i < n; i++) {
		if(in[i] == 0) q.push(i);
	}

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		res.pb(u);
		for(int v: g[u]) {
			in[v]--;
			if(in[v] == 0) q.push(v);
		}
	}

	if((int)res.size() < n) {
		cout << "Impossible\n";
		return;
	}

	for(int x: res) cout << (char)(x + 'a');
}

void solve() {
	cin >> n;
	vector<string> a(n);
	f(i, n) cin >> a[i];

	f(i, n) {
		fa(j, i+1, n) {
			string s1 = a[i], s2 = a[j];
			m = min(s1.size(), s2.size());
			int flag = 1;
			f(i, m) {
				if(s1[i] != s2[i]) {
					flag = 0;
					g[s1[i] - 'a'].pb(s2[i] - 'a');
					in[s2[i] - 'a']++;
					break;
				}
			}

			if(flag && (s1 > s2)) {
				impossible = 1;
			}
		}
	}

	if(impossible) {
		cout << "Impossible\n";
		return;
	}
	
	kahn(26);
}
