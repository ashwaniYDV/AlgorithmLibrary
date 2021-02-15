// https://codeforces.com/contest/1447/problem/C

void solve() {
	int x, y, z, weight, weightBy2;
	cin >> n >> weight;
	weightBy2 = (weight+1)/2;

	vector<pair<int, int>> a;
	f(i, n) {
		cin >> y;
		a.pb({y, i+1});
	}
	sort(all(a));

	int sum = 0, pos;
	f(i, n) {
		sum += a[i].F;
		if(sum >= weightBy2 && sum <= weight) {
			cout << i + 1 << endl;
			loop(j, 0, i) {
				cout << a[j].S << " ";
			}
			cout << endl;
			return;
		}
		if(sum > weight) {
			pos = i;
			break;
		}
	}

	loop(i, 0, pos) {
		sum -= a[i].F;
		if(sum >= weightBy2 && sum <= weight) {
			cout << pos - i << endl;
			loop(j, i+1, pos) {
				cout << a[j].S << " ";
			}
			cout << endl;
			return;
		}
	}

	cout << -1 << endl;
}
