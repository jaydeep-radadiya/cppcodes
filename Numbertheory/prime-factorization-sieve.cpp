#include<bits/stdc++.h>
using namespace std;

int n = 1000007;
vector<int> arr(n+1,-1);
// tc : O(log(n)) sc : O(n)

void sieve(){
	for(int i=2;i<=n;i++){
		if(arr[i]==-1){
			for(int j=i;j<=n;j=j+i){
				if(arr[j]==-1){
					arr[j] = i;
				}
			}
		}
	}
}

vector<int> getFactor(int x){
	vector<int> ans;
	while(x!=1){
		ans.push_back(arr[x]);
		x = x/arr[x];
	}
	return ans;
}

int main(){
	sieve();
	int x = 48;
	vector<int> ans = getFactor(48);

	for(int ele : ans)
		cout<<ele<<" ";

	return 0;
}