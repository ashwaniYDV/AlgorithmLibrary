#include <iostream>
using namespace std;
int main(){
	int res = 0, n;
	
	cin >> n;

	for(int i = 0; i < 2; i++){
		res=n*2;
		n = res;
	}
	cout <<res << endl;
	
	return 0;
}