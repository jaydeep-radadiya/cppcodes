#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &arr){
	int n = arr.size();
	for(int i=0;i<n-1;i++){
		bool is_sorted = false;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){ // check adjacent element
				swap(arr[j],arr[j+1]);
				is_sorted = true;
			}
		}

		if(is_sorted==false){
			break;
		}
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

	bubblesort(arr);

	for(int val : arr)
		cout<<val<<" ";

	return 0;
}