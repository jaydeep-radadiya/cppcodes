#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)

ll findpow(ll base,ll power){
	if(power==0)
		return 1;
	ll temp = findpow(2,power/2);
	if(power%2==0)
		return (temp*temp)%mod;
	else
		return (temp*base*temp)%mod;
}

int main(){
	fastIO();

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll ans = findpow(2,n-1);
		cout<<ans<<"\n";
	}

	return 0;
}