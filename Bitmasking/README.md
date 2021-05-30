### Some Techniques

1) Print all the subsets of a mask (SOS DP suboptimal solution concept)

```
void solve() {
    int mask = 432; // any number
    for(int i = mask; i > 0; i = (i-1) & mask) {
        string s = bitset<32>(i).to_string();
        cout << s << endl;
    }
}
```
