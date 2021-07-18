// https://codeforces.com/contest/669/problem/E
// https://youtu.be/WmDEZbTHN5c


const int N = 1e9+5;
int n, m;
 
map<int, map<int, int>> BIT;
void update(int time, int i, int val) {
    while(time < N) {
        BIT[time][i] += val;
        time += (time&-time);
    }
}

int query(int time, int i) {
    int sum = 0;
    while(time > 0) {
        sum += BIT[time][i];
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
