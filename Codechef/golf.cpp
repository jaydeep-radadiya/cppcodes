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

int main(){
	fastIO();

	ll t;
	cin>>t;
	while(t--){
		ll n,x,k;
		cin>>n>>x>>k;

		if(x%k==0 or (n+1-x)%k==0)
			cout<<"Yes"<<"\n";
		else
			cout<<"No"<<"\n";
	}

	return 0;
}