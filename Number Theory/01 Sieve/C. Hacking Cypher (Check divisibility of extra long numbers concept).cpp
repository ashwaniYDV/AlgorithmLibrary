/*
Problem:

Polycarpus is gievn a public key. The public key is a long integer which may consist of even a million digits!
Polycarpus needs to find such a way to cut the public key into two nonempty parts, that the first (left) part is divisible by a as a separate number, 
and the second (right) part is divisible by b as a separate number. 
Both parts should be positive integers that have no leading zeros. 
Polycarpus knows values a and b.

Help Polycarpus and find any suitable method to cut the public key.

Constrains:
String public key — an integer without leading zeroes, its length is in range from 1 to 10^6 digits. 
Integers a, b — (1  ≤  a,  b  ≤  10^8).
*/


/*
Editorial:

At first, let’s check all prefixes of specified number — do they have remainder 0 when divided by the a? 
It can be done with asymptotic behavior O(N), where N - length of specified number C. 
If we have remainder of division by a of prefix, which ends in position pos, we can count remainder in position pos + 1: 
rema[pos + 1] = (rema[pos] * 10 + C[pos + 1]) % a.

Then we need to check suffixes. 
If we have remainder of division by b of suffix, which begin in position pos, we can count remainder of position pos - 1: 
remb[pos - 1]  =  (C[pos  -  1]  *  P  +  remb[pos]) % b, where P — it is 10^(L - 1) module b, L — length of suffix (P we can count parallel).

Now let’s check all positions pos — can we cut specified number C in this position. 
We can do it if next four conditions performed: 
1) prefix of number C, which ends in pos is divisible by a; 
2) suffix of number C, which begin in pos + 1 is divisible by b; 
3) length of prefix and suffix more than 0; 
3) first digit of suffix is different from 0. If all four conditions performed we found answer. If we did not find any such positions, than print NO.
*/


/*
https://codeforces.com/blog/entry/14849?#comment-580420

rightRem explanation:

As we know number's length can be bigger than 10^6 so we have to make it smaller. (to check % b), so we go from rightmost number to leftard side.

Keep in mind that in modular arithmetic we have properties:
(a+b)%c = (a%c + b%c) % c
(a*b)%c = ((a%c) * (b%c)) % c

Suppose we have number = ......262 and b = 13.

Let's start from 62 we are interested in what is
(62 % 13),    62 = 6*10 + 2 ,
62 % 13 = (6*10 + 2) % 13 -> (6*10 % 13 + 2 % 13) % 13

Then take 262
262 = (2*100 + 6*10 + 2),
262 % 13 = (2*100 % 13 + 6*10 % 13 + 2 % 13) % 13 ,

But we already know (6*10 % 13 + 2 % 13) % 13 so we take it from previous step, and we have to make 1 more thing, 
because our number 100 can get 10 ^ 6, we have to make it smaller too, so we take (100 % 13), then ((100 % 13) * 10) % 13 and so on ... 
I hope it helps :d
*/

void solve() {
    string s;
    int a, b;
    cin>> s;
    cin>> a >> b;
    n = s.size();

    bool possible = false;

    vector<int> leftRem(n), rightRem(n);
    
    leftRem[0] = (s[0] - '0') % a;
    for(int i = 1; i < n; i++) {
        leftRem[i] = (leftRem[i - 1] * 10 + s[i] - '0') % a;
    }

    rightRem[n - 1] = (s[n - 1] - '0') % b;
    int x = 10;
    for(int i = n - 2; i >= 0; i--) {
        rightRem[i] = ((s[i] - '0') * x + rightRem[i + 1]) % b;
        x = (x * 10) % b;
    }
    
    string left, right;
    for(int i = 0; i < n - 1; i++) {
        if(leftRem[i] == 0 && rightRem[i + 1] == 0 && s[i+1] != '0') {
            possible = true;
            left = s.substr(0, i+1);
            right = s.substr(i+1, n - i);
            break;
        }
    }

    if(possible) {
        cout<< "YES" << endl ;
        cout<< left << endl << right ;
    } else {
        cout<< "NO";
    }
} 
