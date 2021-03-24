// https://youtu.be/mme6Tqj8tyY

struct node {
	int i, j;
	int value;
	int dpValue;
	string pathSoFar;
};

void solve() {
	vector<vector<int>> mine = {{1, 3, 1, 5},
								{2, 2, 4, 1},
								{5, 0, 2, 3},
								{0, 6, 1, 2}};

	n = mine.size(), m = mine[0].size();

	vector<vector<int>> dp(n, vector<int>(m, 0));

	for(int i = 0; i < n; i++) {
		dp[i][0] = mine[i][0];
	}

	for(int j = 1; j < m; j++) {
		for(int i = 0; i < n; i++) {
			// basically dp[i][j] = mine[i][j] + max({dp[i][j - 1], dp[i + 1][j - 1], dp[i - 1][j - 1]})
			dp[i][j] = mine[i][j] + dp[i][j - 1];
			if(i - 1 >= 0) {
				dp[i][j] = max(dp[i][j], mine[i][j] + dp[i - 1][j - 1]);
			}
			if(i + 1 < n) {
				dp[i][j] = max(dp[i][j], mine[i][j] + dp[i + 1][j - 1]);
			}
		}
	}

	int res = 0;
	for(int i = 0; i < n; i++) {
		res = max(res, dp[i][m - 1]);
	}
	cout << res << endl;

	// reverse engineering
	queue<node> q;
	for(int i = 0; i < n; i++) {
		if(dp[i][m - 1] == res) {
			q.push({i, m-1, mine[i][m-1], dp[i][m-1], " -> " + to_string(i) + "," + to_string(m-1)});
		}
	}

	while(!q.empty()) {
		node x = q.front();
		q.pop();

		int requiredValue = x.dpValue - x.value;

		if(x.j == 0) {
			cout << x.pathSoFar << endl;
			continue;
		}
		
		if(dp[x.i][x.j - 1] == requiredValue) {
			q.push({x.i, x.j - 1, mine[x.i][x.j - 1], dp[x.i][x.j - 1], " -> " + to_string(x.i) + "," + to_string(x.j - 1) + x.pathSoFar});
		}
		if(x.i - 1 >= 0 && dp[x.i - 1][x.j - 1] == requiredValue) {
			q.push({x.i - 1, x.j - 1, mine[x.i - 1][x.j - 1], dp[x.i - 1][x.j - 1], " -> " + to_string(x.i - 1) + "," + to_string(x.j - 1) + x.pathSoFar});
		}
		if(x.i + 1 < n && dp[x.i + 1][x.j - 1] == requiredValue) {
			q.push({x.i + 1, x.j - 1, mine[x.i + 1][x.j - 1], dp[x.i + 1][x.j - 1], " -> " + to_string(x.i + 1) + "," + to_string(x.j - 1) + x.pathSoFar});
		}
	}
}
