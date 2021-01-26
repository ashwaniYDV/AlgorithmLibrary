// O(N.sqrt(N))
/*
Mark all divisors of each element, in O(n.sqrt(n)). 
Then find maximum element of mark array that is marked more than twice, in O(n).
*/
vi cnt;
void getDivisors(int n) {
    for (int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            cnt[i] += 1;
            if(i != n/i) cnt[n / i] += 1;
        }
    }
}

void solve() {
    ll x, y, z, k, sum = 0, d;
    vi a = { 1, 2, 4, 8, 8, 12 };
    n = a.size();

    int mx = 0;
    f(i, n) mx = max(mx, a[i]);

    cnt.resize(mx + 1, 0);

    f(i, n) getDivisors(a[i]);

    for (int i = mx; i >= 1; i--) {
        if(cnt[i] >= 2) {
            cout << i << endl;
            return;
        }
    } 
    
}








// O(N.log(N))
/*
This approach is based on the idea of Sieve Of Eratosthenes.

First let’s solve a simpler problem, given a value X we have to tell whether a pair has a GCD equal to X. 
This can be done by checking that how many elements in the array are multiples of X. 
If the number of such multiples is greater than 1, then X will be a GCD of some pair.
Now for pair with maximum GCD, we maintain a count array of the original array. 
Our method is based on the above problem with Sieve-like approach for loop.
*/
void solve() {
	ll x, y, z, k, sum = 0, d;
	vi a = { 1, 2, 4, 8, 8, 12 };
	n = a.size();

	int mx = 0;
	f(i, n) mx = max(mx, a[i]);

	int cnt[mx+1] = {0};

	f(i, n) cnt[a[i]]++;

	int res = 0;
	for (int i = mx; i >= 1; i--) {
		int k = 0; // count of numbers that are divisible by i
	   	for (int j = i; j <= mx; j += i) {
			k += cnt[j];
	   	}

	   	//if count of number more than one, 
	   	//then we have two numbers with a divider i, 
	   	//and it is not necessarily maximum divisor of these numbers.
	   	if (k >= 2) {
			res = i;
			break;
		}
	}
	cout << res << endl;
}












// https://codeforces.com/problemset/problem/1370/A
// A. Maximum GCD

// Method 1
void solve() {
	cin >> n;
	int mx = n;
	int cnt[mx+1] = {0};

	loop(i, 1, n) cnt[i] = 1;

	int res = 0;
	for (int i = mx; i >= 1; i--) {
		int k = 0; // count of numbers that are divisible by i
	   	for (int j = i; j <= mx; j += i) {
			k += cnt[j];
	   	}

	   	//if count of number more than one, 
	   	//then we have two numbers with a divider i, 
	   	//and it is not necessarily maximum divisor of these numbers.
	   	if (k >= 2) {
	   		res = i;
	   		break;
	   	}
	}
	cout << res << endl;
}
int32_t main() {
	IOS
	int T = 1;
	cin >> T;
	while(T--)
	solve();
	return 0;
}

// Method 2
// For array = [1, 2, ..., n] max GCD pair = floor(n/2);
// i.e GCD(n, floor(n/2)) = floor(n/2)
int32_t main() {
	IOS;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << n / 2 << endl;
	}
	return 0;
}
