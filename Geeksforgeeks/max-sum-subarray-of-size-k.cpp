#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr,int n,int k){
	int mx = INT_MIN;
	int sum = 0;
	int i=0,j=0;

	while(j<n){
		sum = sum+arr[j];
		if(j-i+1<k){
			j++;
		}
		else if(j-i+1==k){
			mx = max(mx,sum);
			sum = sum-arr[i];
			i++;
			j++;
		}
	}
	return mx;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int ans = solve(arr,n,k);
	cout<<ans<<"\n";

	return 0;
}