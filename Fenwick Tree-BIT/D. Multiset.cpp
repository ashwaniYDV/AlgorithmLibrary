// https://youtu.be/fgEe-iPdqeI
// https://codeforces.com/problemset/problem/1354/D

// Method 1: O[N.(logN)^2]
const int N = 1e6+5;
int n, m, k;

int BIT[N+5];

void update(int i, int val) {
    while(i > 0 && i < N) {
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

void go(int k) {
	int low = 1, high = N;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		int val = query(mid);

		if(val < k) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	update(low, -1);
}

void solve() {
	int q, x;
    cin >> n >> q;
    loop(i, 1, n) {
    	cin >> x;
    	update(x, 1);
    }
    while(q--) {
    	cin >> x;
    	if(x > 0) {
    		update(x, 1);
    	} else {
    		x = -1*x;
    		go(x);
    	}
    }

    fa(i, 1, N) {
    	if(query(i) > 0) {
    		cout << i << endl;
    		return;
    	}
    }
    cout << 0 << endl;
} 








// Method 2: O[N.(logN)^2]
const int N = 1e6+5;
int n, m, k;
 
int BIT[N+5];
 
void update(int i, int val) {
    while(i > 0 && i < N) {
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
 
int go(int k) {
	int low = 1, high = N;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		int val = query(mid);
 
		if(val < k) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return low;
}
 
void solve() {
	int q, x;
    cin >> n >> q;
    loop(i, 1, n) {
    	cin >> x;
    	update(x, 1);
    }
    while(q--) {
    	cin >> x;
    	if(x > 0) {
    		update(x, 1);
    	} else {
    		x = -1*x;
    		int pos = go(x);
    		update(pos, -1);
    	}
    }
 
    // output part
    
    int res = query(N);
    if(!res) {
    	cout << 0 << endl;
    	return;
    }
 
    int pos = go(res);
	cout << pos << endl;
} 
