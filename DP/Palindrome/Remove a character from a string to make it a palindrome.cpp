// https://www.geeksforgeeks.org/remove-character-string-make-palindrome/

bool isPalindrome(string s, int low, int high) {
    while (low < high) {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}

int possiblePalinByRemovingOneChar(string s) {
    int low = 0, high = s.size() - 1;

    while (low < high) {

        // If both characters are equal then move both pointer towards end
        if (s[low] == s[high]) {
            low++;
            high--;
        } else {
            if (isPalindrome(s, low + 1, high))
                return low;

            if (isPalindrome(s, low, high - 1))
                return high;

            // we cannot make s palindrome by removing one character
            return -1;
        }
    }

    // We reach here when complete string will be palindrome
    return -2;
}

void solve() {
    string s = "abcbea";
    int idx = possiblePalinByRemovingOneChar(s);

    if (idx == -1)
        cout << "Not Possible" << endl;
    else if (idx == -2)
        cout << "Possible without removing any character" << endl;
    else
        cout << "Possible by removing character at index " << idx << endl;
}
