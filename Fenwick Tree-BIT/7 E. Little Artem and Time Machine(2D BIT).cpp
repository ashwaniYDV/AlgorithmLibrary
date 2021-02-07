// https://codeforces.com/contest/669/problem/E
// https://youtu.be/WmDEZbTHN5c


const int N = 1e9+5;
int n, m, k;
 
map<int, map<int, int>> BIT;
void update(int time, int val, int cnt) {
	while(time < N) {
		BIT[time][val] += cnt;
		time += (time&-time);
	}
}

int query(int time, int val) {
	int sum = 0;
	while(time > 0) {
		sum += BIT[time][val];
		time -= (time&-time);
	}
	return sum;
}

void solve() {
	int x, y;
	cin >> n;
	int type, time, val;
	while(n--) {
		cin >> type >> time >> val;
		if(type == 1)
			update(time, val, 1);
		else if(type == 2)
			update(time, val, -1);
		else
			cout << query(time, val) << endl;
	}
}
