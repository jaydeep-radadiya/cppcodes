#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {7,10,4,3,20,15};
	int k = 3;
	int n = sizeof(arr)/sizeof(int);

	priority_queue<int> maxh;

	for(int i=0;i<n;i++){
		maxh.push(arr[i]);
		if(maxh.size()>k)
			maxh.pop();
	}

	cout<<maxh.top();
	return 0;
}