// https://leetcode.com/problems/minimum-area-rectangle-ii/

/*
You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
Return the minimum area of any rectangle formed from these points, 
with sides not necessarily parallel to the X and Y axes. 
If there is not any such rectangle, return 0.
Answers within 10-5 of the actual answer will be accepted.
*/


// Method 1
/*
Intuition
---------
* Write 3 for loops to get P1, P2, P3. 
* Then check if we have P4 in our points list. 

How to check if P1, P2, P3 are valid?
------------------------------------
p1 - p3 are end points of diagonal
using pythagoral theorem:  a^2 + b^2 = c^2

            a
   p1 * ------- * p2
                | 
                | b
                |
                * 
   p4            p3 

We have to check if we have p4 in our points list or not.


How to calculate P4?
--------------------        
                p2
                *
             (x2, y2)
      
      
       p1 *                * p3
    (x1, y1)               (x3, y3)

                 *
                 p4
              (x4, y4)
         

x4 = x1 + (x3 - x2)
y4 = y1 + (y3 - y2) 
   = y1 - (y2 - y3)

Note:
-----
* since P1, P2, P3 can be any orientation, we cannot write fopr loop like this
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {

            }
        }
    }

* we have to loop like this, to form all posible combinations of P1, P2, P3:
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {

            }
        }
    }
*/

class Solution {
public:
    double distSqr(auto &p1 , auto &p2){
        return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
    }

    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        for(auto it: points) {
            mp[it[0]].insert(it[1]);
        }

        double res = 1e9;

        for(auto &p1: points) {
            for(auto &p2: points) {
                if(p1 == p2) continue;
                for(auto &p3: points) {
                    if(p1 == p3 || p2 == p3) continue;

                    if(distSqr(p1, p2) + distSqr(p2, p3) != distSqr(p1,p3)) continue;

                    int x4 = p1[0] + (p3[0] - p2[0]);
                    int y4 = p1[1] + (p3[1] - p2[1]);

                    if(mp[x4].count(y4)) {
                        double area = sqrt(distSqr(p1, p2)) * sqrt(distSqr(p3, p2));
                        res = min(res, area);
                    }
                }
            }
        }

        return res == 1e9 ? 0 : res;
    }
};