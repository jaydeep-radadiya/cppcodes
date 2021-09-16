#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr){
	int n = arr.size();
	for(int i=0;i<n-1;i++){
		bool is_swapped = false;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				is_swapped = true;
			}
		}
		if(is_swapped==false)
			break;
	}
}

int main(){
	vector<int> arr {5,6,2,6,9,0};
	int n = arr.size();

	cout<<"before : ";
	for(int ele : arr)
		cout<<ele<<" ";

	bubble_sort(arr);

	cout<<"\n"<<"after : ";
	for(int ele : arr)
		cout<<ele<<" ";

	return 0;
}