// https://www.geeksforgeeks.org/minimum-sprinkers-required-to-be-turned-on-to-water-the-plants/
// https://practice.geeksforgeeks.org/problems/410d51d667ab93f2219b15126f001f32e8bb029e/1/

/*
A gallery with plants is divided into n parts, numbered : 0,1,2,3...n-1. 
There are provisions for attaching water sprinklers at every partition. 
A sprinkler with range x at partition i can water all partitions from i-x to i+x.
Given an array gallery[] consisting of n integers, where gallery[i] is the range of sprinkler at partition i (power == -1 indicates no sprinkler attached), 
return the minimum number of sprinklers that need to be turned on to water the complete gallery.
If there is no possible way to water the full length using the given sprinklers, print -1.

Input:
n = 6
gallery[ ] = {-1, 2, 2, -1, 0, 0}
Output:
2
Explanation: Sprinklers at index 2 and 5 can water thefull gallery, span of sprinkler at index 2 = [0,4] and sprinkler at index 5 = [5,5].
*/


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
            
            int max_range = 0;
            while( i < m && range[i].first <= target ) {
                max_range = max(max_range,  range[i].second);
                i++;
            }

            if(max_range < target) {
                return -1;
            }
            
            res++;
            target = max_range + 1;
        }
        
        return res;
    }
};
