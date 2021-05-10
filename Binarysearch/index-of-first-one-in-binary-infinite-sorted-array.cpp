#include<bits/stdc++.h>
using namespace std;

int findIndex(int arr[],int val){
	int left = 0;
	int right = 1;
	int res = -1;

	// first find the range
	while(val>arr[right]){
		left = right;
		right = 2*right;
	}

	// apply binary search on that range
	while(left<=right){
		int mid = left+(right-left)/2;

		if(arr[mid]==val){
			res = mid;
			right = mid-1;
		}
		else if(arr[mid]<val)
			left = mid+1;
	}
	return res;
}

int main(){
	// suppose this array is infinite
	int arr[] = {0,0,1,1,1,1};
	int val = 1;
	cout<<findIndex(arr,val);
	return 0;
}