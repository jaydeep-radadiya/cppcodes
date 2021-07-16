#include<bits/stdc++.h>
using namespace std;

int countZeros(int n){
	int cnt = 0;
	int i = 5;
	while(i<=n){
		cnt += n/i;
		i = i*5;
	}
	return cnt;
}

int main(){
	int n;
	cin>>n;
	cout<<countZeros(n)<<"\n";
	return 0;
}