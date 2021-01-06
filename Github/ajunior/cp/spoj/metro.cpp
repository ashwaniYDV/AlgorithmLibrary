#include <iostream>

using namespace std;

int busca (int ch){
	int m, i=1, f = 100, c=0;
	while(i<=f){
		c++;
		m = (f+i)/2;
		if (m == ch) {
			return c; 
		} else if (ch < m){
			f = m-1;
		} else {
			i = m+1;
		} 
	} return c;
}
int main (){
		int n;
		while(1){
		cin>>n;
		if(n == 0) break;
		cout << busca(n) <<endl;
		}
	return 0;
}