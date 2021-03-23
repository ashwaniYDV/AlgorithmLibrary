// https://youtu.be/phgjL7SbsWs
// Jump Game (Minimum nuber of paths required)(Print all paths)

struct node {
	int index;
	int sizeOfJump;
	int jumpsRequired;
	string pathSoFar;
};

void solve() {
	cin >> n;
	vector<int> jump(n);
	f(i, n) cin >> jump[i];

	vector<int> dp(n, INF);
	dp[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--) {
		for(int j = 1; j <= jump[i]; j++) {
			if(i + j >= n) break;
			dp[i] = min(dp[i], dp[i + j] + 1);
		}
	}
    cout << "Min number of jumps = " << dp[0] << endl;

    // reverse engineering
    queue<node> q;
    q.push({0, jump[0], dp[0], "0"});

    while(q.size()) {
    	node x = q.front();
    	q.pop();

    	if(x.jumpsRequired == 0) {
    		cout << x.pathSoFar << endl;
    	}

    	for(int j = 1; j <= x.sizeOfJump; j++) {
    		int curIndex = x.index + j;
    		if(curIndex >= n) break;
    		if(dp[curIndex] != INF && dp[curIndex] == x.jumpsRequired - 1) {
    			q.push({curIndex, jump[curIndex], dp[curIndex], x.pathSoFar + "->" + to_string(curIndex)});
    		}
    	}
    }

}
 
signed main() {
	IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}
