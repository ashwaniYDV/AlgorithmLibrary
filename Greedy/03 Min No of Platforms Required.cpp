// https://youtu.be/dxVcMDI7vyI
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1


// Method 1: O(n log n)
/*
The idea is to consider all events in sorted order. 
Once the events are in sorted order, trace the number of trains at any time keeping track of trains that have arrived, but not departed.
*/
class Solution{
public:
    // Function to find the minimum number of platforms required at the railway station such that no train waits.
    const int N = 1e5;
    
    int findPlatform(int arr[], int dep[], int n) {
        // Sort arrival and departure arrays
        sort(arr, arr + n);
        sort(dep, dep + n);
    
        // plat_needed indicates number of platforms needed at a time
        int plat_needed = 1, result = 1;
        int i = 1, j = 0;
    
        // Similar to merge in merge sort to process all events in sorted order
        while (i < n && j < n) {
            // If next event in sorted order is arrival, increment count of platforms needed
            // if (arr[i] < dep[j]) { // use this if necessary
            if (arr[i] <= dep[j]) {
                plat_needed++;
                i++;
            }
            // Else decrement count of platforms needed
            else {
                plat_needed--;
                j++;
            }
    
            result = max(result, plat_needed);
        }
    
        return result;
    }
};







// Method 2: O(nlogn)
class Solution {
public:
    // Function to find the minimum number of platforms required at the railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
        vector<pair<int, int> > vec;
        for (int i = 0; i < n; ++i) {
            vec.push_back({arr[i], 0});
            vec.push_back({dep[i], 1});
        }

        sort(vec.begin(), vec.end());

        int curActive = 0;
        int res = 0;
        for (int i = 0; i < vec.size(); i++) {
            // arrival
            if (vec[i].second == 0) {
                curActive++;
            } else {
                curActive--;
            }
            res = max(res, curActive);
        }

        return res;
    }
};








// Method 3.1: Cumulative Sum
class Solution{
public:
    // Function to find the minimum number of platforms required at the railway station such that no train waits.
    const int N = 1e5;
    
    int findPlatform(int arr[], int dep[], int n) {
        int pref[N] = {0};
    
        for(int i = 0; i < n; i++) {
            pref[arr[i]]++;
            pref[dep[i]+1]--;
        }
    
        for(int i = 1; i < N; i++) {
            pref[i] += pref[i-1];
        }
    
        int res = 0;
        for(int i = 0; i < N; i++) {
            res = max(res, pref[i]);
        }
    
        return res;
    }
};



// Method 3.2: Cumulative Sum
class Solution{
public:
    // Function to find the minimum number of platforms required at the railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
        map<int, int> prefix;
    
        for(int i = 0; i < n; i++) {
            prefix[arr[i]]++;
            prefix[dep[i]+1]--;
        }
        
        auto prevItr = prefix.begin();
        for(auto it = next(prefix.begin()); it != prefix.end(); it++) {
            prefix[it->first] += prefix[prevItr->first];
            prevItr = it;
        }
    
        int res = 0;
        for(auto it: prefix) {
            res = max(res, it.second);
        }
    
        return res;
    }
};