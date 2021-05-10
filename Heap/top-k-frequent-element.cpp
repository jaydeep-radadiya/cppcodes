#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi; 

int main(){
	int arr[] = {1,1,1,3,2,2,4};
	int k = 2;
	int n = sizeof(arr)/sizeof(int);

	unordered_map<int,int> ump;
	for(int i=0;i<n;i++)
		ump[arr[i]]++;

	priority_queue<pi,vector<pi>,greater<pi>> minh;
	for(auto it=ump.begin();it!=ump.end();it++){
		minh.push({it->second,it->first});
		if(minh.size()>k)
			minh.pop();
	}

	while(minh.size()>0){
		cout<<minh.top().second<<" ";
		minh.pop();
	}

	return 0;
}