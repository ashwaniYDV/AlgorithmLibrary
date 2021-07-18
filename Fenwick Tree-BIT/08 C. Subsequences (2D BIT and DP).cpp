// https://codeforces.com/contest/597/problem/C
// https://youtu.be/WmDEZbTHN5c

/*
For the given sequence with n different elements find the number of increasing subsequences with k + 1 elements. 
It is guaranteed that the answer is not greater than 8 * 10^18.

Input:
First line contain two integer values n and k (1 ≤ n ≤ 10^5, 0 ≤ k ≤ 10) — the length of sequence and the number of elements in increasing subsequences.
Next n lines contains one integer ai (1 ≤ ai ≤ n) each — elements of sequence. All values ai are different.

Output:
Print one integer — the answer to the problem.
*/


/*
This question can be generalized as:
After all operations-
query(n, x) will give the count of LIS of length x considering whole array [i.e. arr[1], arr[2], ..., arr[n])] 
since arr is permutation of 1, ..., n and largest element is n
*/

const int N = 1e5+5;
int n, m;
 
int BIT[N][12];
void update(int i, int j, int cnt) {
	while(i < N) {
		BIT[i][j] += cnt;
		i += (i&-i);
	}
}

int query(int i, int j) {
	int sum = 0;
	while(i > 0) {
		sum += BIT[i][j];
		i -= (i&-i);
	}
	return sum;
}

void solve() {
	int x, y, k;
	cin >> n >> k;
	k++;

	for(int i = 0; i < n; i++) {
		cin >> x;
		update(x, 1, 1);
		for(int j = 2; j <= k; j++) {
			update(x, j, query(x - 1, j - 1));
		}
	}
	// query(n, k) will give the count of LIS of length k
	cout << query(n, k) << endl;
}
