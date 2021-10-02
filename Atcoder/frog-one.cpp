#include<bits/stdc++.h>
using namespace std;
#define inf 1e18

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	vector<int> dp(n,inf);
	dp[0] = 0;

	if(n==1){
		cout<<dp[0]<<"\n";
		return 0;
	}

	dp[1] = abs(arr[1]-arr[0]);
	for(int i=2;i<n;i++){
		dp[i] = min(abs(arr[i]-arr[i-1])+dp[i-1],abs(arr[i]-arr[i-2])+dp[i-2]);
	}

	cout<<dp[n-1]<<"\n";
	return 0;
}