#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int n1 = s1.size();
	int n2 = s2.size();

	vector<vector<int>> dp(n1+1, vector<int> (n2+1,0));

	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	// length of lcs : dp[n1][n2]
	string ans = "";
	int i = n1;
	int j = n2;

	while(i>0 and j>0){
		if(s1[i-1]==s2[j-1]){
			ans.push_back(s1[i-1]);
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			// go up directions
			i--;
		}
		else{
			// go left directions
			j--;
		}
	}

	reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;
}