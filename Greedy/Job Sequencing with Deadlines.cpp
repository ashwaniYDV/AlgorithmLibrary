// https://www.youtube.com/watch?v=zPtI8q9gvX8

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


struct Job { 
   char id;     // Job Id 
   int dead;    // Deadline of job 
   int profit;  // Profit if job is over before or on deadline 
}; 

bool compare(Job& j1, Job& j2) { 
    return j1.profit > j2.profit;
}

void printJobScheduling(Job arr[], int n) { 
    // Sort all jobs according to decreasing order of prfit 
    sort(arr, arr+n, compare); 
  
    int result[n]; // To store result (Sequence of jobs) 
    bool slot[n];  // To keep track of free time slots 
  
    // Initialize all slots to be free 
    for (int i=0; i<n; i++) 
        slot[i] = false; 
  
    // Iterate through all given jobs 
    for (int i=0; i<n; i++) { 
       // Find a free slot for this job (Note that we start from the last possible slot) 
       for (int j=min(n, arr[i].dead)-1; j>=0; j--) { 
          // Free slot found 
          if (slot[j]==false) { 
             result[j] = i;  // Add this job to result 
             slot[j] = true; // Make this slot occupied 
             break; 
          } 
       } 
    } 
  
    int totalProfit = 0;
    // Print the result 
    for (int i=0; i<n; i++) {
       if (slot[i]) {
         cout << "JobId = " << arr[result[i]].id << ", Slot = " << i << "-" << i+1 << endl; 
         totalProfit += arr[result[i]].profit;
       }
    }

    cout << endl << "Total Profit: " << totalProfit << endl;
}

void solve() {
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}}; 
    n = sizeof(arr)/sizeof(arr[0]); 

    cout << "Maximum profit sequence of jobs \n"; 
    
    printJobScheduling(arr, n); 
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
Output:

Maximum profit sequence of jobs 
JobId = c, Slot = 0-1
JobId = a, Slot = 1-2
JobId = e, Slot = 2-3

Total Profit: 142
*/
