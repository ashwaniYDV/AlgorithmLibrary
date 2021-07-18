// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
// https://youtu.be/o8emK4ehhq0

/*
There are n workers. 
You are given two integer arrays quality and wage where 
    quality[i] is quality of ith worker and 
    wage[i] is the min wage expectation for ith worker.
We want to hire exactly k workers to form a paid group. 
To hire a group of k workers, we must pay them according to following rules:
    a) Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
    b) Every worker in the paid group must be paid at least their minimum wage expectation.
Given integer k, return the least amount of money needed to form a paid group satisfying above conditions. 


Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
*/



/*
Intuition
==========

Let offer[i] is the money given to i'th worker

Given rules can be written as:
a) offer[i] / offer[j] = quality[i] / quality[j]
   or
   offer[i] / quality[i] = offer[j] / quality[j]
b) offer[i] >= wage[i]

NOTE:
-------
There will be atleast one worker in the k workers group that is paid equal to his expected wage 
(i.e. offer[i] = wage[i] for some i and let's call this i'th worker captain)

offer[captain] = wage[captain]                                    -------------- (i)

offer[i] / offer[captain] = quality[i] / quality[captain]
offer[i] = (quality[i] / quality[captain]) * offer[captain]       -------------- (ii)

From (i), (ii):
offer[i] = (quality[i] / quality[captain]) * wage[captain]

offer[i] = quality[i] * (wage[captain] / quality[captain])
offer[i] = quality[i] * captainsRatio

Thus once the captain is decided, total sum can be calculated as:
total = (quality[i1] * captainsRatio) + (quality[i2] * captainsRatio) + ... + (quality[ik] * captainsRatio)
total = (quality[i1] + quality[i2] + ... + quality[ik]) * captainsRatio


Condition for any worker to be captain:
offer[i] >= wage[i]
quality[i] * captainsRatio >= wage[i]
captainsRatio >= wage[i] / quality[i]
captainsRatio >= workersRatio

Thus the captain is one having the highest worker ratio among the k workers.
*/


class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        
        vector<array<double, 2>> workers;
        for (int i = 0; i < n; ++i) {
            workers.push_back({(double)(wage[i]) / quality[i], (double)quality[i]});
        }

        // sort on basis of captainsRatio
        sort(workers.begin(), workers.end());

        double res = DBL_MAX, qualitySum = 0;
        // max heap to maintain top k smallest
        priority_queue<int> pq;

        for (auto it : workers) {
            double captainsRatio = it[0];
            int quality = it[1];

            while (pq.size() >= k) {
                qualitySum -= pq.top();
                pq.pop();
            }
            // now pq contains less than k elements 

            // add current element
            pq.push(quality);
            qualitySum += quality;

            // since we want exactly k (and not atmost k)
            if (pq.size() == k) {
                res = min(res, qualitySum * captainsRatio);
            }
        }
        return res;
    }
};
