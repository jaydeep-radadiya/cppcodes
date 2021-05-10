#include<bits/stdc++.h>
using namespace std;

int findIndex(int arr[],int val,int n){
	int left = 0;
	int right = n-1;

	while(left<=right){
		int mid = left+(right-left)/2;

		if(arr[mid]==val)
			return mid;
		else if(mid-1>=left and arr[mid-1]==val)
			return mid-1;
		else if(mid+1<=right and arr[mid+1]==val)
			return mid+1;

		if(arr[mid]<val)
			left = mid+2;
		else if(arr[mid]>val)
			right = mid-2;
	}
	return -1;
}

int main(){
	int arr[] = {10,3,40,20,50,80,70};
	int val = 40;
	int n = sizeof(arr)/sizeof(int);
	cout<<findIndex(arr,val,n);
	return 0;
}