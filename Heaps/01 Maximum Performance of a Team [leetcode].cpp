// https://leetcode.com/problems/maximum-performance-of-a-team/

class Solution {
public:
    #define ll long long
    #define MOD 1000000007
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<ll, ll>> a;
        for(ll i = 0; i < n; i++) {
            a.push_back({efficiency[i], speed[i]});
        }
        
        // sort in desc order on basis of efficiency
        sort(a.rbegin(), a.rend());
        
        // stores sum of k maximum speeds upto current index whose minimum efficiency is current element
        // we can use minHeap as well
        multiset<int> st;
        
        ll res = 0, speedSum = 0;
        
        for(ll i = 0; i < n; i++) {
            ll minEff = a[i].first, spd = a[i].second;
            speedSum += spd;
            res = max(res, speedSum * minEff);
            
            st.insert(spd);
            // track sum of (k-1) maximum speeds
            if(st.size() >= k) {
                speedSum -= (*st.begin());
                st.erase(st.begin());
            }
        }
        return (int)(res % MOD);
    }
};










class Solution {
public:
    #define ll long long
    #define MOD 1000000007

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
            vector<pair<int, int>> ess(n);
            for (int i = 0; i < n; ++i) {
                ess[i] = {efficiency[i], speed[i]};
            }

            // sort in desc order on basis of efficiency
            sort(rbegin(ess), rend(ess));

            long sumS = 0, res = 0;
            priority_queue <int, vector<int>, greater<int>> pq; //min heap

            for(auto& [e, s]: ess){
                pq.emplace(s);
                sumS += s;
                if (pq.size() > k) {
                    sumS -= pq.top();
                    pq.pop();
                }
                res = max(res, sumS * e);
            }
            return res % (int)(1e9+7);
    }
};