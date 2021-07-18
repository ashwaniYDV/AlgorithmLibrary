### next_permutation

![next_permutation](https://www.nayuki.io/res/next-lexicographical-permutation-algorithm/next-permutation-algorithm.svg)

```cpp
bool nextPermutation(string& str) {
    int n = str.size();
    if(n == 0) return false;
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
```
