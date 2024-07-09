// https://youtu.be/9uaXG62Y8Uw

/*
Notes:
-----
x & (-x) gives the last set bit in a number x
-x = 2’s complement of x

1 based index is followed in BIT.

BIT[x] = a[x],                  if x is odd                   
       = a[1] + ... + a[x],     if x is power of 2



int BIT[1000], a[1000], n;
void update(int i, int val) {
    for(; i <= n; i += i&-i)
        BIT[i] += val;
}
int query(int i) {
     int sum = 0;
     for(; i > 0; i -= i&-i)
        sum += BIT[i];
     return sum;
}
*/

int BIT[1000], a[1000];

// add "delta" at index "i"
// since BIT stores prefixsum, updates happen from idx = i to n
void update(int i, int delta) {
    while(i <= n) {
        BIT[i] += delta;
        i += (i&-i);
    }
}

// sum is calculated from idx = i to 1
int query(int i) {
    int sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i -= (i&-i);
    }
    return sum;
}

void solve() {
    cin >> n;
    loop(i, 1, n) {
    	cin >> a[i];
    	update(i, a[i]);
    }

    cout << "Sum of first 3 elements is: " << query(3) << endl;
} 

/*
Input:
5
1 2 3 4 5

Output:
Sum of first 3 elements is: 6
*/
