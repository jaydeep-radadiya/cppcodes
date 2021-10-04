#include<bits/stdc++.h>
using namespace std;

int firstMethod(vector<int> &arr){
	int n = arr.size();
	int mx_sum = arr[0];

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum = 0;
			for(int k=i;k<=j;k++){
				sum += arr[k];
			}
			mx_sum = max(mx_sum,sum);
		}
	}
	return mx_sum;
}

int secondMethod(vector<int> &arr){
	int n = arr.size();
	int mx_sum = arr[0];

	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum += arr[j];
			mx_sum = max(mx_sum,sum);
		}
	}
	return mx_sum;
}

int thirdMethod(vector<int> &arr){
	int n = arr.size();
	int mx_sum = arr[0];
	int sum = 0;

	for(int i=0;i<n;i++){
		sum = max(sum+arr[i],arr[i]);
		mx_sum = max(mx_sum,sum);
	}
	return mx_sum;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<firstMethod(arr)<<"\n";
	cout<<secondMethod(arr)<<"\n";
	cout<<thirdMethod(arr)<<"\n";

	return 0;
}