// https://codeforces.com/contest/1535/problem/D

/*
Official Editorial for hints:
Denote cnti as the number of teams that can be winners in the i-th game. The answer to the problem is cnt2k−1.
If the i-th game is played between the winners of games x and y (x < y), then:
cnti = cntx if si = 0;
cnti = cnty if si = 1;
cnti = cntx + cnty if si = ?
So we can calculate all values of cnt for the initial string.
Note that the result of no more than k other games depends on the result of any game. 
So, if we change sp, it will change no more than k values of cnt, and we can recalculate all of them.
*/
 
/*
We will reverse the string so that answer is at tree[1]
Since string is reversed, 0 and 1 meaning here is reversed as well
tree[i] = tree[2*i] if si = 1;
tree[i] = tree[2*i+1] if si = 0;
tree[i] = tree[2*i] + tree[2*i+1] if si = ?
For convenience, you can renumerate the games so that the playoff looks like a segment tree, 
i. e. the final has the number 1, the semifinals have numbers 2 and 3, etc.
n+1 = all the palyers
We build segment tree on all the players
But we only go to one level above the leaf nodes 
i.e. players which is the level of initial game between two players
We initialize tree with 1 so that all the leaf nodes are having value 1
Base case of build is at level one above leaf node
*/

int n, m;
int k;
string s;
vi tree(8e6, 1);

void build(int i, int l, int r) {
    // one level abobe
    if(l == r-1) {
        if(s[i] == '?') {
            tree[i] = 2;
        }else{
            tree[i] = 1;
        }
        return;
    }

    int mid = (l + r) / 2;

    build(2*i, l, mid);
    build(2*i+1, mid+1, r);

    if(s[i] == '1') {
        tree[i] = tree[2*i];
    }else if(s[i] == '0') {
        tree[i] = tree[2*i+1];
    }else{
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

void update(int i) {
    while(i) {
        if(s[i] == '1') {
            tree[i] = tree[2*i];
        } else if(s[i] == '0') {
            tree[i] = tree[2*i+1];
        } else {
            tree[i] = tree[2*i] + tree[2*i+1];
        }
        i /= 2;
    }
}

void solve() {
    int x, y, z, q;
    cin >> k;
    cin >> s;
    s += '#';
    reverse(all(s));

    n = (1 << k) - 1;
    build(1, 1, n+1);

    cin >> q;
    int i;
    char ch;
    while(q--) {
        cin >> i >> ch;
        i = n - i + 1;
        s[i] = ch;
        update(i);
        cout << tree[1] << endl;
    }
}
 
signed main() {
    IOS
    int t = 1;
    // cin >> t;
    f(i, t) {
        solve();
    }
}
