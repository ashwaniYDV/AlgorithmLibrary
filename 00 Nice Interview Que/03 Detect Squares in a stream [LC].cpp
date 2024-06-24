// https://leetcode.com/problems/detect-squares/description/

/*
Easier version of this que:
https://leetcode.com/problems/minimum-area-rectangle/
*/

/*
You are given a stream of points on the X-Y plane. 
Design an algorithm that:
* Adds new points from the stream into a data structure. 
  Duplicate points are allowed and should be treated as different points.
* Given a query point, counts the number of ways to choose three points from the data structure such that the three points and the query point form an axis-aligned square with positive area.

Implement the DetectSquares class:
* DetectSquares() Initializes the object with an empty data structure.
* void add(int[] point) Adds a new point point = [x, y] to the data structure.
* int count(int[] point) Counts the number of ways to form axis-aligned squares with point point = [x, y] as described above.
*/


// Method 1
class DetectSquares {
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            return hash<int>()(v[0]) ^ hash<int>()(v[1]);
        }
    };
public:
    vector<vector<int>> points;
    unordered_map<vector<int>, int, VectorHash> mp;

    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        points.push_back(point);
        mp[point]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        for(int i = 0; i < points.size(); i++) {
            // point1 and point2 are endpoints of main diagonal
            int x1 = point[0], y1 = point[1];
            int x2 = points[i][0], y2 = points[i][1];

            if(x1 == x2 || y1 == y2) continue;
            
            // check if it is a square
            if(abs(x1 - x2) != abs(y1 - y2)) continue;

            // find point3 and point4 which are endpoints of other diagonal
            if(mp.count({x1, y2}) && mp.count({x2, y1})) {
                res += mp[{x1, y2}] * mp[{x2, y1}];
            }
        }

        return res;
    }
};



// Method 2
class DetectSquares {
public:
    vector<vector<int>> points;
    unordered_map<int, unordered_map<int, int>> mp;

    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        points.push_back(point);
        mp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        for(int i = 0; i < points.size(); i++) {
            // point1 and point2 are endpoints of main diagonal
            int x1 = point[0], y1 = point[1];
            int x2 = points[i][0], y2 = points[i][1];

            if(x1 == x2 || y1 == y2) continue;
            
            // check if it is a square
            if(abs(x1 - x2) != abs(y1 - y2)) continue;

            // find point3 and point4 which are endpoints of other diagonal
            if(mp[x1].count(y2) && mp[x2].count(y1)) {
                res += mp[x1][y2] * mp[x2][y1];
            }
        }

        return res;
    }
};

