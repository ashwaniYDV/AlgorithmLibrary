// Print all permutaions of string
// // https://youtu.be/JDOXKqF60RQ?si=J1UP_GzRsWXZtYU6


// Method 1: My own nextPermutation
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

void solve() {
    string s;
    cin >> s;

    // sorting is required
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while (nextPermutation(s));
}







// Method 2: Inbuilt next_permutation
void solve() {
    string s;
    cin >> s;
    // sorting is required
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}





class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return;

        // Find longest non-increasing suffix
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        // longest non-increasing suffix = nums[pivot+1 ... n-1]
        
        // Are we at the last permutation already?
        if (pivot == -1) {
            // return the first permutation
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Find rightmost element greater than the pivot
        for (int i = n - 1; i >= 0; i--) {
            if(nums[i] > nums[pivot]) {
                // Now str[i] will become the new pivot
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        
        // Reverse the suffix
        reverse(nums.begin() + pivot + 1, nums.end());
        // Successfully computed the next permutation
    }
};
