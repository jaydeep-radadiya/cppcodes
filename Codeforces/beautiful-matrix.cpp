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

	int r = 5,c = 5;
	vector<vector<int>> arr(r, vector<int>(c,0));

	// take input
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]==1){
				cout<<abs(2-i)+abs(2-j)<<"\n";
				break;
			}
		}
	}

	return 0;
}