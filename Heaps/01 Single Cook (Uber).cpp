// Uber interview question
// https://leetcode.com/problems/single-threaded-cpu/

/*
There as a single cook that gets n orders in a day. 
N orders are represented by a pair of array orders, where orders[i] = [startTime_i, cookingTime_i]
The cook cannot start cooking an order before startTime. 
If the cook is free and there are available orders, 
the cook will choose the one with the shortest cooking time. 
If multiple orders have the same shortest cooking time, 
it choose the order with the smallest index. 
Once the cook starts cooking an order, the cook finish the entire order (one at a time) 
Return the sequence of orders that the cook will pick up. 

Example 1: 
Input: 
orders = [[1, 2], [2,4], [3,2], [4,1]] 
Output: 
[0, 2, 3, 1]
*/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& orders) {
        // add idx at the back 
        for(int i = 0; i < orders.size(); i++) {
            orders[i].push_back(i);
        }
        // sort on basis of (startTime, cookingTime, idx)
        sort(orders.begin(), orders.end());

        vector<int> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int i = 0, n = orders.size();
        long long curTime = 0;

        while(!pq.empty() || i < n) {
            if (pq.empty()) {
                pq.push({ orders[i][1], orders[i][2] });
                curTime = max(curTime, (long long)orders[i][0]);
                i++;
            }

            while(i < n && orders[i][0] <= curTime) {
                pq.push({ orders[i][1], orders[i][2] });
                i++;
            }

            auto it = pq.top(); 
            pq.pop();
            int cookingTime = it[0], idx = it[1];
            
            res.push_back(idx); 
            curTime += cookingTime;
        }

        return res;
    }
};