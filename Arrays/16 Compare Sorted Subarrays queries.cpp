// https://www.scaler.com/problems/compare-sorted-subarrays

/*
Given an array A of length N. You have to answer Q queires.
Each query will contain 4 integers l1, r1, l2 and r2. If sorted segment from [l1, r1] is same as sorted segment from [l2 r2] then answer is 1 else 0.
NOTE The queries are 0-indexed.

Problem Constraints
0 <= A[i] <= 100000
1 <= N <= 100000
1 <= Q <= 100000


Input Format
First argument is an array A.
Second will be 2-D array B denoting queries with dimension Q * 4.
Consider ith query as l1 = B[i][0], r1 = B[i][1], l2 = A[i][2], r2 = B[i][3].

Output Format
Return an array of length Q with answer of the queries in the same order in input.



Input 1:
 A = [1, 7, 11, 8, 11, 7, 1]
 B = [ 
       [0, 2, 4, 6]
     ]
Output 1:
[1]

Input 2:
 A = [1, 3, 2]
 B = [
       [0, 1, 1, 2]
     ] 
Output 2: 
[0]
*/



/*
Think hashing.
Try to find a hash function f(a,b) for subarray [a,a+1,…b] such that chances of collisions are rare.


If both sub-arrays are exactly same after sorting then their sum of values will be same. 
So, we can just find the sum in range [l1, r1] and sum in range[l2, r2]. If they are different then we are sure that ans is 0. 
But, if they equal then? Consider two sub-arrays [3 5] and [4 4]. Both have sum 8 but still they are different.
Actually above approach fails because input can be carefully chosen.

Now, still we can use same idea but let first assign each value a unique random label from very big range like from 0 to 10^13 
(uoto 10^13 because no of queries can be upto 10^5 and thus the total can be upto 10^18 which will fit in long long). 
Now, probability of failure will be very less that can be neglected with given constraints.

Note: Any solution with random hashing is not 100% correct, possibility of failure exists. 
But with wide range of numbers probability of failure will be too small.

Note: Make sure that you are assign same label to all the occurrences. If value 5 comes 3 times then each 3 occurrences should be assigned same random label. 
Make sure you are using appropriate data type. Also, choosing big range like from 0 to 10^15 can overflow long long int.
*/





#define ll long long
const int N = 100000;
const ll RANGE = 1LL << 46;
unordered_map < int, ll > Hash;

// generates 46bit random number
ll rand46() {
    ll ret = (ll)rand() % RANGE;
    return ret;
}

/*
// we can do this also
ll rand46() {
    ll ret = 0LL, x;
    ret |= (ll)rand() % RANGE;
    x = (((ll)rand()) << 15);
    ret |= x;
    x = (((ll)rand()) << 20);
    ret |= x;
    return ret;
}
*/

void set_hash(vector < int > & a) {
    Hash.clear();
    srand(time(NULL));
    int n = a.size();
    for (int i = 0; i < n; i++) {
        auto it = Hash.find(a[i]);
        if (it == Hash.end()) { 
            Hash[a[i]] = rand46();
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = Hash[a[i]];
    }
}

vector < int > Solution::solve(vector < int > & a, vector < vector < int >> & lr) {
    int n = a.size();
    set_hash(a);
    vector < ll > prefSum(n, 0LL);
    prefSum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefSum[i] = prefSum[i - 1] + a[i];
    }
    int q = lr.size();
    vector < int > res;
    for (auto it: lr) {
        int l1 = it[0], r1 = it[1], l2 = it[2], r2 = it[3];
        ll sum1 = prefSum[r1] - ((l1 > 0) ? (prefSum[l1 - 1]) : (0LL));
        ll sum2 = prefSum[r2] - ((l2 > 0) ? (prefSum[l2 - 1]) : (0LL));
        res.push_back(sum1 == sum2);
    }
    return res;
}
