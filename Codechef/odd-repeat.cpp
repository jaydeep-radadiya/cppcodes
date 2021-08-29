#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int t;
	cin>>t;
	
	while(t--){
		ll n,k,sum;
		cin>>n>>k>>sum;
		cout<<(sum-n*n)/(k-1)<<"\n";
	}
	
	return 0;
}