#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)

int main(){
	fastIO();

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<vector<int>> arr(n,vector<int> (n,0));

		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				cin>>arr[i][j];
			}
		}

		// print the triangle
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<=i;j++){
		// 		cout<<arr[i][j]<<" ";
		// 	}
		// 	cout<<"\n";
		// }

		for(int i=n-1;i>=1;i--){
			for(int j=i-1;j>=0;j--){
				arr[i-1][j] += max(arr[i][j],arr[i][j+1]);
			}
		}
		cout<<arr[0][0]<<"\n";
	}

	return 0;
}