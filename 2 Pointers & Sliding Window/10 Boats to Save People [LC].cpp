// https://leetcode.com/problems/boats-to-save-people/

/*
You are given an array people where people[i] is the weight of the ith person, 
and an infinite number of boats where each boat can carry a maximum weight of limit. 
Each boat carries at most two people at the same time, 
provided the sum of the weight of those people is at most limit.
Return the min number of boats to carry every given person.
*/

/*
Steps:
------
1) Sort the array
2) Try to fill people from right side with more weights
3) Try to fill remaining limit weight people from left side with less weights
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int l = 0, r = people.size() - 1;
        int res = 0;

        while(l <= r) {
            int sum = 0, cnt = 0;
            while(l <= r && (sum + people[r] <= limit) && cnt < 2) {
                sum += people[r--];
                cnt++;
            }

            while(l <= r && (sum + people[l] <= limit) && cnt < 2) {
                sum += people[l++];
                cnt++;
            }

            res++;
        }

        return res;
    }
};