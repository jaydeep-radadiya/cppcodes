#include<bits/stdc++.h>
using namespace std;

int findMaxElement(int arr[],int n){
	int left = 0;
	int right = n-1;

	while(left<=right){
		int mid = left+(right-left)/2;

		if(mid>0 and mid<n-1){
			if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1])
				return arr[mid];
			else if(arr[mid-1]>arr[mid])
				right = mid-1;
			else if(arr[mid+1]>arr[mid])
				left = mid+1;
		}
		else if(mid==0){
			if(arr[0]>arr[1])
				return arr[0];
			else
				return arr[1];
		}
		else if(mid==n-1){
			if(arr[n-1]>arr[n-2])
				return arr[n-1];
			else
				return arr[n-2];
		}
	}
	return -1;
}

int main(){
	int arr[] = {1,4,8,3,2};
	int n = sizeof(arr)/sizeof(int);
	cout<<findMaxElement(arr,n);
	return 0;
}