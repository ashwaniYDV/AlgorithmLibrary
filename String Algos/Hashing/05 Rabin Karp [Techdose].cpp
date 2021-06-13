// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
// https://youtu.be/BQ9E-2umSWc


int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// d is the number of characters in the input alphabet 
#define d 256 

void search(string str, string pat, int q) { 
    int n = str.size(), m = pat.size(); 
    int hashStr = 0, hashPat = 0; 

    // h = d^(m-1) % q 
    int h = binpow(d, m - 1, q);

    // Calculate the hash value of pattern and string on first window of text 
    for (int i = 0; i < m; i++) { 
        hashPat = (hashPat * d + pat[i]) % q; 
        hashStr = (hashStr * d + str[i]) % q; 
    } 

    // Slide the pattern over text one by one 
    for (int i = 0; i <= n - m; i++) { 

        // Check the hash values of current window of text and pattern. 
        // If the hash values match then only check for characters on by one.
        if ( hashPat == hashStr ) { 
            /* Check for characters one by one */
            for (int j = 0; j < m; j++) { 
                if (str[i+j] != pat[j]) break; 

                // if p == t and pat[0...m-1] = str[i, i+1, ...i+m-1] 
                if (j == m-1) cout << "Pattern found at index "<< i << endl; 
            } 
        } 

        // Calculate hash value for next window of text: 
        // Remove leading digit, add trailing digit 
        if ( i < n-m ) { 
            hashStr = ((hashStr - str[i] * h) * d + str[i+m]) % q; 

            // We might get negative value of t, converting it to positive 
            if (hashStr < 0) 
            hashStr = (hashStr + q); 
        } 
    } 
} 


void solve() {
    string str = "GEEKS FOR GEEKS"; 
    string pat = "GEEK"; 
    int q = 101; // A prime number 
    search(str, pat, q); 
}
