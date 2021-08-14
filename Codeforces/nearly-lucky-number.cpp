#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll n;
	cin>>n;

	ll cnt = 0;
	while(n>0){ // cnt lucky digits
		if(n%10==4 || n%10==7){
			cnt++;
		}
		n = n/10;
	}

	if(cnt==4 || cnt==7)
		cout<<"YES"<<"\n";
	else
		cout<<"NO"<<"\n";

	return 0;
}