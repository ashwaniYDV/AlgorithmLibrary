// https://youtu.be/WmDEZbTHN5c
// https://www.codechef.com/problems/SPREAD

/*
Range Update and Point Query

Note this question can also be solved using segment tree by using lazy range update and point query.
Because we have to update range [l, ...,r], but query of point should add the update only once (i.e. x) and not (r-l+1)*x 
*/

const int N = 1e6+5;
int n, m, k;
 
int BIT[N+5];
 
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

void solve() {
	int l, r, c, x;
	char ch;
    cin >> n >> m >> c;

    update(1, c);
    update(n+1, -c);

    while(m--) {
    	cin >> ch;
    	if(ch == 'Q') {
    		cin >> x;
    		cout << query(x) << endl;
    	} else {
    		cin >> l >> r >> x;
    		update(l, x);
    		update(r+1, -x);
    	}
    }
}
