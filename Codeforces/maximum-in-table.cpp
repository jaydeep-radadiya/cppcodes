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
#define PI 3.141592653589793

int solve(int n){
	vector<vector<int>> arr(n,vector<int> (n,1));

	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			arr[i][j] = arr[i-1][j]+arr[i][j-1];
		}
	}
	return arr[n-1][n-1];
}

int main(){
	fastIO();

	int n;
	cin>>n;
	cout<<solve(n);

	return 0;
}