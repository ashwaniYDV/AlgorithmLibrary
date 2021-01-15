// https://www.geeksforgeeks.org/count-set-bits-in-bitwise-xor-of-all-adjacent-elements-upto-n/

/*
If the position of the rightmost set bit of X is K, then count of set bits in (X ^ (X – 1)) must be K. 
*/

#include <bits/stdc++.h>
using namespace std;
 
// Funtion to count of set bits in Bitwise XOR of adjacent elements up to N
int countXORSetBitsAdjElemRange1_N(int N) {

    // Stores count of set bits by Bitwise XOR on adjacent elements of [0, N]
    int total_set_bits = 0;
 

    // Stores all possible values on right most set bit over [0, N]
    int bit_Position = 1;
 

    // Iterate over the range [0, N]
    while (N) {
        total_set_bits += ((N + 1) / 2 * bit_Position);

        // Update N
        N -= (N + 1) / 2;

        // Update bit_Position
        bit_Position++;

    }

    return total_set_bits;
}


int main() {
    int N = 4;
    cout << countXORSetBitsAdjElemRange1_N(N);
    return 0;
}
