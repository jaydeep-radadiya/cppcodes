#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[],int arr2[],int m,int n){
	for(int i=0;i<m;i++){
		if(arr1[i]>arr2[0]){
			swap(arr1[i],arr2[0]);
			int first = arr2[0];

			int j = 1;
			while(j<n and first>arr2[j]){
				arr2[j-1] = arr2[j];
				j++;
			}
			arr2[j-1] = first;
		}
	}
}

void secondMethod(int arr1[],int arr2[],int m,int n){
	for(int i=m-1,j=0;i>=0 and j<n;i--,j++){
		if(arr2[j]<arr1[i]){
			swap(arr1[i],arr2[j]);
		}
	}

	sort(arr1,arr1+m);
	sort(arr2,arr2+n);
}

int main(){
	int m,n;
	cin>>m>>n;
	int arr1[m];
	for(int i=0;i<m;i++)
		cin>>arr1[i];
	int arr2[n];
	for(int i=0;i<n;i++)
		cin>>arr2[i];

	// merge(arr1,arr2,m,n);
	secondMethod(arr1,arr2,m,n);

	cout<<"arr1 : "<<"\n";
	for(int ele : arr1)
		cout<<ele<<" ";
	cout<<"\n"<<"arr2 : "<<"\n";
	for(int ele : arr2)
		cout<<ele<<" ";

	return 0;
}