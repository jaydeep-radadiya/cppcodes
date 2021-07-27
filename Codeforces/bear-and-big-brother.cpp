#include<bits/stdc++.h>
using namespace std;

int main(){
	int lw,bw;
	cin>>lw>>bw;

	int cnt = 0;
	while(lw<=bw){
		lw = 3*lw;
		bw = 2*bw;
		cnt++;
	}

	cout<<cnt<<"\n";
	return 0;
}