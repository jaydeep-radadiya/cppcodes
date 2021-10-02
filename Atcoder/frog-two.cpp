#include<bits/stdc++.h>
using namespace std;
#define inf 1e18

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	vector<int> dp(n,inf);

	dp[0] = 0;
	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			if(i-j<0) break;
			dp[i] = min(dp[i],abs(arr[i]-arr[i-j])+dp[i-j]);
		}
	}

	cout<<dp[n-1]<<"\n";
	return 0;
}