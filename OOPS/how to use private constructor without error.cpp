#include<bits/stdc++.h>
using namespace std;

class ash {
private:
	ash(){}
	
public:
	ash* fun() {
		ash* temp_instance = new ash;
		return temp_instance;
	}

	int id = 5;
	
};
 
void solve() {
   ash* as;
   as = as->fun();
   cout << as->id << endl;
}

signed main() {
    IOS
    int T = 1;
    // cin >> T;
    while (T--)
    	solve();
    return 0;
}
