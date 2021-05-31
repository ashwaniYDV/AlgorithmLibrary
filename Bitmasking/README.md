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
