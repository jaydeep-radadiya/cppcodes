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
	int cnt = 0;

	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b+c>=2)
			cnt++;
	}

	cout<<cnt<<"\n";
	return 0;
}