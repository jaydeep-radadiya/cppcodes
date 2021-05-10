#include<bits/stdc++.h>
using namespace std;

int findPeakIndex(int arr[],int n){
	int left = 0;
	int right = n-1;

	while(left<=right){
		int mid = left+(right-left)/2;

		if(mid>0 and mid<n-1){
			if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1])
				return mid;
			else if(arr[mid+1]>arr[mid])
				left = mid+1;
			else if(arr[mid-1]>arr[mid])
				right = mid-1;
		}
		else if(mid==0){
			if(arr[0]>arr[1])
				return 0;
			else
				return 1;
		}
		else if(mid==n-1){
			if(arr[n-1]>arr[n-2])
				return n-1;
			else 
				return n-2;
		}
	}
	return -1;
}

// binary search on ascending array
int bsa(int arr[],int val,int left,int right){
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
int bsd(int arr[],int val,int left,int right){
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
	int arr[] = {5,6,7,8,9,10,3,2,1};
	int val = 2;
	int n = sizeof(arr)/sizeof(int);
	// index of peak element
	int idx = findPeakIndex(arr,n);
	int first = bsa(arr,val,0,idx-1);
	int second = bsd(arr,val,idx,n-1);

	if(first==-1 and second==-1)
		cout<<-1<<"\n";
	else if(first==-1)
		cout<<second<<"\n";
	else if(second==-1)
		cout<<first<<"\n";

	return 0;
}