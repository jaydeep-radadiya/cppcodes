#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll n = 90000000;
	vector<bool> prime(n+1,true);
	prime[0] = prime[1] = false;

	for(int i=2;i<=sqrt(n);i++){
		if(prime[i]==true){
			for(int j=i*i;j<=n;j=j+i){
				prime[j] = false;
			}
		}
	}

	vector<int> ans;
	for(int i=0;i<=n;i++){
		if(prime[i]==true){
			ans.push_back(i);
		}
	}

	int x;
	cin>>x;
	while(x--){
		int val;
		cin>>val;
		cout<<ans[val-1]<<"\n";
	}

	return 0;
}