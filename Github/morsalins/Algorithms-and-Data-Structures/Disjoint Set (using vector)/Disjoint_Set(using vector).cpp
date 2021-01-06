#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

#define MAX 1000

void makeSet(int);
int findParent(int);
void Union(int, int);

vector <int> parents;

int main()
{
	int nodes, edges;

	cout << "How many nodes: ";
	cin >> nodes;

	makeSet(nodes); // making each elements are parents of themselves. 

	cout << "How many edges: ";
	cin >> edges;

	cout << "Enter the edges (u & v): \n" ;
	for(int i=1; i<=edges; i++){
		
		int u, v;
		cout << "Edge " << i << ": ";
		cin >> u >> v;
		
		Union(u, v);	
	}

	getchar();
	return 0;
}

void makeSet(int nodes){

	for(int i=0; i<=nodes; i++){
		parents.push_back(i);
	}

	return;
}

int findParent( int r ){

	if( r == parents[r] ) return r;

	return parents[r] = findParent( parents[r] );
}

void Union (int a, int b){

	int parent_of_a = findParent(a);
	int parent_of_b = findParent(b);

	if( parent_of_a != parent_of_b ) 
		parents[parent_of_a] = parent_of_b; // or parents[parent_of_b] = parent_of_a is acceptable

	return;
}
