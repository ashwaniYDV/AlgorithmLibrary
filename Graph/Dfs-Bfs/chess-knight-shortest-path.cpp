// https://www.techiedelight.com/chess-knight-problem-find-shortest-path-source-destination/

#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
#define ll long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>n;a<n?i+=1:i-=1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;

const ll mod = 1000000007;
const ll N = 1e6+5, M = N, ninf = -2e5, inf = (int)1e9;
vl g[N], dist;
ll a[N], b[N], dp[N], in[N], out[N], vis[N], level[N];
ll n, m;


ll row[]={2,2,-2,-2,1,1,-1,-1};
ll col[]={-1,1,1,-1,2,-2,2,-2};

bool valid(ll x, ll y){
	if(x<0||y<0||x>=8||y>=8) return false;
	return true;
}

struct Node {
    ll x, y, dist;
    Node(ll x, ll y, ll dist=0): x(x), y(y), dist(dist) {}
    bool operator<(const Node& ob) const{
    	return x<ob.x || (x==ob.x && y<ob.y); 
    }
};

ll bfs(Node src, Node dest){
	map<Node, ll> visited;
	queue<Node>q;
	q.push(src);
	while(!q.empty()){
		Node node = q.front();
		q.pop();
		ll x=node.x;
		ll y=node.y;
		ll dist=node.dist;

		if(x==dest.x && y==dest.y){
			return dist;
		}

		if(!visited[node]){
			visited[node]=1;
			f(i,8){
				ll x1=x+row[i];
				ll y1=y+col[i];
				if(valid(x1, y1)){
					q.push({x1, y1, dist+1});
				}
			}
		}
	}
	return -1;
}


int32_t main()
{
	IOS
	ll t,k,x,y,z,p,q,u,v,ct=0,flag=0;
	Node src={0,7};
	Node dest={7,0};
	cout<<bfs(src, dest);
}
