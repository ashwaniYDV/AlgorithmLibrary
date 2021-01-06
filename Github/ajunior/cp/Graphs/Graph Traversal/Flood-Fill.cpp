#include <bits/stdc++.h>

#define C 1010
#define R 1010

using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

char grid[R][C];

int flood_fill(int r, int c, char c1, char c2){
    if(r < 0 || r >= R || c < 0 || c >= C) return 0;
    if(grid[r][c] != c1) return 0;

    int ans = 1;
    grid[r][c] = c2;

    for(int d = 0; d < 8; d++)
        ans += flood_fill(r + dr[d], c + dc[d], c1, c2);
    return ans;
}

int main(){
    return 0;
}
