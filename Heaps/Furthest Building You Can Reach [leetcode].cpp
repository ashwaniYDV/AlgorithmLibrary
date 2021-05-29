/*
Explanation:
It's always optimal to use ladders in the largest jumps.

Heap pq store k height difference that we need to use ladders.
Each move, if the height difference d > 0,
we push d into the priority queue pq.
If the size of queue exceed ladders, it means we have to use bricks for one move.
Then we pop out the smallest difference, and reduce bricks.
If bricks < 0, we can't make this move, then we return current index i.
If we can reach the last building, we return n - 1.
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        for (int i = 0; i < n - 1; i++) {
            int d = heights[i + 1] - heights[i];
            if (d > 0)
                pq.push(-d); // minHeap = reverse maxHeap
            if (pq.size() > ladders) {
                bricks += pq.top();
                pq.pop();
            }
            if (bricks < 0)
                return i;
        }
        return n - 1;
        
    }
};





















// Cannot use DP since state variables are large = 1e9
class Solution {
public:
    int n;

    int go(int i, int bricks, int ladders, vector<int>& heights) {
        if(i == n-1) return 0;

        int res = 0;

        if(heights[i] >= heights[i+1]) {
            res = 1 + go(i+1, bricks, ladders, heights);
        } else {
            if(ladders > 0) {
                res = 1 + go(i+1, bricks, ladders - 1, heights);
            }

            int diff = heights[i+1] - heights[i];
            if(bricks >= diff) {
                int x = 1 + go(i+1, bricks - diff, ladders, heights);
                res = max(res, x);
            }
        }

        return res;
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n = heights.size();
        if(n == 1) {
            return 0;
        }
        return go(0, bricks, ladders, heights);
        
    }
};
