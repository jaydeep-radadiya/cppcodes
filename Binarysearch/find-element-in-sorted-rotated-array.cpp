#include<bits/stdc++.h>
using namespace std;

int findMinValueIndex(int arr[],int n){
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

int findIndex(int arr[],int val,int left,int right){
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
	int arr[] = {4,5,6,7,0,1,2};
	int val = 4;
	int n = sizeof(arr)/sizeof(int);

	int idx = findMinValueIndex(arr,n);
	int first = findIndex(arr,val,0,idx-1);
	int second = findIndex(arr,val,idx,n-1);

	if(first==-1 and second==-1)
		cout<<-1<<"\n";
	else if(first==-1)
		cout<<second<<"\n";
	else if(second==-1)
		cout<<first<<"\n";

	return 0;
}