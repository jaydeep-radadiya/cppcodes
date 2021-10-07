#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n;
		cin>>n;
		ll i = 5;
		ll cnt = 0;
		while(n/i>0){
			cnt += n/i;
			i = i*5;
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}