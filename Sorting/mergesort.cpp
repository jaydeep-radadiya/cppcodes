#include<bits/stdc++.h>
using namespace std;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void merge(int *arr,int start,int end){
	int mid = start+(end-start)/2;
	int i = start, j = mid+1;
	// smart pointer
	unique_ptr<int[]> result(new int[end-start]);
	// int *result = new int[end-start]();
	int k = 0;
	while(i<=mid and j<=end){
		if(arr[i]<arr[j])
			result[k++] = arr[i++];
		else
			result[k++] = arr[j++];
	}
	while(i<=mid)
		result[k++] = arr[i++];
	while(j<=end)
		result[k++] = arr[j++];

	// copy data into main array
	k = 0;
	for(int i=start;i<=end;i++)
		arr[i] = result[k++];
	// delete [] result;
}

void mergesort(int *arr,int start,int end){
	if(start>=end) return;
	int mid = start+(end-start)/2;
	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);
	merge(arr,start,end);
}

int main(){
	fastIO();

	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	mergesort(arr,0,n-1);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	return 0;
}