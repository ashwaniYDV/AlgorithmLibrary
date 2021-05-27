/*
Alpha-Beta Pruning Algorithm
----------------------------
Time Complexity : Best Case : O(b^(d/2))
				  Worst Case : O(b^d)
Space Complexity : O(n)
*/

// https://youtu.be/l-hh51ncgDI

int alpha_beta_minimax(int depth, int nodeIndex, bool isMax, vector<int>& scores, int alpha, int beta, int h) {
    // Terminating condition = leaf node is reached
    if (depth == h)
        return scores[nodeIndex];
 
    //  If current move is maximizer, find the maximum attainable value
    if (isMax) {
        int best = -INF;
        for (int i = 0; i < 2; i++) {
            int value = alpha_beta_minimax(depth + 1, 2 * nodeIndex + i, false, scores, alpha, beta, h);
            best = max(best, value);
            alpha = max(alpha, best);
            if (beta <= alpha) {
                break;
            }
        }
        return best;
    }
 
    // Else (If current move is Minimizer), find the minimum attainable value
    else {
        int best = INF;
        for (int i = 0; i < 2; i++) {
            int value = alpha_beta_minimax(depth + 1, 2 * nodeIndex + i, true, scores, alpha, beta, h);
            best = min(best, value);
            beta = min(beta, best);
            if (beta <= alpha) {
                break;
            }
        }
        return best;
    }
}
 

void solve() {
    // The number of elements in scores must be a power of 2.
    vector<int> scores = {3, 5, 2, 9, 12, 5, 23, 23};
    int n = scores.size();
    int h = (int)log2(n);
    int res = alpha_beta_minimax(0, 0, true, scores, -INF, +INF, h);
    cout << "The optimal value is : " << res << endl;
}
