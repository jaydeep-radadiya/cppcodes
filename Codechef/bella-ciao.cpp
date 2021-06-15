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
		ll D,d,p,q;
		cin>>D>>d>>p>>q;

		ll n = D/d; // quotient
		ll rem = D%d;
		ll part_one = (n*(2*p+(n-1)*q)/2)*d;
		ll part_two = (p+n*q)*rem;
		cout<<part_one+part_two<<"\n";
	}

	return 0;
}