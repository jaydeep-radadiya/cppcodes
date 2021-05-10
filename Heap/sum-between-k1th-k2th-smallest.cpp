#include<bits/stdc++.h>
using namespace std;

int kthsmallest(int arr[],int k,int n){
	priority_queue<int> maxh;

	for(int i=0;i<n;i++){
		maxh.push(arr[i]);
		if(maxh.size()>k)
			maxh.pop();
	}
	return maxh.top();
}

int main(){
	int arr[] = {1,3,12,5,15,11};
	int n = sizeof(arr)/sizeof(int);
	int k1 = 3;
	int k2 = 6;

	int k1th = kthsmallest(arr,k1,n);
	int k2th = kthsmallest(arr,k2,n);

	int sum = 0;
	for(int i=0;i<n;i++){
		if(arr[i]>k1th and arr[i]<k2th)
			sum += arr[i];
	}

	cout<<sum;
	return 0;
}