/*
Minimax Algorithm
-----------------
Time Complexity : Best, Average and Worst Case : O(b^d)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

int minimax(int depth, int node_index, bool is_max, vector<int> &scores, int height){
	if (depth == height){
		return scores[node_index];
	}

	if (is_max){
		return max(minimax(depth + 1, 2 * node_index, false, scores, height), 
			minimax(depth + 1, 2 * node_index + 1, false, scores, height));
	} else{
		return min(minimax(depth + 1, 2 * node_index, true, scores, height), 
			minimax(depth + 1, 2 * node_index + 1, true, scores, height));
	}
}