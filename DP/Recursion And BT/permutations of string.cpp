// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

void permute(string s, int l, int r) {
    // Base case  
    if (l == r) {
        cout << s << endl;
        return;
    }
    // Permutations made  
    for (int i = l; i <= r; i++) {  

        // Swapping done  
        swap(s[l], s[i]);

        // Recursion called  
        permute(s, l+1, r);  

        //backtrack  
        swap(s[l], s[i]);  
    }
}

void solve() {
    string s;
    cin >> s;
    permute(s, 0, s.size() - 1);
}   
