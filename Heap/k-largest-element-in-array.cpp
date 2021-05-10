#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {7,10,4,3,20,15};
	int k = 3;
	int n = sizeof(arr)/sizeof(int);

	priority_queue<int,vector<int>,greater<int>> minh;

	for(int i=0;i<n;i++){
		minh.push(arr[i]);
		if(minh.size()>k)
			minh.pop();
	}

	while(minh.size()>0){
		cout<<minh.top()<<" ";
		minh.pop();
	}

	return 0;
}