#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {1,1,1,3,2,2,4};
	int n = sizeof(arr)/sizeof(int);

	unordered_map<int,int> ump;
	for(int i=0;i<n;i++)
		ump[arr[i]]++;

	priority_queue<pair<int,int>> maxh;
	for(auto it=ump.begin();it!=ump.end();it++){
		maxh.push({it->second,it->first});
	}

	int i = 0;
	while(maxh.size()>0){
		int val = maxh.top().second;
		int fre = maxh.top().first;

		while(fre--){
			arr[i] = val;
			i++;
		}
		maxh.pop();
	}

	for(int ele : arr)
		cout<<ele<<" ";

	return 0;
}