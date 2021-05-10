#include<bits/stdc++.h>
using namespace std;

int findKRotation(int arr[],int n){
	int left = 0;
	int right = n-1;

	while(left<=right){
		if(arr[left]<=arr[right])
			return left;

		int mid = left+(right-left)/2;
		int prev = (mid-1+n)%n;
		int next = (mid+1)%n;

		if(arr[mid]<=arr[prev] and arr[mid]<=arr[next])
			return mid;
		else if(arr[left]<=arr[mid])
			left = mid+1;
		else if(arr[mid]<=arr[right])
			right = mid-1;
	}
	return -1;
}

int main(){
	int arr[] = {15,18,2,3,6,12};
	int n = sizeof(arr)/sizeof(int);
	cout<<findKRotation(arr,n);
	return 0;
}