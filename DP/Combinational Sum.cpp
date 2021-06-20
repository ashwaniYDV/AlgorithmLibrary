/*
Given an array of positive integers arr[] and a sum x, find all unique combinations in arr[] where the sum is equal to x. 
The same repeated number may be chosen from arr[] unlimited number of times. 
Elements in a combination (a1, a2, …, ak) must be printed in non-descending order. (ie, a1 <= a2 <= … <= ak). 
The combinations themselves must be sorted in ascending order, i.e., the combination with smallest first element should be printed first. 
*/

void combinationSum(vector<ll>& ar, ll sum, vector<vector<ll> >& res, vector<ll>& curr, ll index) { 
    if (sum < 0) return;
    if (sum == 0) { 
        res.push_back(curr); 
        return;
    } 
  
    // Recur for all remaining elements that have value smaller than sum. 
    // for(ll i=index; i<ar.size() && sum-ar[i]>=0; i++) {
    for(ll i=index; i<ar.size(); i++){
        // Till every element in the array starting from i which can contribute to the sum add them to list
        curr.push_back(ar[i]); 
        // recur for next numbers 
        combinationSum(ar, sum - ar[i], res, curr, i); 
        // remove number from list (backtracking) 
        curr.pop_back(); 
    } 
} 

void solve() {
    vector<int> ar = {2, 4, 8, 6, 8}; 
    int sum = 8;
 
    n = ar.size();

    // sort input array 
    sort(ar.begin(), ar.end()); 
    // remove duplicates 
    ar.erase(unique(ar.begin(), ar.end()), ar.end()); 

    vector<int> curr; 
    vector<vector<int> > res; 

    combinationSum(ar, sum, res, curr, 0); 

    for (int i = 0; i < res.size(); i++) { 
        for (int j = 0; j < res[i].size(); j++) 
            cout << res[i][j] << " "; 
        cout << "\n"; 
    } 
}
