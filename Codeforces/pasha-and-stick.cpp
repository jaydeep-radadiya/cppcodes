#include<bits/stdc++.h>
using namespace std;
 
void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
 
int main(){
	fastIO();
 
	int n;
	cin>>n;
	if(n%2!=0)
		cout<<0<<"\n";
	else{
		n = n/2;
		int ans = n-1;
		cout<<ans/2<<"\n";
	}
 
	return 0;
}