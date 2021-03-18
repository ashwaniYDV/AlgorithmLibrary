https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/

const int N = 4;
int n, m; 

/* A utility function to print solution */
void printSolution(int board[N][N]) { 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " "; 
        }
        cout << endl;
    } 
} 

bool isSafe(int board[N][N], int row, int col) { 
  
    /* Check this row on left side */
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return false; 
    }
  
    /* Check upper diagonal on left side */
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false; 
    }
  
    /* Check lower diagonal on left side */
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) return false; 
    }
  
    return true; 
} 
  
bool solveNQUtil(int board[N][N], int col) { 
    if (col >= N) return true; 
  
    for (int i = 0; i < N; i++) { 
        if (isSafe(board, i, col)) { 
            board[i][col] = 1; 

            if (solveNQUtil(board, col + 1)) return true; 
  
            board[i][col] = 0;
        } 
    } 
    return false; 
} 

void solve() { 
    int board[N][N] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 } }; 
  
    if (solveNQUtil(board, 0)) { 
        printSolution(board); 
        return;
    }
    
    cout << "Solution does not exist" << endl; 
} 
 
signed main() {
	IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}
