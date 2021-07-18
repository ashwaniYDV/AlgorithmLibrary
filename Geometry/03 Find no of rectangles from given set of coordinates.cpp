// https://youtu.be/EuPSibuIKIg
// Google Coding Interview of Errichto by Clement

/*
Find number of rectangles from a given set of coordinates. The edges of rectangle should be parallel to coordinate axes.
*/



// Method 1:
/*
For every pair of points, say (x1, y1) and (x2, y2) consider it to be the diagonal of some rectangle. 
If there exist points (x1, y2) and (x2, y1) in the initial set then we have found our rectangle. 
It should be noted that there will exist 2 diagonals which will represent the same rectangle so we divide the final answer by 2.
*/

int Solution::solve(vector < int > & X, vector < int > & Y) {
    map < pair < int, int > , int > mp;
    int ans = 0;
    for (int i = 0; i < X.size(); i++) {
        mp[{X[i], Y[i]}]++;
    }

    for (int i = 0; i < X.size(); i++) {
        for (int j = i + 1; j < X.size(); j++) {
            if (X[i] != X[j] && Y[i] != Y[j])
                if (mp[{X[i], Y[j]}] != 0 && mp[{X[j], Y[i]}] != 0)
                    ans++;
        }
    }
    return ans / 2;
}











// Method 2

/*
(x, y), (x, y2), (x2, y), (x2, y2) -> points of rectangle
x != x2 && y != y2
*/

int Solution::solve(vector < int > & X, vector < int > & Y) {
    int n = X.size();
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        points.push_back({X[i], Y[i]});
    }

    map<pair<int, int>, int> count;
    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto p = points[i];
            auto p_above = points[j];
            // check if these 2 points are on the same vertical line
            if (p.first == p_above.first && p.second < p_above.second) {
                // count all 2 points pairs which are on the same vertical line
                res += count[ {p.second, p_above.second}];
                count[ {p.second, p_above.second}]++;
            }
        }
    }

    return res;
}




int Solution::solve(vector < int > & X, vector < int > & Y) {
    int n = X.size();
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        points.push_back({X[i], Y[i]});
    }

    // sorting so that all x coordinates are in order to reduce complexity little bit
    sort(points.begin(), points.end());

    map<pair<int, int>, int> count;
    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto p = points[i];
            auto p_above = points[j];
            // check if these 2 points are on the same vertical line
            if (p.first == p_above.first && p.second < p_above.second) {
                // count all 2 points pairs which are on the same vertical line
                res += count[ {p.second, p_above.second}];
                count[ {p.second, p_above.second}]++;
            } else {
                break;
            }
        }
    }

    return res;
}
