#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr){
	int n = arr.size();
	for(int i=1;i<n;i++){
		int ele = arr[i];
		int j = i-1;
		while(j>=0 and arr[j]>ele){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = ele;
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	insertion_sort(arr);

	for(int ele : arr)
		cout<<ele<<" ";

	return 0;
}