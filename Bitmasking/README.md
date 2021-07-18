### Some Techniques

1) Print all the subsets of a mask, i.e submasks (SOS DP suboptimal solution concept)

```
void solve() {
    int mask = 25; // any number
    for(int i = mask; i > 0; i = (i-1) & mask) {
        string s = bitset<32>(i).to_string();
        cout << s << endl;
    }
}

Output:
00000000000000000000000000011001
00000000000000000000000000011000
00000000000000000000000000010001
00000000000000000000000000010000
00000000000000000000000000001001
00000000000000000000000000001000
00000000000000000000000000000001

```

2) Sunny's "Adobe Emerge" interview question

You are given a very big file containing the binary representation of a natural number,find whether the number is divisible by 5 or not.

You are given a utility function which will tell you the current bit when you call it, the next time it is called it will give next bit, so on… once it gives anything apart from 0/1 , it means the file has ended.

I told him we keep on adding the modulo 5 of all powers iterating from LSB to MSB
Somewhat like ans = (ans + BinExp( 2, i , 5) ) % 5

He told the no of bits are so large that even i will overflow basically i cant even count the bits in a variable, i can just iterate over the file , and told me to think of another solution 

He repeatedly kept on saying this is a pure computer science fundamental problem and there is no pattern or trick for it and is an easy one. I couldn't make any sense  and couldn't solve it. After interview i found it is DFA problem (formal lang automata theory) (thats why he was saying basic CSF problem ;_;) (basically go from MSB to LSB and do next = (currnt*2 + bit)%5 )


https://www.quora.com/Is-there-a-pattern-to-binary-numbers-divisible-by-5

```
#include <bits/stdc++.h>
using namespace std;

int main() {
    int number, divisor;
    cin >> number;
    // can be generalized to any divisor, eg: (divisor = 13)
    divisor = 5;

    int cur = 0, next = 0;
    for (int i = 30; i >= 0; i--) {
        if (number & (1 << i)) {
            next = (cur * 2 + 1) % divisor;
        } else {
            next = (cur * 2 + 0) % divisor;
        }
        cur = next;
    }
    cout << "Remainder = " << cur << endl;
}
```
