// https://www.techiedelight.com/calculate-rank-lexicographically-sorted-permutations/
// https://www.interviewbit.com/problems/sorted-permutation-rank/
// https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/

/*
Let the given string be “STRING”. In the input string, ‘S’ is the first character. 
There are total 6 characters and 4 of them are smaller than ‘S’. 
So there can be 4 * 5! smaller strings where first character is smaller than ‘S’, like following
R X X X X X 
I X X X X X 
N X X X X X 
G X X X X X

Now let us Fix ‘S’ and find the smaller strings starting with ‘S’.


Repeat the same process for T, rank is 4*5! + 4*4! +…
Now fix T and repeat the same process for R, rank is 4*5! + 4*4! + 3*3! +…
Now fix R and repeat the same process for I, rank is 4*5! + 4*4! + 3*3! + 1*2! +…
Now fix I and repeat the same process for N, rank is 4*5! + 4*4! + 3*3! + 1*2! + 1*1! +…
Now fix N and repeat the same process for G, rank is 4*5! + 4*4! + 3*3! + 1*2! + 1*1! + 0*0!
Rank = 4*5! + 4*4! + 3*3! + 1*2! + 1*1! + 0*0! = 597
Note that the above computations find count of smaller strings. 
Therefore rank of given string is count of smaller strings plus 1. The final rank = 1 + 597 = 598
*/



// Function to find the lexicographic rank of a string
// O(n^2)
#include <bits/stdc++.h>
using namespace std;

#define mod 1000003;

int fact(int n) {
    if (n == 0) return 1;
    return (n * fact(n - 1)) % mod;
}

int findRank(string s) {
    int res = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[i])
                c++;
        }
        res += ( (c * fact(n - i - 1)) ) % mod;
    }
    // res = cnt of smaller strings + 1
    return (res + 1 ) % mod;
}


int main() {
    string str = "ACBFR";

    cout << findRank(str) << endl;

    return 0;
}














// A O(n) solution for finding rank of string
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 256

// A utility function to find factorial of n
int fact(int n) {
    return (n <= 1) ? 1 : n * fact(n - 1);
}

// Construct a count array where value at every index
// contains count of smaller characters in whole string
void populateAndIncreaseCount(int* count, string str) {
    for (int i = 0; i < str.size(); ++i)
        ++count[str[i]];

    for (int i = 1; i < MAX_CHAR; ++i)
        count[i] += count[i - 1];
}

// Removes a character ch from count[] array
// constructed by populateAndIncreaseCount()
void updatecount(int* count, char ch) {
    for (int i = ch; i < MAX_CHAR; ++i)
        --count[i];
}

// A function to find rank of a string in all permutations of characters
int findRank(string str) {
    int n = str.size();
    int mul = fact(n);
    int rank = 1;

    // all elements of count[] are initialized with 0
    int count[MAX_CHAR] = { 0 };

    // Populate the count array such that count[i]
    // contains count of characters which are present
    // in str and are smaller than i
    populateAndIncreaseCount(count, str);

    for (int i = 0; i < n; ++i) {
        mul /= n - i;

        // count number of chars smaller than str[i]
        // fron str[i+1] to str[len-1]
        rank += count[str[i] - 1] * mul;

        // Reduce count of characters greater than str[i]
        updatecount(count, str[i]);
    }

    return rank;
}

// Driver program to test above function
int main() {
    string str = "string";
    cout << findRank(str);
    return 0;
}
