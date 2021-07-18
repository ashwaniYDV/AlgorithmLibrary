// https://leetcode.com/problems/greatest-common-divisor-traversal/

/*
You are given a 0-indexed integer array nums, 
and you are allowed to traverse between its indices. 
You can traverse between index i and index j, i != j, 
if and only if gcd(nums[i], nums[j]) > 1.
Your task is to determine if for every pair of indices i and j in nums, 
where i < j, there exists a sequence of traversals that can take us from i to j.
Return true if it is possible to traverse between all such pairs of indices, or false otherwise.
*/

/*
Intuition
---------
* Get distinct prime factors of each nums[i]
  Eg: 4 = [2]
      6 = [2, 3]
      11 = [11]
      15 = [3, 5]
      16 = [2]
* Create a list of indexes for each prime factor. 
  (For explanation I have shown nums[i], but we can store i)
  Each prime factor stores the indexs of nums whose prime factor is this number.
  2 = [4, 6, 16]
  3 = [6, 15]
  5 = [15]
  11 = [11]
* Now we can see that (4, 6, 16) form a component; (6, 15) form a connected component
* We can use DSU to form and join these connected components
*/


// First read this TLE solution to understand concept
class Solution {
    struct Sieve {
        vector<bool> isprime;
        vector<int> spf;

        Sieve(int n) {
            isprime.resize(n+1, true);
            spf.resize(n+1);

            for(int i = 0; i <= n; i++) {
                isprime[i] = true;
                spf[i] = i;
            }
            
            isprime[0] = isprime[1] = false;
            for(int i = 2; i * i <= n; i++) {
                if(isprime[i]) {
                    for(int j = i * i; j <= n; j += i) {
                        isprime[j] = false;
                        spf[j] = min(spf[j], i);
                    }
                }
            }
        }

        vector<int> getDistinctPrimeFactors(int x) {
            vector<int> v;
            while(x > 1) {
                int p = spf[x];
                while(x % p == 0) {
                    x /= p;
                }
                v.push_back(p);
            }
            return v;
        }
    };

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
        bool sameSet(int x, int y) { 
            return findParent(x) == findParent(y); 
        }
        int size (int x) { 
            return -par[findParent(x)]; 
        }
    };
public:
    const int N = 1e5+5;
    int n;

    bool canTraverseAllPairs(vector<int>& nums) {
        n = nums.size();
        Sieve sieve(N);
        DSU dsu(n);

        vector<vector<int>> allIndexesOfEachPrimeFactor(N);

        for(int i = 0; i < n; i++) {
            for(int prime: sieve.getDistinctPrimeFactors(nums[i])) {
                allIndexesOfEachPrimeFactor[prime].push_back(i);
            }
        }

        for(auto it: allIndexesOfEachPrimeFactor) {
            for(int i = 1; i < it.size(); i++) {
                dsu.unionSet(it[0], it[i]);
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(dsu.findParent(i) == i) cnt++;
        }

        return cnt == 1;
    }
};


// Accepted Solution
class Solution {
    struct Sieve {
        vector<bool> isprime;
        vector<int> spf;

        Sieve(int n) {
            isprime.resize(n+1, true);
            spf.resize(n+1);

            for(int i = 0; i <= n; i++) {
                isprime[i] = true;
                spf[i] = i;
            }
            
            isprime[0] = isprime[1] = false;
            for(int i = 2; i * i <= n; i++) {
                if(isprime[i]) {
                    for(int j = i * i; j <= n; j += i) {
                        isprime[j] = false;
                        spf[j] = min(spf[j], i);
                    }
                }
            }
        }

        vector<int> getDistinctPrimeFactors(int x) {
            vector<int> v;
            while(x > 1) {
                int p = spf[x];
                while(x % p == 0) {
                    x /= p;
                }
                v.push_back(p);
            }
            return v;
        }
    };

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
        bool sameSet(int x, int y) { 
            return findParent(x) == findParent(y); 
        }
        int size (int x) { 
            return -par[findParent(x)]; 
        }
    };
public:
    const int N = 1e5+5;
    int n;

    bool canTraverseAllPairs(vector<int>& nums) {
        n = nums.size();
        Sieve sieve(N);
        DSU dsu(n);

        vector<int> firstIndexOfEachPrimeFactor(N, -1);

        for(int i = 0; i < n; i++) {
            for(int prime: sieve.getDistinctPrimeFactors(nums[i])) {
                if(firstIndexOfEachPrimeFactor[prime] == -1) {
                    firstIndexOfEachPrimeFactor[prime] = i;
                } else {
                    dsu.unionSet(firstIndexOfEachPrimeFactor[prime], i);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(dsu.findParent(i) == i) cnt++;
        }

        return cnt == 1;
    }
};