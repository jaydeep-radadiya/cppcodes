#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	while(true){
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];

		sort(arr.begin(),arr.end());
		int cnt = 0;

		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				auto ub = upper_bound(arr.begin(),arr.end(),arr[i]+arr[j]);
				cnt += arr.end()-ub;
			}
		}

		cout<<cnt<<"\n";
		cin>>n;
		if(n==0) break;
	}

	return 0;
}