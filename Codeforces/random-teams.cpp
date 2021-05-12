#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main(){
	fastIO();

	ll n,m;
	cin>>n>>m;
	if(m==1){
		ll ans = n*(n-1)/2;
		cout<<ans<<" "<<ans<<"\n";
	}
	else{
		ll mx = (n-m+1)*(n-m)/2;
		ll each = n/m; // person in every group
		ll rem = n%m; // groups have extra person
		// extra person group pair
		ll epgp = rem*(((each+1)*each)/2);
		// simple person group pair
		ll spgp = (m-rem)*(each*(each-1)/2);
		ll mn = epgp+spgp;
		cout<<mn<<" "<<mx<<"\n";
	}

	return 0;
}