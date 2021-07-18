// https://codeforces.com/contest/429/problem/D
// https://codeforces.com/contest/429/submission/105246820

/*
Let’s define prefix[i] = a[1] + a[2] + ... + a[i]. 
Then, f(i, j) = (i – j) ^ 2 + (prefix[i] – prefix[j]) ^ 2.
*/


const int N = 1e5;
int n, m;

struct Point {
    int x, y;
    Point operator - (Point p) {
        return {x - p.x, y - p.y};
    }

    int dist() {
        return x*x + y*y;
    }
};

bool by_x(Point &a, Point &b) {
    return a.x < b.x;
}

bool by_y(Point &a, Point &b) {
    return a.y < b.y;
}

Point pt[N];
int prefix[N];

int fun(int L, int R) {
    if(L == R) return 1e18;

    int M = (L + R) / 2;

    sort(pt + L, pt + R + 1, by_x);

    int d = min(fun(L, M), fun(M + 1, R));
    int midx = pt[L + (R - L + 1) / 2].x;
    
    vector<Point> v;
    for(int i = L; i <= R; i++) {
        if(Point{pt[i].x - midx, 0}.dist() < d) {
            v.push_back(pt[i]);
        }
    }
    sort(v.begin(), v.end(), by_y);

    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(Point{0, v[i].y - v[j].y}.dist() > d) {
                break;
            }
            d = min(d, (v[i] - v[j]).dist());
        }
    }

    return d;
}

void solve() {
    int x, y;
    cin >> n;
    loop(i, 1, n) {
        cin >> x;
        prefix[i] = prefix[i-1] + x;
    }
    loop(i, 1, n) {
        pt[i].x = i;
        pt[i].y = prefix[i];
    }
    int distanceSquare = fun(1, n);
    cout << distanceSquare << endl;
}
