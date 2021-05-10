#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> ppi;

int main(){
	int arr[][2] = {{1,3},{-2,2},{5,8},{0,1}};
	int row = sizeof(arr)/sizeof(arr[0]);
	int col = 2;
	int k = 2;

	priority_queue<ppi> maxh;

	for(int i=0;i<row;i++){
		maxh.push({arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1],{arr[i][0],arr[i][1]}});
		if(maxh.size()>k)
			maxh.pop();
	}

	while(maxh.size()>0){
		pair<int,int> p = maxh.top().second;
		cout<<p.first<<" "<<p.second<<"\n";
		maxh.pop();
	}

	return 0;
}