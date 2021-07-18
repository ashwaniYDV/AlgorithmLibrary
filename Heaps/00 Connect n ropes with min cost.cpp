// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
// https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/

/*
There are given n ropes of different lengths, 
we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to the sum of their lengths. 
We need to connect the ropes with minimum cost.

For example, if we are given 4 ropes of lengths 4, 3, 2, and 6. 
We can connect the ropes in the following ways. 
1) First, connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6, and 5. 
2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9. 
3) Finally connect the two ropes and all ropes have connected.
Total cost for connecting all ropes is 5 + 9 + 15 = 29. 
*/

class Solution {
public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue < long long, vector < long long > , greater < long long >> minheap;
        for (int i = 0; i < n; i++) minheap.push(arr[i]);

        long long res = 0;
        while (minheap.size() > 1) {
            long long x = minheap.top();
            minheap.pop();
            long long y = minheap.top();
            minheap.pop();

            res += x + y;
            minheap.push(x + y);
        }
        return res;
    }
};
