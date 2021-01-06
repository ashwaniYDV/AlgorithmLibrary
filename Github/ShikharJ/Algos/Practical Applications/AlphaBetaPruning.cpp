/*
Alpha-Beta Pruning Algorithm
----------------------------
Time Complexity : Best Case : O(b^(d/2))
				  Worst Case : O(b^d)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

int alpha_beta_minimax(int depth, int node_index, bool is_max, vector<int> &scores, int alpha, int beta, int height){
	if (depth == height){
		return scores[node_index];
	}

	if (is_max){
		int best = -999999999;
		for (int i = 0; i < 2; i++){
			int value = alpha_beta_minimax(depth + 1, 2 * node_index + i, false, scores, alpha, beta, height);
			best = max(best, value);
			alpha = max(alpha, best);
			if (beta <= alpha){
				break;
			}
		}
		return best;
	} else {
		int best = 999999999;
		for (int i = 0; i < 2; i++){
			int value = alpha_beta_minimax(depth + 1, 2 * node_index + i, true, scores, alpha, beta, height);
			best = min(best, value);
			beta = min(beta, best);
			if (beta <= alpha){
				break;
			}
		}
		return best;
	}
}