#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	for(int i=n+1;true;i++){
		unordered_set<int> ss;
		int n = i;
		while(n>0){
			ss.insert(n%10);
			n = n/10;
		}
		if(ss.size()==4){
			cout<<i<<"\n";
			return 0;
		}
	}

	return 0;
}