// https://codeforces.com/problemset/problem/611/C



const int N = 500+5;
int n, m;
string s[N];

void solve() {
	int x, y, z, q, r1, r2, c1, c2;
	cin >> n >> m;
	f(i, n) cin >> s[i];

	vector<vector<int>> a(n, vector<int>(m, 0));

	a[0][0] = 0;

	fa(j, 1, m) {
		if(s[0][j] == '.' && s[0][j-1] == '.') {
			a[0][j] = a[0][j-1] + 1;
		} else {
			a[0][j] = a[0][j-1];
		}
	}
	fa(i, 1, n) {
		if(s[i][0] == '.' && s[i - 1][0] == '.') {
			a[i][0] = a[i-1][0] + 1;
		} else {
			a[i][0] = a[i-1][0];
		}
	}

	fa(i, 1, n) {
		fa(j, 1, m) {
			a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1];

			if(s[i][j] == '.' && s[i-1][j] == '.') a[i][j]++;
			if(s[i][j] == '.' && s[i][j-1] == '.') a[i][j]++;
		}
	}
  
	cin >> q;

	while(q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		r1--, r2--, c1--, c2--;

		if(r1 == 0 && c1 == 0) {
			cout << a[r2][c2] << endl;
			continue;
		}

		if(r1 == 0) {
			x = a[r2][c2] - a[r2][c1 - 1];
			for(int i = r1; i <= r2; i++) {
				if(s[i][c1] == '.' && s[i][c1 - 1] == '.') {
					x--;
				}
			}
			cout << x << endl;
			continue;
		}

		if(c1 == 0) {
			x = a[r2][c2] - a[r1-1][c2];
			for(int j = c1; j <= c2; j++) {
				if(s[r1][j] == '.' && s[r1 - 1][j] == '.') {
					x--;
				}
			}
			cout << x << endl;
			continue;
		}

		x = a[r2][c2] - a[r1-1][c2] - a[r2][c1 - 1] + a[r1-1][c1-1];
		for(int j = c1; j <= c2; j++) {
			if(s[r1][j] == '.' && s[r1 - 1][j] == '.') {
				x--;
			}
		}
		for(int i = r1; i <= r2; i++) {
			if(s[i][c1] == '.' && s[i][c1 - 1] == '.') {
				x--;
			}
		}
		cout << x << endl;
	}

}
