#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int x,y,z;
		cin>>x>>y>>z;
		int ans = min({x,y,z});
		if(ans==x)
			cout<<"Draw"<<"\n";
		else if(ans==y)
			cout<<"Bob"<<"\n";
		else
			cout<<"Alice"<<"\n";
	}
	
	return 0;
}