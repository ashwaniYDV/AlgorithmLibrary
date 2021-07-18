// https://www.geeksforgeeks.org/count-pairs-in-array-whose-sum-is-divisible-by-k/
// https://practice.geeksforgeeks.org/problems/count-pairs-in-array-divisible-by-k/1/


class Solution {
public:
    int countKdivPairs(int A[], int n, int K) {
        // Create a frequency array to count occurrences of all remainders when divided by K
        int freq[K] = { 0 };

        // Count occurrences of all remainders
        for (int i = 0; i < n; i++) {
            A[i] = (A[i] + K) % K;
            freq[A[i]]++;
        }

        // If both pairs are divisible by 'K'
        int res = freq[0] * (freq[0] - 1) / 2;

        // If K is even
        if (K % 2 == 0) {
            res += (freq[K / 2] * (freq[K / 2] - 1) / 2);
        }

        // count for all i and (k-i) freq pairs
        for (int i = 1; i <= K / 2 && i != (K - i); i++) {
            res += freq[i] * freq[K - i];
        }
        return res;
    }
};
