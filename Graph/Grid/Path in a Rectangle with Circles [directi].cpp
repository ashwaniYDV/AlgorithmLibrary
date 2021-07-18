// https://www.geeksforgeeks.org/path-rectangle-containing-circles/
// https://www.interviewbit.com/problems/valid-path/

/*
There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.
Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.
Note :  We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.

Input Format
1st argument given is an Integer x.
2nd argument given is an Integer y.
3rd argument given is an Integer N, number of circles.
4th argument given is an Integer R, radius of each circle.
5th argument given is an Array X of size N, where X[i] = x cordinate of ith circle
6th argument given is an Array Y of size N, where Y[i] = y cordinate of ith circle

Output Format
Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).
*/


int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
 
string Solution::solve(int n, int m, int N, int r, vector<int> &X, vector<int> &Y) {
    int rect[n+1][m+1];
    memset(rect, 0 , sizeof(rect));
 
    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= m; j++)
            for(int k = 0; k < N; k++)
                if(sqrt(pow(X[k] - i, 2) + pow(Y[k] - j, 2)) <= r) {
                    rect[i][j] = 1;
                    break;
                }
 
    if(rect[0][0] == 1 || rect[n][m] == 1) return "NO";
 
    queue<pair<int,int> > q;
    q.push({0,0});
    rect[0][0] = 1;
 
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        if(x == n && y == m) return "YES";
 
        for(int i=0;i<8;i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx >= 0 && newx <= n && newy >= 0 && newy <= m && rect[newx][newy] == 0) {
                rect[newx][newy] = 1;
                q.push({newx,newy});
            }
        }
    }
    return "NO";
}
