// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

/*
There is a party where n friends numbered from 0 to n - 1 are attending. 
There is an infinite number of chairs in this party that are numbered from 0 to infinity. 
When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.
For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave.
If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], 
indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. 
All arrival times are distinct.
Return the chair number that the friend numbered targetFriend will sit on.

 
Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
Output: 1
Explanation: 
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.
Since friend 1 sat on chair 1, we return 1.

Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
Output: 2
Explanation: 
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.
*/

// Method 1.1
class Solution {
public:
    int smallestChair(vector<vector<int>>& A, int target) {
        int n = A.size();

        for(int i = 0; i < n; i++) {
            // A[i] = {arrival, dept, idx}
            A[i].push_back(i);
        }

        // sort on basis arrival time
        sort(A.begin(), A.end());

        set<int> unoccupiedChairs;
        set<pair<int, int>> occupiedChairs; // {deptTime, chairId}
        int newSeat = 0;

        for(auto& it: A) {
            int arrTime = it[0], deptTime = it[1], idx = it[2];

            // return back all occupied chairs to unoccupied chairs set for which
            // dept time of this chair <= current arr time
            while(!occupiedChairs.empty() && occupiedChairs.begin()->first <= arrTime) {
                unoccupiedChairs.insert(occupiedChairs.begin()->second);
                occupiedChairs.erase(occupiedChairs.begin());
            }

            int currentSeat;
            if(unoccupiedChairs.size() > 0) {
                currentSeat = *(unoccupiedChairs.begin());
                unoccupiedChairs.erase(currentSeat);
            } else {
                currentSeat = newSeat++;
            }

            occupiedChairs.insert({deptTime, currentSeat});

            if(idx == target) return currentSeat;
        }

        return -1;
    }
};

// Method 1.2
class Solution {
public:
    int smallestChair(vector<vector<int>>& A, int target) {
        int n = A.size();
        int arrTimeOfTarget = A[target][0]; // we can use this as an identifier since all arrival times are unique

        // sort on basis arrival time
        sort(A.begin(), A.end());

        set<int> unoccupiedChairs;
        set<pair<int, int>> occupiedChairs; // {deptTime, chairId}
        int newSeat = 0;

        for(auto& it: A) {
            int arrTime = it[0], deptTime = it[1];

            // return back all occupied chairs to unoccupied chairs set for which
            // dept time of this chair <= current arr time
            while(!occupiedChairs.empty() && occupiedChairs.begin()->first <= arrTime) {
                unoccupiedChairs.insert(occupiedChairs.begin()->second);
                occupiedChairs.erase(occupiedChairs.begin());
            }

            int currentSeat;
            if(unoccupiedChairs.size() > 0) {
                currentSeat = *(unoccupiedChairs.begin());
                unoccupiedChairs.erase(currentSeat);
            } else {
                currentSeat = newSeat++;
            }

            occupiedChairs.insert({deptTime, currentSeat});

            if(arrTimeOfTarget == arrTime) return currentSeat;
        }

        return -1;
    }
};



// Method 2
class Solution {
public:
    int smallestChair(vector<vector<int>>& A, int target) {
        int n = A.size();
        int arrTimeOfTarget = A[target][0]; // we can use this as an identifier since all arrival times are unique

        // sort on basis arrival time
        sort(A.begin(), A.end());

        set<int> unoccupiedChairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs; // {deptTime, chairId}
        int newSeat = 0;

        for(auto& it: A) {
            int arrTime = it[0], deptTime = it[1];

            // return back all occupied chairs to unoccupied chairs set for which
            // dept time of this chair <= current arr time
            while(!occupiedChairs.empty() && occupiedChairs.top().first <= arrTime) {
                unoccupiedChairs.insert(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            int currentSeat;
            if(unoccupiedChairs.size() > 0) {
                currentSeat = *(unoccupiedChairs.begin());
                unoccupiedChairs.erase(currentSeat);
            } else {
                currentSeat = newSeat++;
            }

            occupiedChairs.push({deptTime, currentSeat});

            if(arrTimeOfTarget == arrTime) return currentSeat;
        }

        return -1;
    }
};