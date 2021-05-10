#include<bits/stdc++.h>
using namespace std;

int findIndex(int arr[],int val){
	int left = 0;
	int right = 1;

	// first find the range
	while(val>arr[right]){
		left = right;
		right = 2*right;
	}

	// apply binary search on that range
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

int main(){
	// suppose this array is infinite
	int arr[] = {1,3,5,8,12,13,17,19,28,39,103,123,140,2040};
	int val = 17;	
	cout<<findIndex(arr,val);
	return 0;
}