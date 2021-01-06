 
#include <iostream>
using namespace std;

long long a[200001];
long long ans=0;
void Merge(long long ei,long long ef,long long di,long long df){
    long long pos=0,pp=ei,temp[df-ei+3];
    while(ei<=ef&&di<=df){
        if(a[ei]<=a[di]){
            temp[pos++]=a[ei++];
		}else{
            ans=ans+(ef-ei+1);
            temp[pos++]=a[di++];
        }
    }
    while(ei<=ef){
	 temp[pos++]=a[ei++];
	}
    while(di<=df){
		temp[pos++]=a[di++];
	}
    for(int i=0;i<pos;i++){
        a[pp+i]=temp[i];
	}
    return;
}
 
void MergeSort(long long e,long long d){
    long long mid=(e+d)>>1;
    if(e<d)    {
        MergeSort(e,mid);
        MergeSort(mid+1,d);
        Merge(e,mid,mid+1,d);
    }
}
 
int main(){
    long long n,m,d,teste,t=0;
    cin >> teste;
    for(int k = 0; k < teste; k++){
        ans=0;
        cin >> n;
        for(int i=0;i<n;i++){
           cin >> a[i];
		}
        MergeSort(0,n-1);
        cout << ans << endl;
    }

    
    return 0;
}