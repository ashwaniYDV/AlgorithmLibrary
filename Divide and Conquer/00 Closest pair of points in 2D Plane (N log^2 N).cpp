// https://github.com/Ashishgup1/Competitive-Coding
// https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/


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
    f(i, n) {
        cin >> pt[i].x >> pt[i].y;
    }
    int distanceSquare = fun(0, n - 1);
    cout << sqrt(distanceSquare) << endl;
}
