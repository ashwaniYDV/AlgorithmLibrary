#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct point {
    float x;
    float y;
};

int main () {
    point p1, p2;
    float distance;

    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    cout << setprecision(4) << fixed;

    distance = sqrt(pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2));

    cout << distance << endl;

    return EXIT_SUCCESS;
}