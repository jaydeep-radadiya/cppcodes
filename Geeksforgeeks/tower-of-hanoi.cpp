#include<bits/stdc++.h>
using namespace std;

void solve(int n,string src,string dest,string helper){
	if(n==0) return;
	solve(n-1,src,helper,dest);
	cout<<"move disk "<<n<<" from "<<src<<" to "<<dest<<"\n";
	solve(n-1,helper,dest,src);
}

int main(){
	int n;
	cin>>n;
	solve(n,"src","dest","helper");
	return 0;
}