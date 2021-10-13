#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n,a,b;
		cin>>n>>a>>b;
		
		int odd = 0;
		int even = 0;
		
		while(n%2==0){
			n = n/2;
			even++;
		}
		
		for(int i=3;i<=sqrt(n);i+=2){
			if(n%i==0){
				while(n%i==0){
					n = n/i;
					odd++;
				}
			}
		}
		
		// if n is prime like 17
		if(n>1){
			odd++;
		}
		
		int ans = 0;
		if(a>=0 and b>=0)
			ans = a*even+b*odd;
		else if(a<=0 and b<=0){
			if(even>0)
				ans = a;
			else
				ans = b;
		}
		else if(a>=0 and b<=0){
			if(even>0)
				ans = a*even;
			else
				ans = b;
		}
		else if(a<=0 and b>=0){
			if(even>0)
				ans = a+b*odd;
			else
				ans = b*odd;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}