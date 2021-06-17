#include<bits/stdc++.h>
using namespace std;

// work for positive array
int solve(vector<int> arr,int n,int k){
	int mx = 0,sum = 0;
	int i = 0,j = 0;

	while(j<n){
		sum = sum+arr[j];
		if(sum<k)
			j++;
		else if(sum==k){
			mx = max(mx,j-i+1);
			j++;
		}
		else if(sum>k){
			while(sum>k){
				sum = sum-arr[i];
				i++;
			}
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