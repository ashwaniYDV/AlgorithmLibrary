#include<bits/stdc++.h>
using namespace std;
 
const int N = 9;

void print(int grid[N][N]) {
    for (int i = 0; i < N; i++)  {
        for (int j = 0; j < N; j++) cout << grid[i][j] << " ";
        cout << endl;
    }
}

// Checks whether it will be legal to assign num to the given row, col
bool isSafe(int grid[N][N], int row, int col, int num) {
     
    // Check if we find the same num in the similar row, return false
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) return false;
    }
 
    // Check if we find the same num in the similar column, return false
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) return false;
    }

    // startRow, startCol of 3*3 sub-grid
    int startRow = row - row % 3; 
    int startCol = col - col % 3;
   
   	// Check if we find the same num in the particular 3*3 sub-grid, return false
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }
 
    return true;
}

bool solveSuduko(int grid[N][N], int row, int col) {
    // base case
    // Check if we have reached the 8th row and 9th column (0 indexed matrix)
    if (row == N - 1 && col == N) {
    	return true;
    }
 
    // base case
    // Check if column value becomes 9, we move to next row and column start from 0
    if (col == N) {
        row++;
        col = 0;
    }
   
    // Check if the current position of the grid already contains value > 0
    if (grid[row][col] > 0) {
        return solveSuduko(grid, row, col + 1);
    }
 
    for (int num = 1; num <= N; num++) {
         
        // Check if it is safe to place the num (1-9)  in the given row ,col  
        // --> we move to next column
        if (isSafe(grid, row, col, num)) {
        	grid[row][col] = num;
           
            // Checking for next possibility with next column
            if (solveSuduko(grid, row, col + 1)) {
                return true;
            }
        }
       
        // Removing the assigned num, since our assumption was wrong, 
        // and we go for next assumption with diff num value
        grid[row][col] = 0;
    }

    return false;
}

void solve() {
    // 0 means unassigned cells
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
 
    if (solveSuduko(grid, 0, 0)) print(grid);
    else cout << "No solution  exists" << endl;
}
 
int32_t main() {
	// IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}
