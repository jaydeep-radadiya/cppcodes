#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n,k,q;
	cin>>n>>k>>q;
	vector<int> temp(200001,0);
	for(int i=0;i<n;i++){
		ll li,ri;
		cin>>li>>ri;
		temp[li]++;
		if(ri+1<temp.size())
			temp[ri+1]--;
	}

	for(int i=1;i<temp.size();i++)
		temp[i] = temp[i-1]+temp[i];

	for(int i=0;i<temp.size();i++){
		if(temp[i]>=k)
			temp[i] = 1;
		else
			temp[i] = 0;
	}

	for(int i=1;i<temp.size();i++)
		temp[i] = temp[i-1]+temp[i];

	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<temp[b]-temp[a-1]<<"\n";
	}

	return 0;
}