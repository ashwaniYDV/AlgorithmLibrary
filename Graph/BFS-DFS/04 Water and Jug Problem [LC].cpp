// https://leetcode.com/problems/water-and-jug-problem/

/*
You are given two jugs with capacities x liters and y liters. 
You have an infinite water supply. 
Return whether the total amount of water in both jugs may reach target using the following operations:
a) Fill either jug completely with water.
b) Completely empty either jug.
c) Pour water from one jug into another until the receiving jug is full, or the transferring jug is empty.
 
Input: x = 3, y = 5, target = 4
Output: true
Explanation: Follow these steps to reach a total of 4 liters:
  Fill the 5-liter jug (0, 5).
  Pour from the 5-liter jug into the 3-liter jug, leaving 2 liters (3, 2).
  Empty the 3-liter jug (0, 2).
  Transfer the 2 liters from the 5-liter jug to the 3-liter jug (2, 0).
  Fill the 5-liter jug again (2, 5).
  Pour from the 5-liter jug into the 3-liter jug until the 3-liter jug is full. This leaves 4 liters in the 5-liter jug (3, 4).
  Empty the 3-liter jug. Now, you have exactly 4 liters in the 5-liter jug (0, 4).

Constraints:
1 <= x, y, target <= 10^3
*/


class Solution {
public:
    const int N = 1e3+1;
    void makeBfsCall(int a, int b, queue<array<int, 2>>& q, vector<vector<bool>>& vis) {
        if(vis[a][b]) return;
        q.push({a, b});
        vis[a][b] = 1;
    }
    bool canMeasureWater(int x, int y, int target) {
        queue<array<int, 2>> q;
        vector<vector<bool>> vis(N, vector<bool>(N, false));

        q.push({0, 0});
        vis[0][0] = 1;

        while(!q.empty()) {
            auto it = q.front(); q.pop();

            if(it[0] + it[1] == target) return 1;

            // case 1: Fill either jug completely with water
            makeBfsCall(x, it[1], q, vis);
            makeBfsCall(it[0], y, q, vis);

            // case 2: Completely empty either jug
            makeBfsCall(0, it[1], q, vis);
            makeBfsCall(it[0], 0, q, vis);

            // case 3: Pour water from one jug into another until the receiving jug is full, or the transferring jug is empty
            int transferFrom0to1 = min(it[0], y - it[1]);
            makeBfsCall(it[0] -  transferFrom0to1, it[1] + transferFrom0to1, q, vis);
            int transferFrom1to0 = min(it[1], x - it[0]);
            makeBfsCall(it[0] +  transferFrom1to0, it[1] - transferFrom1to0, q, vis);
        }

        return 0;
    }
};
