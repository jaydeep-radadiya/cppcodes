#include<bits/stdc++.h>
using namespace std;

int solve(int n){
	int steps = 0;
	while(n>0){
		if(n>=5)
			n -= 5;
		else if(n>=4)
			n -= 4;
		else if(n>=3)
			n -= 3;
		else if(n>=2)
			n -= 2;
		else if(n>=1)
			n -= 1;
		steps++; 
	}
	return steps;
}

int main(){
	int n;
	cin>>n;

	// cout<<solve(n)<<"\n";

	if(n%5==0)
		cout<<n/5<<"\n";
	else
		cout<<(n/5)+1<<"\n";
	
	return 0;
}