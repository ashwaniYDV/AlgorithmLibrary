/*
There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are (x, y).
We start at the source = [sx, sy] square and want to reach the target = [tx, ty] square. 
There is also an array of blocked squares, where each blocked[i] = [xi, yi] represents a blocked square with coordinates (xi, yi).
Each move, we can walk one square north, east, south, or west if the square is not in the array of blocked squares. We are also not allowed to walk outside of the grid.
Return true if and only if it is possible to reach the target square from the source square through a sequence of valid moves.

Constraints:
0 <= blocked.length <= 200
blocked[i].length == 2
0 <= xi, yi < 10^6
source.length == target.length == 2
0 <= sx, sy, tx, ty < 10^6
source != target
It is guaranteed that source and target are not blocked.

Hint 1
If we become stuck, there's either a loop around the source or around the target.
Hint 2
If there is a loop around say, the source, what is the maximum number of squares it can have?
*/

class Solution {
private:
    const int MAX_STEPS = 400;
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool dfs(vector<int> cur,
             vector<int>& source,
             vector<int>& target,
             unordered_set<string>& block,
             unordered_set<string>& visited) {
        
        if (cur[0] == target[0] && cur[1] == target[1])
            return true;
        
        // If expanded beyond 200 Manhattan distance, escape is possible
        if (abs(source[0] - cur[0]) + abs(source[1] - cur[1]) > MAX_STEPS)
            return true;
        
        string key = to_string(cur[0]) + "->" + to_string(cur[1]);
        visited.insert(key);
        
        for (auto& d : dirs) {
            int r = cur[0] + d.first;
            int c = cur[1] + d.second;
            
            string nextKey = to_string(r) + "->" + to_string(c);
            
            if (r >= 0 && r < 1e6 &&
                c >= 0 && c < 1e6 &&
                !block.count(nextKey) &&
                !visited.count(nextKey)) {
                
                if (dfs({r, c}, source, target, block, visited))
                    return true;
            }
        }
        
        return false;
    }

public:
    bool isEscapePossible(vector<vector<int>>& blocked,
                          vector<int>& source,
                          vector<int>& target) {
        
        unordered_set<string> block;
        for (auto& p : blocked) {
            block.insert(to_string(p[0]) + "->" + to_string(p[1]));
        }
        
        unordered_set<string> visited1, visited2;
        
        return dfs(source, source, target, block, visited1) &&
               dfs(target, target, source, block, visited2);
    }
};
