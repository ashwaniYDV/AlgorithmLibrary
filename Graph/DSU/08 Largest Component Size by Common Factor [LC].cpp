// https://leetcode.com/problems/largest-component-size-by-common-factor/

/*
You are given an integer array of unique positive integers nums. 
Consider the following graph:
There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.
*/


/*
We have to find the largest size of connected component.

We can store for all the prime factors of nums[i] as keys in a map
and values will be all those nums[i] which have this key as its factor

2 -> [n1, n4, n5, , ]
5 -> [n1, n3, n4, , ]
7 -> [n2, n4, n5, , ]
.
.
.

In above example, n1 is present in both 2 and 5, 
so 2 and 5 components will combine to form a larger common component.

n4 is present in both 5 and 7, 
so 5 and 7 components will combine to form a larger common component.

Overall, all 2, 5, 7 components will combine.
*/ 


class Solution {
public:
    static const int N = 1e5+5;

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

        set<int> getUniqueFactors(int x) {
            set<int> v;
            while(x > 1) {
                v.insert(spf[x]);
                x /= spf[x];
            }
            return v;
        }
    };

    int largestComponentSize(vector<int>& nums) {
        DSU dsu(N);
        Sieve sieve(N);
        unordered_map<int, vector<int>> mp;

        for(int x: nums) {
            set<int> st = sieve.getUniqueFactors(x);
            for(int prime: st) {
                mp[prime].push_back(x);
            } 
        }

        for(auto it: mp) {
            int prime = it.first;
            if(mp[prime].size() < 1) continue;
            
            for(int j = 1; j < mp[prime].size(); j++) {
                dsu.unionSet(mp[prime][0], mp[prime][j]);
            } 
        }

        int mx = 0;
        for(int x: nums) {
            mx = max(mx, dsu.size(x));
        }
        return mx;
    }
};