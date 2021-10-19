#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll n,q;
	cin>>n>>q;
	vector<ll> arr(n);
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	vector<ll> idx(n,0);
	while(q--){
		ll l,r;
		cin>>l>>r;
		l--;r--;
		idx[l]++;
		if(r+1<n)
			idx[r+1]--;
	}
	for(ll i=1;i<n;i++)
		idx[i] = idx[i]+idx[i-1];

	sort(arr.begin(),arr.end());
	sort(idx.begin(),idx.end());

	ll ans = 0;
	for(ll i=0;i<n;i++)
		ans += arr[i]*idx[i];
	cout<<ans<<"\n";

	return 0;
}