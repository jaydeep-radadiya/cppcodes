#include<bits/stdc++.h>
using namespace std;

vector<int> ds;
void solve(int i,vector<int> &ds,vector<int> &arr,int n){
	// base case
	if(i==n){
		for(int ele : ds){
			cout<<ele<<" ";
		}
		cout<<"\n";
		return;
	}

	// pick element
	ds.push_back(arr[i]);
	solve(i+1,ds,arr,n);

	// not pick element
	ds.pop_back();
	solve(i+1,ds,arr,n);
}

int main(){
	vector<int> arr {11,22,33};
	int n = arr.size();
	solve(0,ds,arr,n);
	return 0;
}