// https://youtu.be/bgXpltW2yAQ

int32_t main() {
	char ar[] = {'A', 'B', 'C', 'D'};
	ll n=4;
	ll total=1<<n;
	for(ll mask=0; mask<total; mask++){
		cout<<"{ ";
		f(i,n){
			ll f=1 << i;
			if(mask & f){
				cout<<ar[i]<<" ";
			}
		}
		cout<<"}";
		cout<<endl;
	}
}
