#include<bits/stdc++.h>
using namespace std;

void singleNumber(vector<int> arr){
	int n = arr.size();
	int res = 0;
	for(int i=0;i<n;i++)
		res = res^arr[i];

	// find the last or right most set bit
	int temp = res;
	int i = 0;
	while(temp>0){
		if(temp&1)
			break;
		i++;
		temp = temp>>1;
	}

	int mask = (1<<i); // make mask
	int first = 0;
	int second = 0;

	for(int i=0;i<n;i++){
		if(arr[i]&mask){
			first = first^arr[i];
		}
	}

	second = first^res;
	cout<<"first number : "<<first<<"\n";
	cout<<"second number : "<<second<<"\n";
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	singleNumber(arr);
	return 0;
}