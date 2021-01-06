#include <iostream>
using namespace std;
int main(){
	long long n, res = 1;
	cin >> n;
	while(true){
		n = n/2;
		res = res*4;
		if(n<2)break;	
	}
	cout << res <<endl;
	
	
	return 0;
}