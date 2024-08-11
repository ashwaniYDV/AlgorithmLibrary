// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

/*
There are n cities numbered from 0 to n-1. 
Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold.
If there are multiple such cities, return the city with the greatest number.
*/

class Solution {
public:
    const int INF = 1e9;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dis[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)
                    dis[i][j] = 0;
                else
                    dis[i][j] = INF;
            }
        }
        
        for(auto i: edges){
            int u = i[0], v = i[1], w = i[2];
            dis[u][v] = w;
            dis[v][u] = w;
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
                }
            }
        }
        
        int ans = -1;
        int mn = INF;
        for(int i = 0; i < n; i++){
            int ct = 0;
            for(int j = 0; j < n; j++){
                if(dis[i][j] <= distanceThreshold) ct++;
            }
            if(ct <= mn) {
                mn = ct;
                ans = i;
            }
        }
        
        return ans;
    }
};