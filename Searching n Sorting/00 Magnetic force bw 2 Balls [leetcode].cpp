// https://leetcode.com/problems/magnetic-force-between-two-balls/

/*
It is same as aggressive cows.
==============================

In the universe Earth C-137, Rick discovered a special form of magnetic force 
between two balls if they are put in his new invented basket. 
Rick has n empty baskets, the ith basket is at position[i], 
Morty has m balls and needs to distribute the balls into the baskets 
such that the minimum magnetic force between any two balls is maximum.
Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
Given the integer array position and the integer m. 
Return the required force.
*/


// TTTTTTTTTTFFFFFFFFF


// Method 1
class Solution {
public:
    bool check(int mid, vector<int>& position, int m) {
        int cnt = 1, prevPos = 0;
        for(int i = 1; i < position.size(); i++) {
            if(position[i] - position[prevPos] >= mid) {
                prevPos = i, cnt++;
            }
        }
        return cnt >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
    
        int lo = 0, hi = position[position.size()-1];
        while(lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;

            if(check(mid, position, m)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};


// Method 2
class Solution {
public:
    bool check(int mid, vector<int>& position, int m) {
        int cnt = 1, prevPos = 0;
        for(int i = 1; i < position.size(); i++) {
            if(position[i] - position[prevPos] >= mid) {
                prevPos = i, cnt++;
            }
        }
        return cnt >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
    
        int lo = 0, hi = position[position.size()-1];
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(check(mid, position, m)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
};