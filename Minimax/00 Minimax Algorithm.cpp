/*
Minimax Algorithm
-----------------
Time Complexity : Best, Average and Worst Case : O(b^d)
Space Complexity : O(n)
*/

// https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-1-introduction/
// https://youtu.be/Ntu8nNBL28o
// https://youtu.be/l-hh51ncgDI   (minimax and alpha-beta pruning)

/*
Minimax is a kind of backtracking algorithm that is used in decision making and game theory to find the optimal move for a player, 
assuming that your opponent also plays optimally. 
It is widely used in two player turn-based games such as Tic-Tac-Toe, Backgammon, Mancala, Chess, etc.
In Minimax the two players are called maximizer and minimizer. 
The maximizer tries to get the highest score possible while the minimizer tries to do the opposite and get the lowest score possible.
*/

/*
Example: 
Consider a game which has 4 final states and paths to reach final state are from root to 4 leaves of a perfect binary tree as shown below. 
Assume you are the maximizing player and you get the first chance to move, i.e., you are at the root and your opponent at next level. 
Which move you would make as a maximizing player considering that your opponent also plays optimally?

Function minimax returns the optimal value a maximizer can obtain.

depth = current depth in game tree.
nodeIndex = index of current node in scores[].
isMax = true if current move is of maximizer, else false
scores[] = stores leaves of Game tree.
h = maximum height of Game tree
*/

int minimax(int depth, int nodeIndex, bool isMax, vector<int>& scores, int h) {
    // Terminating condition = leaf node is reached
    if (depth == h)
        return scores[nodeIndex];
 
    //  If current move is maximizer, find the maximum attainable value
    if (isMax) {
        int l = minimax(depth+1, nodeIndex*2, false, scores, h);
        int r = minimax(depth+1, nodeIndex*2 + 1, false, scores, h);
       return max(l, r);
    }
 
    // Else (If current move is Minimizer), find the minimum attainable value
    else {
        int l = minimax(depth+1, nodeIndex*2, true, scores, h);
        int r = minimax(depth+1, nodeIndex*2 + 1, true, scores, h);
        return min(l, r);
    }
}
 

void solve() {
    // The number of elements in scores must be a power of 2.
    vector<int> scores = {3, 5, 2, 9, 12, 5, 23, 23};
    int n = scores.size();
    int h = (int)log2(n);
    int res = minimax(0, 0, true, scores, h);
    cout << "The optimal value is : " << res << endl;
}

signed main() {
    IOS
    int t = 1;
    // cin >> t;
    f(i, t) {
        solve();
    }
}
