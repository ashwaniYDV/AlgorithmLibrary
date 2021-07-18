// https://www.geeksforgeeks.org/count-maximum-points-on-same-line/
// https://practice.geeksforgeeks.org/problems/points-in-straight-line/1


/*
Given two array of integers X and Y describing a pair of (X[i], Y[i]) coordinates in 2D plane. 
X[i] describe x coordinates of the ith point in 2D plane whereas Y[i] describes the y-coordinate of the ith point in 2D plane.

Find and return the maximum number of points which lie on the same line.
*/



/*
If two point are (x1, y1) and (x2, y2) then their slope will be (y2 – y1) / (x2 – x1) which can be a double value and can cause precision problems.
To get rid of the precision problems, we treat slope as pair ((y2 – y1), (x2 – x1)) instead of ratio and reduce pair by their gcd before inserting into map.
Points which are vertical or repeated are treated separately.
Note: If we use map in c++ or HashMap in Java for storing the slope pair, then total time complexity of solution will be O(n^2 logn)
*/

/*
We can solve above problem by following approach – 
For each point p, calculate its slope with other points and use a map to record how many points have same slope, 
by which we can find out how many points are on same line with p as their one point. 
For each point keep doing the same thing and update the maximum number of point count found so far.
Some things to note in implementation are: 
1) if two point are (x1, y1) and (x2, y2) then their slope will be (y2 – y1) / (x2 – x1) 
   which can be a double value and can cause precision problems. 
   To get rid of the precision problems, we treat slope as pair ((y2 – y1), (x2 – x1)) instead of ratio 
   and reduce pair by their gcd before inserting into map. 
   In below code points which are vertical or repeated are treated separately.
2) If we use unordered_map in c++ or HashMap in Java for storing the slope pair, then total time complexity of solution will be O(n^2)
*/


class Solution {
public:
    int maxPoints(int X[], int Y[], int n) {
        if (n < 2) return n;
     
        int maxPoint = 0;
        int curMax, overlapPoints, verticalPoints;
     
        // looping for each point
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> slopeMap;
            curMax = overlapPoints = verticalPoints = 0;
     
            // looping from i + 1 to ignore same pair again
            for (int j = i + 1; j < n; j++) {
                // If both point are equal then just increase overlapPoint count
                if (X[i] == X[j] && Y[i] == Y[j]) {
                    overlapPoints++;
                }
     
                // If x co-ordinate is same, then both point are vertical to each other
                else if (X[i] == X[j]) {
                    verticalPoints++;
                }
                else {
                    int yDif = Y[j] - Y[i];
                    int xDif = X[j] - X[i];
                    int g = __gcd(xDif, yDif);
     
                    // reducing the difference by their gcd
                    yDif /= g;
                    xDif /= g;
     
                    // increasing the frequency of current slope in map
                    slopeMap[make_pair(yDif, xDif)]++;
                    curMax = max(curMax, slopeMap[{yDif, xDif}]);
                }
     
                curMax = max(curMax, verticalPoints);
            }
     
            // updating global maximum by current point's maximum
            maxPoint = max(maxPoint, curMax + overlapPoints + 1);
        }
     
        return maxPoint;
    }
};
