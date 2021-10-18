#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll minCost(vector<ll> &height,vector<ll> &cost,ll n,ll ht){
	ll ans = 0;

	for(ll i=0;i<n;i++){
		ans += abs(ht-height[i])*cost[i];
	}
	return ans;
}

ll solve(vector<ll> &height,vector<ll> &cost,ll n){
	ll left = 0;
	ll right = 10000;

	while(left<right){
		ll mid1  = left+(right-left)/3;
		ll mid2 = right-(right-left)/3;
		ll val1 = minCost(height,cost,n,mid1);
		ll val2 = minCost(height,cost,n,mid2);

		if(val1>val2)
			left = mid1+1;
		else if(val2>val1)
			right = mid2-1;
		else{
			left = mid1+1;
			right = mid2-1;
		}
	}
	return minCost(height,cost,n,left);
}

int main(){
	ll t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;
		vector<ll> height(n);
		for(ll i=0;i<n;i++)
			cin>>height[i];
		vector<ll> cost(n);
		for(ll i=0;i<n;i++)
			cin>>cost[i];
		cout<<solve(height,cost,n)<<"\n";
	}

	return 0;
}