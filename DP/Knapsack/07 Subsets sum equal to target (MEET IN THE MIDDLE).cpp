// https://cses.fi/alon/result/12049928/
// https://www.linkedin.com/feed/update/urn:li:activity:7294709623507357697/

/*
You are given an array of n numbers. 
In how many ways can you choose a subset of the numbers with sum x?

Constraints
1 <= n <= 40
1 <= x <= 10^9
1 <= a[i] <= 10^9
*/


/*
Case 2: When constrains are such that DP cannot be used.
We have to use meet in the middle approach.


If the constraints were n <= 20 or even maybe 21. You could brute force it.
But the array size is 40. 
Well, so now you break the array into 2 and brute force each, and combine the results. 
In "cool" terms this is often referred to as 'Meet in the Middle'. 
*/




/*
This is somehow giving TLE due to hashmap
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void generateSubsetSums(const vector<int>& a, unordered_map<int, int>& sumFreq) {
    int n = (int)a.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum += a[i];
        }
        sumFreq[sum]++;
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int n, sum;
    cin >> n >> sum;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int mid = n / 2;
    vector<int> leftPart(a.begin(), a.begin() + mid);
    vector<int> rightPart(a.begin() + mid, a.end());
 
    unordered_map<int, int> leftSums, rightSums;
    
    generateSubsetSums(leftPart, leftSums);
    generateSubsetSums(rightPart, rightSums);
 
    int res = 0;
    for (auto& [sum1, freq1] : leftSums) {
        int required = sum - sum1;
        res += freq1 * rightSums[required];
    }
 
    cout << res << "\n";
    return 0;
}



/*
This passed
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void allSubsetSums(vector<int>& a, vector<int>& sums) {
    int n = a.size();
    
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1LL << i)) {
                sum += a[i];
            }
        }
        sums.push_back(sum);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, sum, x;
    cin >> n >> sum;
    
    vector<int> firstHalf, secondHalf;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i < n / 2) firstHalf.push_back(x);
        else secondHalf.push_back(x);
    }

    vector<int> s1, s2;
    allSubsetSums(firstHalf, s1);
    allSubsetSums(secondHalf, s2);
    
    sort(s2.begin(), s2.end()); // Sort second half for binary search

    int res = 0;
    for (int val : s1) {
        int target = sum - val;
        res += upper_bound(s2.begin(), s2.end(), target) - lower_bound(s2.begin(), s2.end(), target);
    }

    cout << res << endl;
}
