// https://atcoder.jp/contests/dp/tasks/dp_k
// https://youtu.be/HTbMXXURjF4

/*
Impartial games: 
In this type of game, 
the set of allowable moves depends only on the position of the game 
and not on which of the two players is moving. 
For example, Nim, sprouts, and green hackenbush are impartial, 
while games like tik-tak-toe and chess are not (they are called partisan).
*/

/*
In this proble we are given an impartial game. 
In this type pf game every state is either a winning state ( = 1) pr a losing state ( = 0),
considering ki game draw nhi ho rha hai. 
Draw tabhi hota hai jab game state me koi cyclic dependency ho.
Finite games kabhi na kabhi terminate hote hi hai.

In this problem K hamesha khatam ho jaega thus ye game hmesha end hoga without draw.

First player = Player which starts first.



Losing state = Losing state us state ko kehte hai jis state se agar game start hua ho 
                to first player chahe kitna bhi acha khele use second player hara sake.

Winning state = Winning state us state ko kehte hai jis state se agar game start hua ho  
                to first player optimally khele to chahe second player kitna bhi achha khele 
                first player jeet jaega.



Relation between winning and losing state:
   Jo bhi ek winning state hogi usse jitni bhi edges bahar ja rahi hai 
   unse se atleast ek losing state hogi. 
   (har move kisi doosri state ko correspond kregi) 
   
   Kehne ka matlab ye hai ki agar first player kuch aisi move chal de 
   ki jab second player ki move ae to vo ek losing state pe pahuch jae. 

Game state depends on number of remaining stones only. 
*/




/*
dp[i] = 1 when player 1 can win till the i'th move, (where i from 0 to k)

Answer = dp[k]

Base case:
if k = 0 then first player cannot play a move and loses
dp[0] = 0


Transition:

If x pick karke second player losing state par ja sakta hai 
then i first player ke lie winning state hai

for (int x: a) {
    if(i >= x && dp[i - x] == 0) {
        dp[i] = 1;
        break;
    }
}
*/


int dp[N];

void solve() {
    int x, y, k;
    cin >> n >> k;
    vi a(n);

    for(int& x: a) 
        cin >> x;

    // if k = 0 then first player cannot play a move and loses
    dp[0] = 0;

    for (int i = 1; i <= k; i++) {
        // initialize dp[i] as losing state
        dp[i] = 0;
        for (int x: a) {
            if(i >= x && dp[i - x] == 0) {
                dp[i] = 1;
                break;
            }
        }
    }

    if (dp[k] == 1) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}

signed main() {
    IOS
    int t = 1;
    PRECISION(10)
    // cin >> t;
    f(i, t) {
        solve();
    }
}
