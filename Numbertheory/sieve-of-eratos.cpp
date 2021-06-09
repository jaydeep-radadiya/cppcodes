#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<bool> prime(n+1,true);
	prime[0] = prime[1] = false;

	// sc : O(n)
	// ts : O(nlog(logn))
	for(int i=2;i<=sqrt(n);i++){
		if(prime[i]==true){
			for(int j=i*i;j<=n;j=j+i){
				prime[j] = false;
			}
		}
	}

	for(int i=0;i<=n;i++){
		if(prime[i]==true)
			cout<<i<<" ";
	}

	return 0;
}