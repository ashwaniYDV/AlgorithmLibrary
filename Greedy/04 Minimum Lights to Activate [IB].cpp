// https://www.interviewbit.com/problems/minimum-lights-to-activate/

/*
There is a corridor in a Jail which is N units long. 
Given an array A of size N. 
The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.
All the lights are of specific power B which if is placed at position X, it can light the corridor from [ X-B+1, X+B-1].
Initially all lights are off.
Return min no of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.

Input 1:
A = [ 0, 0, 1, 1, 1, 0, 0, 1].
B = 3
Outout 1:
2

Input 2:
A = [ 0, 0, 0, 1, 0].
B = 3
Outout 2:
-1
*/



// Method 1: Street bulb lighting concept
int Solution::solve(vector<int>& A, int B) {
    int n = A.size();
    vector<pair<int,int>> range;
    for(int i = 0; i < n; i++) {
        if(A[i] == 1) {
            range.push_back({i - (B - 1), i + (B - 1)});
        }
    }
    
    // sorting not required, as it is already sorted
    // sort(range.begin(), range.end());
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


// Method 2: space optimized
int Solution::solve(vector<int>& a, int B) {
    int n = a.size();
    
    int i = 0, target = 0, res = 0;
    while(target <= n-1 && i < n) {
        if(a[i] == 0) {
            i++;
            continue;
        }
        
        // left > target
        if((i - (B - 1)) > target) {
            return -1;
        }
        
        int max_range = 0;
        while(i < n && (a[i] == 0 || (i - (B - 1)) <= target)) {
            if(a[i] == 1)
                max_range = max(max_range,  i + (B - 1));  
            i++;
        }

        if(max_range < target) {
            return -1;
        }
        
        res++;
        target = max_range + 1;
    }
    
    if(target <= n-1) return -1;
    return res;
}
