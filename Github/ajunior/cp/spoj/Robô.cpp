#include <iostream>
using namespace std;
int main()
{
	int t1,t2,s1,s2;
	cin>>t1>>t2>>s1>>s2;
	int matriz[500][500];
	for(int i=1;i<=t1;i++){
		for (int l=1;l<=t2;l++){
			cin>>matriz[i][l];
		}
	}
	for(int i=1;i<=t1;i++){
		for (int l=1;l<=t2;l++){
			if((i!=s1||l!=s2) && matriz[i][l]==1){
				cout<<i <<" "<<l;
				i=t1+1;
			}
		}
	}
    return 0;       
}