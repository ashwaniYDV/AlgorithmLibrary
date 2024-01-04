// https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/

bool compare(string X, string Y) {
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY > YX;
}

void solve() {
    vector<string> arr = {"54", "546", "548", "60"};
    sort(arr.begin(), arr.end(), compare);
    
    // output should be 6054854654
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
    }
}
