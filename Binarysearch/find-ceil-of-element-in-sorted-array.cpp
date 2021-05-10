#include<bits/stdc++.h>
using namespace std;

int findCeil(int arr[],int val,int n){
	int left = 0;
	int right = n-1;
	int res = -1;

	while(left<=right){
		int mid = left+(right-left)/2;

		if(arr[mid]==val)
			return mid;
		else if(arr[mid]<val)
			left = mid+1;
		else if(arr[mid]>val){
			res = mid;
			right = mid-1;
		}
	}
	return res;
}

int main(){
	int arr[] = {1,2,8,10,10,12,19};
	int val = 9;
	int n = sizeof(arr)/sizeof(int);
	// print index of ceil value
	cout<<findCeil(arr,val,n);
	return 0;
}