#include<bits/stdc++.h>
using namespace std;

int n = 1000007;
vector<bool> prime(n+1,true);
vector<int> cpn(n+1,0);
vector<int> cppn(n+1,0);

void sieve(){
	prime[0] = prime[1] = false;
	for(int i=2;i<=sqrt(n);i++){
		if(prime[i]==true){
			for(int j=i*i;j<=n;j=j+i){
				prime[j] = false;
			}
		}
	}

	// cnt the prime number till i
	for(int i=1;i<=n;i++){
		cpn[i] = cpn[i-1]+(prime[i]==true);
	}

	// cnt the prime prime number till i
	for(int i=1;i<=n;i++){
		if(prime[cpn[i]]==true)
			cppn[i] = cppn[i-1]+1;
		else
			cppn[i] = cppn[i-1];
	}
}

int  main(){
	sieve();
	int t;
	cin>>t;

	while(t--){
		int l,r;
		cin>>l>>r;

		cout<<cppn[r]-cppn[l-1]<<"\n";
	}

	return 0;
}