#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {6,5,3,2,8,10,9};
	int k = 3;
	int n = sizeof(arr)/sizeof(int);

	priority_queue<int,vector<int>,greater<int>> minh;
	vector<int> ans;

	for(int i=0;i<n;i++){
		minh.push(arr[i]);
		if(minh.size()>k){
			int temp = minh.top();
			ans.push_back(temp);
			minh.pop();
		}
	}

	while(minh.size()>0){
		int temp = minh.top();
		ans.push_back(temp);
		minh.pop();
	}

	for(int val : ans)
		cout<<val<<" ";

	return 0;
}