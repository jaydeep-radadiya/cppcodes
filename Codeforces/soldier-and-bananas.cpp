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

	int k,n,w;
	cin>>k>>n>>w;
	int i = w*(w+1)/2;
	int bill = k*i;

	if(n>=bill)
		cout<<0<<"\n";
	else
		cout<<bill-n<<"\n";

	return 0;
}