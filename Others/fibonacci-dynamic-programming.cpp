#include<bits/stdc++.h>
using namespace std;

// recursive
// int fib(int n){
// 	if(n==0 or n==1) return n;
// 	return fib(n-1) + fib(n-2);
// }

int dp[1001];
int fib(int n){
	if(n==0 or n==1) return n;
	if(dp[n]!=-1) return dp[n];
	return dp[n] = fib(n-1) + fib(n-2);
}

// top down with vector
int fibTD(int n,vector<int> &memo){
	if(n==0 or n==1) return n;
	if(memo[n]!=-1) return memo[n];
	return memo[n] = fibTD(n-1,memo) + fibTD(n-2,memo);
}

// bottom up approach
int fibBU(int n){
	vector<int> dp(n+1,0);
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main(){
	// memset(dp,-1,sizeof(dp));
	// cout<<fib(5);

	// vector<int> memo(1001,-1);
	// cout<<fibTD(10,memo);

	cout<<fibBU(5);

	return 0;
}