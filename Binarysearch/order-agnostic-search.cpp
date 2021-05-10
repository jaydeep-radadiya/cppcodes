#include<bits/stdc++.h>
using namespace std;

// binary search on ascending array
int bsa(int arr[],int val,int n){
	int left = 0;
	int right = n-1;

	while(left<=right){
		int mid = left+(right-left)/2;

		if(arr[mid]==val)
			return mid;
		else if(arr[mid]<val)
			left = mid+1;
		else if(arr[mid]>val)
			right = mid-1;
	}
	return -1;
}

// binary search on descending array
int bsd(int arr[],int val,int n){
	int left = 0;
	int right = n-1;

	while(left<=right){
		int mid = left+(right-left)/2;

		if(arr[mid]==val)
			return mid;
		else if(arr[mid]<val)
			right = mid-1;
		else if(arr[mid]>val)
			left = mid+1;
	}
	return -1;
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};	
	int val = 3;
	int n = sizeof(arr)/sizeof(int);

	if(arr[0]<arr[n-1])
		cout<<bsa(arr,val,n);
	else
		cout<<bsd(arr,val,n);

	return 0;
}