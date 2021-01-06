#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, t,  res = 0;
	
	cin >> n;
	
	
	for(int i = 0; i < n; i++)	{
		cin >> t;
		res+=t;
	}
	   	cout << res/n << endl;    
     
	return 0;
}