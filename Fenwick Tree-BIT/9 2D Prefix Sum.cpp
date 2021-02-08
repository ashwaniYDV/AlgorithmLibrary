/*
n*n matrix initially all elements are 0 (matrix is 1 based indexed)
Operations:-
Type 1: set matrix[x][y] = val
Type 2: Find the sum of matrix whose top left corner is (1, 1) and bottom right corner is (x, y)

NOTE: 2D can be extended to higher dimensions as well. Only the nested loops and BIT dimension will increase.
*/


const int N = 1e3+5;
int n, m;
 
int BIT[N][N], mat[N][N];

void update(int x, int y, int val) {
	for(int i = x; i <= n; i += (i&-i)) {
		for(int j = y; j <= n; j += (j&-j)) {
			BIT[i][j] += val;
		}
	}
}

int query(int x, int y) {
	int sum = 0;
	for(int i = x; i > 0; i -= (i&-i)) {
		for(int j = y; j > 0; j -= (j&-j)) {
			sum += BIT[i][j];
		}
	}
	return sum;
}

void solve() {
	int x, y, q, type, val;
	cin >> n;

	cin >> q;

	while(q--) {
		cin >> type;
		if(type == 1) {
			cin >> x >> y >> val;
			update(x, y, val - mat[x][y]);
			mat[x][y] = val;
		} else {
			cin >> x >> y;
			cout << query(x, y) << endl;
		}
	}
}



/*
Input:
5
8
1 1 1 5
1 2 2 10
1 3 2 5
2 2 2
2 1 2
2 2 1
2 3 2
2 3 3

Output:
15
5
5
20
20
*/
