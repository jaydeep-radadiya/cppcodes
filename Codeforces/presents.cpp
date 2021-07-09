#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n+1);
	for(int i=1;i<arr.size();i++){
		cin>>arr[i];
	}

	vector<int> ans(n+1);
	for(int i=1;i<arr.size();i++){
		ans[arr[i]] = i;
	}

	for(int i=1;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}

	return 0;
}