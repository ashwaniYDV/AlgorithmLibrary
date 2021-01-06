// https://leetcode.com/problems/maximal-rectangle/
// https://youtu.be/dAVF2NpC3j4

/*
Largest rectangle area in histogram concept is used here repetedly
*/

class Solution {
public:
    // Largest rectangle area in histogram function
    int largestRectangleAreaInHisto(vector<int>& heights) {
        int n = heights.size();
        int mxArea = 0;
        
        for(int i = 0; i < n; i++) {
            int h = heights[i];
            int left = 0, right = 0;
            
            for(int l = i - 1; l >= 0; l--) {
                if(heights[l] >= h) {
                    left++;
                } else {
                    break;
                }
            }
            for(int r = i + 1; r < n; r++) {
                if(heights[r] >= h) {
                    right++;
                } else {
                    break;
                }
            }
            
            int currArea = h * (left + right + 1);
            mxArea = max(mxArea, currArea);
        }
        return mxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        
        vector<vector<int>> heights(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0) {
                    heights[i][j] = matrix[i][j] - 48;
                } else {
                    if(matrix[i][j] == '0') {
                        heights[i][j] = 0;
                    } else {
                        heights[i][j] += (1 + heights[i - 1][j]);
                    }
                }
            }
        }
        
        int mxArea = 0;
        for(int i = 0; i < n; i++) {
            mxArea = max(mxArea, largestRectangleAreaInHisto(heights[i]));
        }
    
        return mxArea;
    }
};









/////////////////////////////////////////////////////////////////////

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
#define uniq(v) (v).erase(unique(all(v)),(v).end())
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

int largestRectangleAreaInHisto(vector<int>& heights) {
    int n = heights.size();
    int mxArea = 0;
    
    for(int i = 0; i < n; i++) {
        int h = heights[i];
        int left = 0, right = 0;
        
        for(int l = i - 1; l >= 0; l--) {
            if(heights[l] >= h) {
                left++;
            } else {
                break;
            }
        }
        for(int r = i + 1; r < n; r++) {
            if(heights[r] >= h) {
                right++;
            } else {
                break;
            }
        }
        
        int currArea = h * (left + right + 1);
        mxArea = max(mxArea, currArea);
    }
    
    return mxArea;
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    f(i, n) {
        f(j, m) {
            cin >> matrix[i][j];
        }
    }

    int mxArea = 0;
    mxArea = max(mxArea, largestRectangleAreaInHisto(matrix[0]));

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j]) {
                matrix[i][j] += matrix[i-1][j];
            }
        }

        mxArea = max(mxArea, largestRectangleAreaInHisto(matrix[i]));
    }
    
    cout << mxArea;
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
4 5
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0


Output:
6
*/
