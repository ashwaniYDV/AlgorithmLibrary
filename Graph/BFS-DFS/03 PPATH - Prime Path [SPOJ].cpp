// https://www.spoj.com/problems/PPATH/

/*
The ministers of the cabinet were quite upset by the message from the Chief of Security stating that 
they would all have to change the four-digit room numbers on their offices.
— It is a matter of security to change such things every now and then, to keep the enemy in the dark.
— But look, I have chosen my number 1033 for good reasons. I am the Prime minister, you know!
— I know, so therefore your new number 8179 is also a prime. You will just have to paste four new digits over the four old ones on your office door.
— No, it's not that simple. Suppose that I change the first digit to an 8, then the number will read 8033 which is not a prime!
— I see, being the prime minister you cannot stand having a non-prime number on your door even for a few seconds.
— Correct! So I must invent a scheme for going from 1033 to 8179 by a path of prime numbers where only one digit is changed from one prime to the next prime.

Now, the minister of finance, who had been eavesdropping, intervened.
— No unnecessary expenditure, please! I happen to know that the price of a digit is one pound.
— Hmm, in that case I need a computer program to minimize the cost. You don't know some very cheap software gurus, do you?
— In fact, I do. You see, there is this programming contest going on...

Help the prime minister to find the cheapest prime path between any two given four-digit primes! The first digit must be nonzero, of course. 
Here is a solution in the case above.

    1033
    1733     
    3733     
    3739     
    3779
    8779
    8179     
*/

const int N = 1e5+5;
int n, m;

vector<int> g[N];
vector<int> primes;
int dist[N];

bool check(int i, int j) {
    int cnt = 0;
    while(i) {
        if((i % 10) != (j % 10)) cnt++;
        i /= 10;
        j /= 10;
    }
    return cnt == 1;
}

bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void buildGraph() {
    for(int i = 1000; i <= 9999; i++) {
        if (isPrime(i)) primes.pb(i);
    }

    for(int i = 0; i < primes.size(); i++) {
        for(int j = i + 1; j < primes.size(); j++) {
            int u = primes[i], v = primes[j];
            if (check(u, v)) {
                g[u].pb(v);
                g[v].pb(u);
            }
        }           
    }
}

void bfs(int src, int dest) {
    for(int i = 1000; i <= 9999; i++) {
        dist[i] = INF;
    }
    
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v: g[u]) {
            if(dist[v] != INF) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    if(dist[dest] == INF)
        cout << "IMPOSSIBLE\n";
    else
        cout << dist[dest] << endl;

}

void solve() {
    buildGraph();

    int t, u, v;
    cin >> t;
    while(t--) {
        cin >> u >> v;
        bfs(u, v);
    }
}
