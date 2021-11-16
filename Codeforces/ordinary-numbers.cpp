/*
Note that every ordinary number can be represented as d⋅(10^0+10^1+…+10^k)
Therefore, to count all ordinary numbers among the numbers from 1 to n 
It is enough to count the number of (d,k) pairs such that d⋅(100+101+…+10k)<=n
In the given constraints, it is enough to iterate over d from 1 to 9 and k from 0 to 8
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n){
	int res = 0;
	for(int pw=1;pw<=n;pw=pw*10+1){
		for(int d=1;d<=9;d++){
			if(pw*d<=n){
				res++;
			}
		}
	}
	return res;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		cout<<solve(n)<<"\n";
	}
	return 0;
}