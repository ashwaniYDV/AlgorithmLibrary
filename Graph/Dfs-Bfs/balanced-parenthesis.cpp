// write all possible answers to balance the string with minimum number of characters removed
// https://youtu.be/EE_9U798nvQ

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>n;a<n?i+=1:i-=1)
#define pb push_back
#define F first
#define S second
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



class Solution{
	bool isBalanced(string s){
		ll ct=0;
		for(char x: s){
			if(x=='(') ct++;
			else if(x==')') ct--;
			if(ct<0) return 0;
		}
		return ct==0;
	}
	public: 
		map<string, bool> visited;
		vector<string> removeInvalidParenthesis(string s){
			queue<string> Q;
			vector<string> ans;
			Q.push(s);
			ll found=0;
			while(!Q.empty()){
				string u=Q.front(); Q.pop();
				if(visited[u]) continue;
				visited[u]=1;
				if(isBalanced(u)) found=1, ans.pb(u);
				if(found) continue;
				f(i,u.size()){
					if(u[i]=='(' || u[i]==')'){
						string v=u.substr(0,i)+u.substr(i+1,u.size());
						Q.push(v);
					}
				}
			}
			return ans;
		}
};

 
int main()
{
	ios
	
	Solution s;
	vector<string> result = s.removeInvalidParenthesis("(a()*(()()b)");
	for(string cur: result) cout<<cur<<endl;

}
