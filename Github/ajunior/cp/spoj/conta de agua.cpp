#include <iostream>

using namespace std; 

int main(){

	int n, res = 7;
	cin >> n;
	if(n > 100){
		res += (n-100)*5;
		n = 100;
	}
	if(n > 30){
		res += (n-30)*2;
		n = 30;
	}
	if(n > 10){
		res += n-10;
	}
	cout << res << endl;
	
	
	return 0;
}