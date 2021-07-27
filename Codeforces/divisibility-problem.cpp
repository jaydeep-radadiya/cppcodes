#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int a,b;
		cin>>a>>b;
		int rem = a%b;
		if(rem==0)
			cout<<0<<"\n";
		else
			cout<<b-rem<<"\n";
	}

	return 0;
}