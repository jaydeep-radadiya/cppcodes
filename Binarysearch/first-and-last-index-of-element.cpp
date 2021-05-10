#include<bits/stdc++.h>
using namespace std;

int firstIndex(int arr[],int val,int n){
	int left = 0;
	int right = n-1;
	int res = -1;

	while(left<=right){
		int mid = left+(right-left)/2;

		if(arr[mid]==val){
			res = mid;
			right = mid-1;
		}
		else if(arr[mid]<val)
			left = mid+1;
		else if(arr[mid]>val)
			right = mid-1;
	}
	return res;
}

int lastIndex(int arr[],int val,int n){
	int left = 0;
	int right = n-1;
	int res = -1;

	while(left<=right){
		int mid = left+(right-left)/2;

		if(arr[mid]==val){
			res = mid;
			left = mid+1;
		}
		else if(arr[mid]<val)
			left = mid+1;
		else if(arr[mid]>val)
			right = mid-1;
	}
	return res;
}

int main(){
	int arr[] = {2,4,10,10,10,18,20};
	int val = 10;
	int n = sizeof(arr)/sizeof(int);

	int fi = firstIndex(arr,val,n);
	int li = lastIndex(arr,val,n);

	cout<<fi<<"\n";
	cout<<li<<"\n";	

	return 0;
}