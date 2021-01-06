#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <vector>
using namespace std;
 typedef struct Letra {
 	string l1, l2, l3;
 }Letra;

int main(){
	Letra l[10];
	l[1].l1 = "*.";
	l[2].l1 = "*.";
	l[3].l1 = "**";
	l[4].l1 = "**";
	l[5].l1 = "*.";
	l[6].l1 = "**";
	l[7].l1 = "**";
	l[8].l1 = "*.";
	l[9].l1 = ".*";
	l[0].l1 = ".*";

	l[1].l2 = "..";
	l[2].l2 = "*.";
	l[3].l2 = "..";
	l[4].l2 = ".*";
	l[5].l2 = ".*";
	l[6].l2 = "*.";
	l[7].l2 = "**";
	l[8].l2 = "**";
	l[9].l2 = "*.";
	l[0].l2 = "**";

	l[1].l3 = "..";
	l[2].l3 = "..";
	l[3].l3 = "..";
	l[4].l3 = "..";
	l[5].l3 = "..";
	l[6].l3 = "..";
	l[7].l3 = "..";
	l[8].l3 = "..";
	l[9].l3 = "..";
	l[0].l3 = "..";
	string ent, op;
	int n;
	while(true){
		cin >> n;
		if(n == 0){
			break;
		}
		cin >> op;
		char g[1];
		if(op == "S"){
			cin >> ent;
			for(int i = 0; i < ent.size(); i++){
				g[0] = ent[i]; 
				cout << l[atoi(g)].l1;
				if(i != ent.size()-1){
					cout << " ";
				}
			}
			cout << endl;
			for(int i = 0; i < ent.size(); i++){
				g[0] = ent[i]; 
				cout << l[atoi(g)].l2;
				if(i != ent.size()-1){
					cout << " ";
				}				
			}
			cout << endl;
			for(int i = 0; i < ent.size(); i++){
				g[0] = ent[i]; 
				cout << l[atoi(g)].l3;
				if(i != ent.size()-1){
					cout << " ";
				}				
			}
			cout << endl;
		}else{
			Letra ls[101];
			for(int i = 0; i < n; i++){
				cin >> ls[i].l1;
			}
			for(int i = 0; i < n; i++){
				cin >> ls[i].l2;
			}
			for(int i = 0; i < n; i++){
				cin >> ls[i].l3;
			}
			for(int i = 0; i < n; i++){
				for(int j = 0; j < 10; j++){
					if(ls[i].l1 == l[j].l1 && ls[i].l2 == l[j].l2){
						cout << j;
						break;
					}
				}
			}
			cout << endl;
		}

	}
	return 0;
}