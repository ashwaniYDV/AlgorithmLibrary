// https://leetcode.com/problems/minimum-area-rectangle/description/

/*
You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
Return min area of a rectangle formed from these points, with sides parallel to the X and Y axes. 
If there is not any such rectangle, return 0.
*/


// Method 1
class Solution {
public:
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            return hash<int>()(v[0]) ^ hash<int>()(v[1]);
        }
    };

    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();

        unordered_set<vector<int>, VectorHash> st(points.begin(), points.end());

        int res = 1e9;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                // point1 and point2 are endpoints of main diagonal
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if(x1 == x2 || y1 == y2) continue;

                // find point3 and point4 which are endpoints of other diagonal
                if(st.count({x1, y2}) && st.count({x2, y1})) {
                    res = min(res, abs(x1 - x2) * abs(y1 - y2));
                }
            }
        }

        if(res == 1e9) return 0;
        return res;
    }
};



// Method 2
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<int, unordered_set<int>> mp;
        for(auto it: points) {
            mp[it[0]].insert(it[1]);
        }

        int res = 1e9;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                // point1 and point2 are endpoints of main diagonal
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if(x1 == x2 || y1 == y2) continue;

                // find point3 and point4 which are endpoints of other diagonal
                if(mp[x1].count(y2) && mp[x2].count(y1)) {
                    res = min(res, abs(x1 - x2) * abs(y1 - y2));
                }
            }
        }

        if(res == 1e9) return 0;
        return res;
    }
};