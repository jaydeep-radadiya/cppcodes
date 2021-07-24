#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,m,l;
		cin>>n>>m>>l;

		vector<int> arr(n+1);
		for(int i=0;i<m;i++){
			int x;
			cin>>x;
			for(int j=0;j<x;j++){
				int y;
				cin>>y;
				arr[y] = i;
			}
		}

		vector<int> v(l);
		for(int i=0;i<l;i++)
			cin>>v[i];

		int cnt = 1;
		for(int i=1;i<l;i++){
			if(arr[v[i]]!=arr[v[i-1]]){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}

	return 0;
}