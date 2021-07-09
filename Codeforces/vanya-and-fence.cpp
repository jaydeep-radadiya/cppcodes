#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,w;
	cin>>n>>w;

	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int cnt = 0;
	for(int i=0;i<n;i++){
		if(arr[i]>w)
			cnt = cnt+2;
		else
			cnt = cnt+1;
	}

	cout<<cnt<<"\n";
	return 0;
}