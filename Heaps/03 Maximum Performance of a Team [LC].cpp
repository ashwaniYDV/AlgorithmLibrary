// https://leetcode.com/problems/maximum-performance-of-a-team/

/*
You are given two integers n and k and two integer arrays speed and efficiency both of length n. 
There are n engineers numbered from 1 to n. 
speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.
Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
Performance of a team is sum of their engineers' speeds multiplied by min efficiency among their engineers.
Return maximum performance of this team. Since answer can be a huge, return it modulo 10^9+7.
 

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation: 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). 
That is, performance = (10 + 5) * min(4, 7) = 60.

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72
*/




/*
It is tough to maintain both sum of speed and minimum of efficiency and to find optimal answer.
In this type of questions we have to fix a parameter, here we can fix minimum efficiency.
If we sort {efficiency,speed} in decreasing efficiency, we know for ith efficiency, since everything from 1 to i-1
is more than it, ith is the minimum. 
So from 1 to i-1 if we have the sum of best k-1 speeds we can team them
with ith and we do this for every i and keep taking its maximum.
Note that to find top k sum we can use a heap and maintain its size as less than equal to k and also
keep track of sum of the elements present in heap
*/


class Solution {
public:
    #define ll long long
    #define mod 1000000007
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // to maintain top k sum
        priority_queue <int, vector <int>, greater <int>> pq;
        
        vector <pair<ll, ll>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({efficiency[i], speed[i]});
        }
        
        // sorting in decreasing order of efficiency
        sort(v.rbegin(), v.rend());
        
        ll sum = 0, res = 0;
        for(int i = 0; i < n; i++) {
            ll cur_min = v[i].first;
            ll spd = v[i].second;
            
            while(pq.size() >= k) {
                sum -= pq.top();
                pq.pop();
            }
            // now pq contains less than k elements 
            
            // add current element
            pq.push(spd);
            sum += spd;
            res = max(res, sum * cur_min);
        }
        
        res %= mod;
        return res;
    }
};
