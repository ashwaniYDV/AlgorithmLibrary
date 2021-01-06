/*
Same as classic interval scheduling problem

The greedy choice is to always pick the next activity whose finish time is least among the remaining activities 
and the start time is more than or equal to the finish time of previously selected activity. 
We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.

1) Sort the activities according to their finishing time
2) Select the first activity from the sorted array and print it.
3) Do following for remaining activities in the sorted array.
4) If the start time of this activity is greater than or equal to the finish time of previously selected activity then select this activity and print it.
*/


#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fa(i,a,n) for(int i=a;i<n;i++)
#define loop(i,a, n) for(int i = a; i <= n; i++)
#define loopb(i,a, n) for(int i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5 + 5;
const int N = 1e5+5;
int n, m;

struct  Interval {
    int start;
    int end;
};

bool compare(Interval& i1, Interval& i2) { 
    return i1.end < i2.end;
}

void solve() {
    int x, y;
    cin >> n;
    Interval arr[n];
    f(i, n) {
        cin >> x >> y;
        // { start, end }
        arr[i] = {x, y};
    }
    
    // sort in ascending order of end time
    sort(arr, arr + n, compare);
    
    int end = arr[0].end;
    int count = 1;
    
    for (int i = 1; i < n; i++) {
        // If this activity has start time >= the finish time of previously selected activity, then select it 
        if (arr[i].start >= end) {
            end = arr[i].end;
            count++;
        }
    }
    cout << count << endl;
}
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}

/*
Input:
6
1 2
3 4
0 6
5 7
8 9
5 9

Output:
4
*/
