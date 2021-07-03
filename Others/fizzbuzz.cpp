#include<bits/stdc++.h>
using namespace std;

void solve(int n){
	int c3 = 0;
	int c5 = 0;
	for(int i=1;i<=n;i++){
		string s = "";
		c3++; c5++;
		if(c3==3){
			s += "Fizz";
			c3 = 0;
		}
		if(c5==5){
			s += "Buzz";
			c5 = 0;
		}
		// print the output
		if(s=="")
			cout<<i<<"\n";
		else
			cout<<s<<"\n";
	}
}

int main(){
	solve(100);

	return 0;
}