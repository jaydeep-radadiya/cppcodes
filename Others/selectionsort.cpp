#include<bits/stdc++.h>
using namespace std;

int find_min(vector<int> &arr,int start){
	int min_idx = start;
	for(int i=start+1;i<arr.size();i++){
		if(arr[i]<arr[min_idx])
			min_idx = i;
	}
	return min_idx;
}

void selectionsort(vector<int> &arr){
	for(int i=0;i<arr.size();i++){
		int min_idx = find_min(arr,i);
		if(min_idx != i)
			swap(arr[min_idx],arr[i]);
	}
}

int main(){
	vector<int> arr {11,33,44,22};

	cout<<"before : ";
	for(int ele : arr)
		cout<<ele<<" ";

	selectionsort(arr);

	cout<<"\n"<<"after : ";
	for(int ele : arr)
		cout<<ele<<" ";

	return 0;
}