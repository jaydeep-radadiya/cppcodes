#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n,w;
	cin>>n>>w;
	vector<ll> wt(n);
	vector<ll> val(n);
	for(int i=0;i<n;i++)
		cin>>wt[i]>>val[i];

	vector<ll> dp1(w+1,0);
	vector<ll> dp2(w+1,0);

	for(int i=0;i<n;i++){
		for(int j=1;j<=w;j++){
			if(wt[i]>j){
				dp2[j] = dp1[j];
			}
			else{
				dp2[j] = max({dp1[j],dp2[j],val[i]+dp1[j-wt[i]]});
			}
		}
		dp2.swap(dp1);
		dp2.clear();
	}

	cout<<dp1[w]<<"\n";
	return 0;
}