#include<bits/stdc++.h>
using namespace std;

char findNextElement(char arr[],char val,int n){
	int left = 0;
	int right = n-1;
	char res = '#';

	while(left<=right){
		int mid = left+(right-left)/2;

		if(arr[mid]==val)
			left = mid+1;
		else if(arr[mid]<val)
			left = mid+1;
		else if(arr[mid]>val){
			res = arr[mid];
			right = mid-1;
		}
	}
	return res;
}

int main(){
	char arr[] = {'A','K','S'};	
	char val = 'L';
	int n = sizeof(arr)/sizeof(char);
	cout<<findNextElement(arr,val,n);
	return 0;
}