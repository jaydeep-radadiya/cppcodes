#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr){
	for(int ele : arr)
		cout<<ele<<" ";
	cout<<"\n";
}

void bubble_sort_recursive(vector<int> &arr,int i,int n){
	if(n==1) return;
	if(i==n-1){
		print(arr);
		bubble_sort_recursive(arr,0,n-1);
		return;
	}
	if(arr[i]>arr[i+1])
		swap(arr[i],arr[i+1]);
	bubble_sort_recursive(arr,i+1,n);
}

int main(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	bubble_sort_recursive(arr,0,n);
	print(arr);

	return 0;
}