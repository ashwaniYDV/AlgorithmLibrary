/*
Constraint:
number = consists of upto 1e6 digits without leading zero
divisor = [1, 1e9]
*/

// Method 1
void solve() {
    string number;
    int divisor;
    cin >> number;
    cin >> divisor;
    n = number.size();

    vector<int> remainder(n);
    
    remainder[0] = (number[0] - '0') % divisor;
    for(int i = 1; i < n; i++) {
        remainder[i] = (remainder[i - 1] * 10 + (number[i] - '0')) % divisor;
    }

    if(remainder[n - 1] == 0) {
        cout << number << " is divisible by " << divisor << endl;
    } else {
        cout << number << " is NOT divisible by " << divisor << endl;
    }
}






// Method 2
void solve() {
    string number;
    int divisor;
    cin >> number;
    cin >> divisor;
    n = number.size();

    vector<int> remainder(n);
    
    remainder[n - 1] = (number[n - 1] - '0') % divisor;
    int x = 10;
    for(int i = n - 2; i >= 0; i--) {
        remainder[i] = ((number[i] - '0') * x + remainder[i + 1]) % divisor;
        x = (x * 10) % divisor;
    }

    if(remainder[0] == 0) {
        cout << number << " is divisible by " << divisor << endl;
    } else {
        cout << number << " is NOT divisible by " << divisor << endl;
    }
} 
