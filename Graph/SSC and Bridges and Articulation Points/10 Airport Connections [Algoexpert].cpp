// https://youtu.be/qz9tKlF431k
// Google Coding Interview of Willian Lin by Clement

/*
Algo Expert Extremely Hard 2
Airport Connections - Extremely Hard 2

You are given a list of airports (three-letter codes like 'JFK'), a list of routes 
(one-way flights from one airport to another like ['JFK', 'SFO']), and a starting airport.
Write a function that returns the minimum number of airport connections (one-way flights) that need to be added 
in order for someone to be able to reach any airport in the list, starting at the starting airport.


Sample Input:

airports = [
"BGI",
"CDG",
"DEL",
"DOH",
"DSM",
"EWR",
"EYW",
"HDN",
"ICN",
"JFK",
"LGA",
"LHR",
"ORD",
"SAN",
"SFO",
"SIN",
"TLV",
"BUD"
]

routes = [
["DSM","ORD"],
["ORD","BGI"],
["BGI","LGA"],
["SIN","CDG"],
["CDG","SIN"],
["CDG","BUD"],
["DEL","DOH"],
["DEL","CDG"],
["TLV","DEL"],
["EWR","HND"],
["HND","ICN"],
["HND","JFK"],
["ICN","JFK"],
["JFK","LGA"],
["EYW","LHR"],
["LHR","SFO"],
["SFO","SAN"],
["SFO", "DSM"],
["SAN","EYW"]
]

startingAirport = "LGA"


Sample output:
3
*/






/*
Steps:
1) process the input and build the directed graph
2) find the SCCs
3) compress the graph based on SCCs (we assign any one node of each SCC to represent the SCC)
4) find the no of nodes in condensed graph which has indegree = 0 and is not the startingNode 
   (this is our result, since we have to add these many edges from startingNode to these nodes [or any other node with indegree > 0 to these nodes ])
*/




const int N = 2e5+5;
int n, m;

vector<int> g[N], revG[N], compressedG[N];
int vis[N], sccParent[N], indegree[N];
stack<int> st;

void dfs(int u) {
    vis[u] = 1;
    for(int v: g[u]) {
        if(!vis[v]) dfs(v);
    }
    st.push(u);
}

void revDfs(int u, int sccPar) {
    vis[u] = 1;
    sccParent[u] = sccPar;
    for(int v: revG[u]) {
        if(!vis[v]) revDfs(v, sccPar);
    }
}

void solve() {
    /*******************Input starts***********************/
    vector<string> airports = {
                            "BGI",
                            "CDG",
                            "DEL",
                            "DOH",
                            "DSM",
                            "EWR",
                            "EYW",
                            "HDN",
                            "ICN",
                            "JFK",
                            "LGA",
                            "LHR",
                            "ORD",
                            "SAN",
                            "SFO",
                            "SIN",
                            "TLV",
                            "BUD"};

    vector<vector<string>> routes = {
                            {"DSM","ORD"},
                            {"ORD","BGI"},
                            {"BGI","LGA"},
                            {"SIN","CDG"},
                            {"CDG","SIN"},
                            {"CDG","BUD"},
                            {"DEL","DOH"},
                            {"DEL","CDG"},
                            {"TLV","DEL"},
                            {"EWR","HND"},
                            {"HND","ICN"},
                            {"HND","JFK"},
                            {"ICN","JFK"},
                            {"JFK","LGA"},
                            {"EYW","LHR"},
                            {"LHR","SFO"},
                            {"SFO","SAN"},
                            {"SFO", "DSM"},
                            {"SAN","EYW"}};

    string startingAirport = "LGA";
    /*******************Input ends************************/
    
    n = airports.size();

    map<string, int> strToInt;
    for(int i = 0; i < n; i++) {
        strToInt[airports[i]] = i+1;
    }

    int startingNode = strToInt[startingAirport];

    for(auto it: routes) {
        int u = strToInt[it[0]], v = strToInt[it[1]];
        g[u].pb(v);
        revG[u].pb(v);
    }

    // to store nodes in decreasing order of out time in stack
    loop(i, 1, n) {
        if(!vis[i]) dfs(i);
    }

    loop(i, 0, n) vis[i] = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            revDfs(node, node);
        }
    }


    // compressed graph of sccParent nodes only
    for(auto it: routes) {
        int u = strToInt[it[0]], v = strToInt[it[1]];
        u = sccParent[u];
        v = sccParent[v];
        // u != v means it is a edge between two different SCC
        if(u != v) {
            compressedG[u].pb(v);
            indegree[v]++;
        }
    }

    int res = 0;
    loop(i, 1, n) {
        if(sccParent[i] == i && indegree[i] == 0 && i != sccParent[startingNode]) {
            res++;
        }
    }

    cout << res << endl;
}
