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
#define PI 3.141592653589793

bool filterVals(vector<ll> &arr,ll val,ll i){
	ll j = 0;
	ll sum = 0;
	while(i>0){
		if(i&1)
			sum += arr[j];
		else
			sum += 0;
		i = i>>1;
		j++;
	}
	if(sum==val)
		return true;
	else
		return false;
}

bool generateSubsets(vector<ll> &arr,ll val){
	ll n = arr.size();
	ll range = 1<<n;
	for(ll i=0;i<range;i++){
		bool ans = filterVals(arr,val,i);
		if(ans==true) return true;
	}
	return false;
}

int main(){
	fastIO();

	ll t;
	cin>>t;
	while(t--){
		ll n,val;
		cin>>n>>val;
		vector<ll> arr(n);
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		bool ans = generateSubsets(arr,val);
		if(ans==true)
			cout<<"Yes"<<"\n";
		else
			cout<<"No"<<"\n";
	}
	return 0;
}