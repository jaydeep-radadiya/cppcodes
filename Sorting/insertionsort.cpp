#include<bits/stdc++.h>
using namespace std;

void insertionsort(vector<int> &arr){
	for(int i=1;i<arr.size();i++){
		int key = arr[i];
		int j = i-1;
		while(j>=0 and arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}

	insertionsort(arr);

	for(int val : arr)
		cout<<val<<" ";

	return 0;
}