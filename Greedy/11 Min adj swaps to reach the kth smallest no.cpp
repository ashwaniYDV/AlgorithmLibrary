// https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/

/*
You are given a string num, representing a large integer, and an integer k.

We call some integer wonderful if it is a permutation of the digits in num and is greater in value than num. 
There can be many wonderful integers. 
However, we only care about the smallest-valued ones.

Return min no of adjacent digit swaps that needs to be applied to num to reach kth smallest wonderful integer.

For example, when num = "5489355142":
The 1st smallest wonderful integer is "5489355214".
The 2nd smallest wonderful integer is "5489355241".
The 3rd smallest wonderful integer is "5489355412".
The 4th smallest wonderful integer is "5489355421".

The tests are generated in such a way that kth smallest wonderful integer exists.


Example 1:
Input: num = "5489355142", k = 4
Output: 2
Explanation: The 4th smallest wonderful number is "5489355421". 
To get this number:
- Swap index 7 with index 8: "5489355142" -> "5489355412"
- Swap index 8 with index 9: "5489355412" -> "5489355421"
*/


class Solution {
public:
    // Function to return min no of adjacent swaps to convert a string s1 into its given anagram s2
    int minAdjSwaps(string s1, string s2) {
        int n = s1.size();
        int result = 0;

        // Iterate over the first string and convert every element equal to the second string
        for (int i = 0; i < n; i++) {
            int j = i;

            // Find index element of first string which is equal to the ith element of second string
            while (s1[j] != s2[i]) {
                j++;
            }

            // Swap adjacent elements in first string so that element at ith position becomes equal
            while (j > i) {
                // Swap elements using temporary variable
                swap(s1[j], s1[j - 1]);
                j--;
                result++;
            }
        }
        return result;
    }
    int getMinSwaps(string num, int k) {
        string nextNum = num;
        // Find the next permutation of the given string k times.
        while (k--) {
            next_permutation(nextNum.begin(), nextNum.end());
        }

        // Min no of adjacent swaps to convert a string into its given anagram
        return minAdjSwaps(num, nextNum);
    }
};












class Solution {
public:
    bool nextPermutation(string& str) {
        int n = str.size();
        if (n == 0) return false;
        // Find longest non-increasing suffix
        int i = n - 1;
        while (i > 0 && str[i - 1] >= str[i]) {
            i--;
        }
        // Now i is the head index of the suffix

        // Are we at the last permutation already?
        if (i == 0)
            return false;

        // Let str[i - 1] be the pivot
        // Find rightmost element greater than the pivot
        int j = n - 1;
        while (str[j] <= str[i - 1]) {
            j--;
        }
        // Now the value str[j] will become the new pivot
        // Assertion: j >= i

        // Swap the pivot with j
        swap(str[i - 1], str[j]);

        // Reverse the suffix
        reverse(str.begin() + i, str.end());
        // Successfully computed the next permutation
        return true;
    }

    // Function to return min no of adjacent swaps to convert a string s1 into its given anagram s2
    int minAdjSwaps(string s1, string s2) {
        int n = s1.size();
        int result = 0;

        // Iterate over the first string and convert every element equal to the second string
        for (int i = 0; i < n; i++) {
            int j = i;

            // Find index element of first string which is equal to the ith element of second string
            while (s1[j] != s2[i]) {
                j++;
            }

            // Swap adjacent elements in first string so that element at ith position becomes equal
            while (j > i) {
                // Swap elements using temporary variable
                swap(s1[j], s1[j - 1]);
                j--;
                result++;
            }
        }
        return result;
    }
    int getMinSwaps(string num, int k) {
        string nextNum = num;
        // Find the next permutation of the given string k times.
        while (k--) {
            nextPermutation(nextNum);
        }

        // Min no of adjacent swaps to convert a string into its given anagram
        return minAdjSwaps(num, nextNum);
    }
};
