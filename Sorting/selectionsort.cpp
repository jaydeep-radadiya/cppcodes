#include<bits/stdc++.h>
using namespace std;

int findMinIdx(vector<int> &arr,int i){
	int min_idx = i;
	while(i<arr.size()){
		if(arr[i]<arr[min_idx])
			min_idx = i;
		i++;
	}
	return min_idx;
}

void selectionsort(vector<int> &arr){
	for(int i=0;i<arr.size();i++){
		int min_idx = findMinIdx(arr,i);
		if(i!=min_idx)
			swap(arr[i],arr[min_idx]);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	selectionsort(arr);

	for(int val : arr)
		cout<<val<<" ";

	return 0;
}