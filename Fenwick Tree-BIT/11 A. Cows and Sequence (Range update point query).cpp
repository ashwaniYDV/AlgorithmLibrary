// https://codeforces.com/problemset/problem/283/A

/*
Bessie and the cows are playing with sequences and need your help. They start with a sequence, initially containing just the number 0, 
and perform n operations. Each operation is one of the following:

1) Add the integer xi to the first ai elements of the sequence.
2) Append an integer ki to the end of the sequence. (And hence the size of the sequence increases by 1)
3) Remove the last element of the sequence. So, the size of the sequence decreases by one. 

After each operation, the cows would like to know the average of all the numbers in the sequence. Help them!
*/

const int N = 2e5+5;
int n, m;

int BIT[N];

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
    int q, t, k, range, value;
    cin >> q;
    n = 1;
    int sum = 0;

    while(q--) {
        cin >> t;
        if(t == 1) {
            cin >> range >> value;
            update(1, value);
            update(range+1, -value);
            sum += (range * value);
        }
        if(t == 2) {
            cin >> k;
            n++;
            update(n, +k - query(n));
            update(n+1, -k - query(n+1));
            sum += k;
        }
        if(t == 3) {
            sum -= query(n);
            update(n, -query(n));
            n--;
        }

        cout << (ld)(sum) / (ld)(n) << endl;
    }
}
