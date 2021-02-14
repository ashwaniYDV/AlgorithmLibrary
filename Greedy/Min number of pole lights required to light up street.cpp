// https://practice.geeksforgeeks.org/contest-problem/f1def6da30e4a24e4390a2be3da76b67533320c5/1/

/*
Make a vector<pair<int, int>> of all sprinklers and sort them wrt the starting point of their span.
Now set the target at the start of the gallery (= 0) and select the sprinkler which covers the target and reaches the furthest possible point (end of span).
Now, the target point moves one unit ahead of the end of span of the previously selected sprinkler. 
Repeat this process of selecting sprinklers till the complete gallery is covered.
*/

class Solution{
    public:
    int min_sprinklers(int gallery[], int n) {
        vector<pair<int,int>> range;

        for(int i = 0; i < n; i++) {
            if(gallery[i] != -1) {
                range.push_back({i - gallery[i], i + gallery[i]});
            }
        }
        
        sort(range.begin(), range.end());
        int m = range.size();
        
        int i = 0, target = 0, res = 0;
        while(target <= n-1) {
            if(i == m || range[i].first > target) {
                return -1;
            }
            
            int max_range = range[i].second;
            while( i < m && range[i].first <= target ) {
                max_range = max(max_range,  range[i].second);
                i++;
            }

            if(max_range < target) {
                return -1;
            }
            
            res++;
            target = max_range +1;
        }
        
        return res;
    }
};








class Solution{
    public:
    int min_sprinklers(int gallery[], int n) {
        vector<pair<int,int>> range;

        for(int i = 0; i < n; i++) {
            if(gallery[i] != -1) {
                range.push_back({i - gallery[i], i + gallery[i]});
            }
        }
        
        sort(range.begin(), range.end());
        int m = range.size();
        
        int i = 0, target = 0, res = 0;
        while(target <= n-1) {
            if(i == m || range[i].first > target) {
                return -1;
            }
            
            int max_range = range[i].second;
            while( i + 1 < m && range[i+1].first <= target ) {
                max_range = max(max_range,  range[i+1].second);
                i++;
            }

            if(max_range < target) {
                return -1;
            }
            
            res++;
            target = max_range +1;
            i++;
        }
        
        return res;
    }
};
