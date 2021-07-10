// every elemnts occurs twice in the array excepttwo numbers which occurs once
// https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/



ll find2UniqueNums(ll a[], ll n) {
	ll res = 0;
	f(i, n){
		res = res ^ a[i];
	}
	// find the rightmost set bit position
	ll temp = res;
	ll pos = 0;
	while(temp) {
		if(temp & 1){
			break;
		}
		pos++;
		temp = temp >> 1;
	}
	ll mask = 1 << pos;
	ll firstNum = 0, secondNum = 0;
	f(i, n){
		if(mask & a[i]){
			firstNum = firstNum ^ a[i];
		}
	}
	secondNum = res ^ firstNum;
	if(firstNum > secondNum) swap(firstNum, secondNum);
	cout << firstNum << " " << secondNum << endl;
}

void solve() {
    cin >> n;
    ll a[n];
    f(i, n) cin >> a[i];
    find2UniqueNums(a, n);
}

int32_t main() {
	IOS
	solve();
	cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
	return 0;
}
