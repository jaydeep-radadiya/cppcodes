#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[],int arr2[],int n1,int n2){
	for(int i=0;i<n1;i++){
		if(arr1[i]>arr2[0]){
			swap(arr1[i],arr2[0]);
			int first = arr2[0];

			int j = 1;
			while(j<n2 and first>arr2[j]){
				arr2[j-1] = arr2[j];
				j++;
			}
			arr2[j-1] = first;
		}
	}
}

void secondMethod(int arr1[],int arr2[],int n1,int n2){
	for(int i=n1-1,j=0;i>=0 and j<n2;i--,j++){
		if(arr2[j]<arr1[i]){
			swap(arr1[i],arr2[j]);
		}
	}

	sort(arr1,arr1+n1);
	sort(arr2,arr2+n2);
}

int main(){
	int n1,n2;
	cin>>n1>>n2;
	int arr1[n1];
	for(int i=0;i<n1;i++)
		cin>>arr1[i];
	int arr2[n2];
	for(int i=0;i<n2;i++)
		cin>>arr2[i];

	merge(arr1,arr2,n1,n2);
	// secondMethod(arr1,arr2,n1,n2);

	cout<<"arr1 : "<<"\n";
	for(int ele : arr1)
		cout<<ele<<" ";
	cout<<"\n"<<"arr2 : "<<"\n";
	for(int ele : arr2)
		cout<<ele<<" ";

	return 0;
}