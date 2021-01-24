#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
#define ll long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>=n;a<n?i+=1:i-=1)
#define rep(i,a, n) for(i = a; i < n; i++)
#define ren(i,a, n) for(i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define setmem(x, k) memset(x, k, sizeof(x))
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
// const ll N = 1e6+5, M = N, ninf = -2e5, inf = (int)1e9;
// vl g[N], dist;
// ll a[N], b[N], dp[N], in[N], out[N], vis[N], level[N];
// const ll N=1005;
// ll n, m;

struct Node{
	ll data;
	Node* next;
};

Node* head;

void Insert(ll data){
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
		return;
	}
	Node* temp1 = head;
	while(temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp1->next = temp;
}

void Insert_front(ll data){
	Node* temp = new Node();
	temp->data = data;
	temp->next = head;
	head = temp;
}

void Insert_at_pos(ll data, ll n){
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(n==1){
		temp->next = head;
		head = temp;
		return;
	}
	Node *temp2 = head;
	for(ll i=1; i<=n-2; i++){
		temp2 = temp2->next; // after loop temp2 point to (n-1)th node
	}
	temp->next = temp2->next; // temp2->next point to (n)th node
	temp2->next = temp;
}

void Reverse(){
	Node *current, *prev, *next;
	current = head;
	prev = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void Delete(ll n){
	Node *temp1 = head;
	if(n==1){
		head = temp1->next; // (2)nd node
		delete temp1;
		return;
	}
	for(ll i=1; i<=n-2; i++){
		temp1 = temp1->next; // after loop temp1 point to (n-1)th node
	}
	Node *temp2 = temp1->next; // (n)th node
	temp1->next = temp2->next; // (n+1)th node
	delete temp2;
}

void Print(){
	Node* ptr = head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

 
int32_t main(){
	IOS
	head = NULL;
	Insert(1);
	Insert(2);
	Insert(3);
	Insert(4);
	Insert(5);
	Print();
	Reverse();
	Print();
	Insert(6);
	Insert(7);
	Print();
	Insert_front(8);
	Insert_front(9);
	Print();
	Insert_at_pos(10, 3);
	Print();
	Insert_at_pos(11, 5);
	Print();
	Delete(3); // delete node at 3rd position
	Print();
}
