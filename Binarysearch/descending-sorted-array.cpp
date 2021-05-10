#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int val,int n){
	int left = 0;
	int right = n-1;

	while(left<=right){
		int mid = left+(right-left);

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
	int arr[] = {20,17,15,14,13,12,10,9,8,4};
	int val = 4;
	int n = sizeof(arr)/sizeof(int);
	cout<<solve(arr,val,n);	
	return 0;
}