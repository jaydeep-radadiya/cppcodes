#include<bits/stdc++.h>
using namespace std;
int dp[100005];
vector<int> graph[100005];

int findLongestPath(int src){
	if(dp[src]!=-1) return dp[src];

	int result = INT_MIN;
	int is_leaf = 1;
	for(int neighbour : graph[src]){
		is_leaf = 0;
		result = max(result,findLongestPath(neighbour));
	}
	return dp[src] = is_leaf ? 0 : result+1;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n,e;
	cin>>n>>e;

	while(e--){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}

	int result = INT_MIN;
	// for all component
	for(int i=1;i<=n;i++){
		result = max(result,findLongestPath(i));
	}

	cout<<result;
	return 0;
}