#include<bits/stdc++.h>
using namespace std;

int minDifference(int arr[],int val,int n){
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

	if(abs(arr[right]-val)<abs(arr[left]-val))
		return arr[right];
	else 
		return arr[left];
}

int main(){
	int arr[] = {1,3,8,10,15};
	int val = 12;
	int n = sizeof(arr)/sizeof(int);
	cout<<minDifference(arr,val,n);
	return 0;
}