// https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/description/

/*
You are given an integer array nums of length n.
You start at index 0, and your goal is to reach index n - 1.
From any index i, you may perform one of the following operations:
  - Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
  - Prime Teleportation: If nums[i] is a prime number p, you may instantly jump to any index j != i such that nums[j] % p == 0.
Return the minimum number of jumps required to reach index n - 1.


Example 1:
Input: nums = [1,2,4,6]
Output: 2
Explanation:
One optimal sequence of jumps is:
Start at index i = 0. Take an adjacent step to index 1.
At index i = 1, nums[1] = 2 is a prime number. Therefore, we teleport to index i = 3 as nums[3] = 6 is divisible by 2.
Thus, the answer is 2.

Example 2:
Input: nums = [2,3,4,7,9]
Output: 2
Explanation:
One optimal sequence of jumps is:
Start at index i = 0. Take an adjacent step to index i = 1.
At index i = 1, nums[1] = 3 is a prime number. Therefore, we teleport to index i = 4 since nums[4] = 9 is divisible by 3.
Thus, the answer is 2.

Example 3:
Input: nums = [4,6,5,8]
Output: 3
Explanation:
Since no teleportation is possible, we move through 0 → 1 → 2 → 3. Thus, the answer is 3.
 

Constraints:
1 <= n == nums.length <= 10^5
1 <= nums[i] <= 106
*/

class Solution {
    struct Sieve {
        vector<int> spf;

        Sieve(int n) {
            spf.resize(n + 1);

            for(int i = 0; i <= n; i++) {
                spf[i] = i;
            }

            for(int i = 2; i * i <= n; i++) {
                if(spf[i] == i) {
                    for(int j = i * i; j <= n; j += i) {
                        if(spf[j] == j) {
                            spf[j] = i;
                        }
                    }
                }
            }
        }

        bool isPrime(int x) {
            return x > 1 && spf[x] == x;
        }

        vector<int> getFactors(int x) {
            vector<int> v;

            while(x > 1) {
                int p = spf[x];
                v.push_back(p);

                while(x % p == 0) {
                    x /= p;
                }
            }

            return v;
        }
    };

public:
    static const int MAXN = 1e6;

    int bfs(int src, int dest, int n, vector<int>& a, unordered_map<int, vector<int>>& idxs, Sieve& sieve) {
        vector<int> dist(n, -1);
        queue<int> q;

        q.push(0);
        dist[0] = 0;

        unordered_set<int> usedPrime;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            if(u == n-1) {
                return dist[u];
            }

            if(u-1 >= 0 && dist[u-1] == -1) {
                dist[u-1] = dist[u] + 1;
                q.push(u-1);
            }

            if(u+1 < n && dist[u+1] == -1) {
                dist[u+1] = dist[u] + 1;
                q.push(u+1);
            }

            int val = a[u];

            if(sieve.isPrime(val) && !usedPrime.count(val)) {
                usedPrime.insert(val);

                for(int v: idxs[val]) {
                    if(dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        return -1;
    }

    int minJumps(vector<int>& a) {
        static Sieve sieve(MAXN); // NOTE: if we dont use static it gives TLE
        int n = a.size();

        unordered_map<int, vector<int>> idxs;

        // build prime -> indices
        for(int i = 0; i < n; i++) {
            for(int p: sieve.getFactors(a[i])) {
                idxs[p].push_back(i);
            }
        }

        return bfs(0, n-1, n, a, idxs, sieve);
    }
};
