#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;

int main(){
	ll n,w;
	cin>>n>>w;
	vector<ll> wt(n);
	vector<ll> val(n);
	for(int i=0;i<n;i++)
		cin>>wt[i]>>val[i];

	ll dp1[n*1000+1];
	ll dp2[n*1000+1];
	for(int i=0;i<n*1000+1;i++){
		dp1[i] = inf;
		dp2[i] = inf;
	}

	// base case
	dp1[0] = 0;
	dp1[val[0]] = wt[0];

	for(int i=1;i<n;i++){
		for(int j=0;j<n*1000+1;j++){
			if(val[i]>j){
				dp2[j] = dp1[j];
			}
			else{
				dp2[j] = min({dp1[j],dp2[j],wt[i]+dp1[j-val[i]]});
			}
		}
		for(int k=0;k<n*1000+1;k++){
			dp1[k] = dp2[k];
			dp2[k] = inf;
		}
	}

	ll res = 0;
	for(ll i=0;i<n*1000+1;i++){
		if(dp1[i]<=w){
			res = max(res,i);
		}
	}

	cout<<res;
	return 0;
}