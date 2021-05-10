#include<bits/stdc++.h>
using namespace std;

bool isValid(int arr[],int mid,int k,int n){
	int student = 1;
	int sum = 0;

	for(int i=0;i<n;i++){
		sum += arr[i];

		if(sum>mid){
			student++;
			sum = arr[i];
		}

		if(student>k)
			return false;
	}
	return true;
}

int findPages(int arr[],int k,int n){
	if(k>n) return -1;

	int sum = 0;
	for(int i=0;i<n;i++)
		sum += arr[i];

	int left = 0;
	int right = sum;
	int res = -1;

	while(left<=right){
		int mid = left+(right-left)/2;

		if(isValid(arr,mid,k,n)==true){
			res = mid;
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	return res;
}

int main(){
	int arr[] = {10,20,30,40};
	int k = 2;
	int n = sizeof(arr)/sizeof(int);
	cout<<findPages(arr,k,n);
	return 0;
}