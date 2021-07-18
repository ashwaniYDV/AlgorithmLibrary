// https://youtu.be/nuUspQ7ORXE

/*
Note:
Array must be of non-negative integers
*/

 
int BIT[N+5], a[N+5];

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

// returns index of lower_bound of prefixSum
int prefixSumLB(int prefixSum) {
	int curr = 0, prevSum = 0;
	for (int i = log2(N); i >= 0; i--) {
		if((curr + (1 << i)) < N && BIT[curr + (1 << i)] + prevSum < prefixSum) {
			curr += (1 << i);
			prevSum += BIT[curr];
		}
	}
	return curr + 1;
}

// returns index of upper_bound of prefixSum
int prefixSumUB(int prefixSum) {
	int curr = 0, prevSum = 0;
	for (int i = log2(N); i >= 0; i--) {
		if((curr + (1 << i)) < N && BIT[curr + (1 << i)] + prevSum <= prefixSum) {
			curr += (1 << i);
			prevSum += BIT[curr];
		}
	}
	return curr + 1;
}

void solve() {
    cin >> n;
    loop(i, 1, n) {
    	cin >> a[i];
    	update(i, a[i]);
    }
    cout << prefixSumLB(3) << endl;
    cout << prefixSumUB(3) << endl;
}

/*
Input:
5
1 2 3 4 5

Output:
2
3
*/
