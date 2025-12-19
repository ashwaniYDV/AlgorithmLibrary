// https://leetcode.com/problems/find-all-people-with-secret/description/

/*
You are given an integer n indicating there are n people numbered from 0 to n - 1. 
You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. 
A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.
Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. 
This secret is then shared every time a meeting takes place with a person that has the secret. 
More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.
The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.
Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.

 

Example 1:
Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
Output: [0,1,2,3,5]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 5, person 1 shares the secret with person 2.
At time 8, person 2 shares the secret with person 3.
At time 10, person 1 shares the secret with person 5.​​​​
Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.

Example 2:
Input: n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
Output: [0,1,3]
Explanation:
At time 0, person 0 shares the secret with person 3.
At time 2, neither person 1 nor person 2 know the secret.
At time 3, person 3 shares the secret with person 0 and person 1.
Thus, people 0, 1, and 3 know the secret after all the meetings.

Example 3:
Input: n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
Output: [0,1,2,3,4]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 1, person 1 shares the secret with person 2, and person 2 shares the secret with person 3.
Note that person 2 can share the secret at the same time as receiving it.
At time 2, person 3 shares the secret with person 4.
Thus, people 0, 1, 2, 3, and 4 know the secret after all the meetings.
 

Constraints:
2 <= n <= 10^5
1 <= meetings.length <= 10^5
meetings[i].length == 3
0 <= xi, yi <= n - 1
xi != yi
1 <= timei <= 10^5
1 <= firstPerson <= n - 1
*/


class Solution {
public:
    // Union-Find with Reset
    struct DSU {
        vector<int> par;
        DSU(int n) {
            par.resize(n+1, -1);
        }
        int findParent(int a) {
            if(par[a] < 0) return a;
            return par[a] = findParent(par[a]);
        }
        bool unionSet(int a, int b){
            a = findParent(a);
            b = findParent(b);
            if(a == b) return 0;
            if(par[a] > par[b]) swap(a,b);
            par[a] += par[b];
            par[b] = a;
            return 1;
        }
        void reset (int x) { 
            par[x] = -1; 
        }
        bool sameSet(int x, int y) { 
            return findParent(x) == findParent(y); 
        }
        int size (int x) { 
            return -par[findParent(x)]; 
        }
    };

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        DSU dsu(n);

        // sort meetings in increasing order of time
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        dsu.unionSet(0, firstPerson);

        int i = 0;
        while (i < meetings.size()) {
            // Group Meetings occuring at the same time
            int start = i;
            while(i < meetings.size() && meetings[start][2] == meetings[i][2]) {
                int x = meetings[i][0], y = meetings[i][1];
                dsu.unionSet(x, y); // Unite two persons taking part in a meeting
                i++;
            }
            int end = i - 1;

            // If any one knows the secret, both will be connected to 0.
            // If no one knows the secret, then reset.
            for(int j = start; j <= end; j++) {
                int x = meetings[j][0], y = meetings[j][1];

                // No need to check for y since x and y were united
                if(!dsu.sameSet(0, x)) {
                    // reset since they do not shared the secret
                    dsu.reset(x);
                    dsu.reset(y);
                }
            }
        }

        vector<int> res;

        // Al those who are connected to 0 will know the secret
        for(int i = 0; i < n; i++) {
            if(dsu.sameSet(0, i)) res.push_back(i);
        }

        return res;
    }
};
