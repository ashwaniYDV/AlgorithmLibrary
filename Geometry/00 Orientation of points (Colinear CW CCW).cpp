// https://youtu.be/qE6ceKCpbj0

/*
Slope difference = (y2 - y1)/(x2 - x1) - (y3 - y2)/(x3 - x2)
*/

struct Point {
    int x, y;
};

int orientation(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if(val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

void solve() {
    int x, y, z, k;
    Point p1 = {1, 4}, p2 = {2, 5}, p3 = {3, 10};
    int o = orientation(p1, p2, p3);
    if(o == 0) {
        cout << "Linear\n";
    } else if(o == 1) {
        cout << "Clockwise\n";
    } else {
        cout << "Counterclockwise\n";
    }
}
