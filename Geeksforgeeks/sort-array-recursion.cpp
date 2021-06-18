#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v,int temp){
	// base case
	if(v.size()==0 || v[v.size()-1]<=temp){
		v.push_back(temp);
		return;
	}
	// self work
	int val = v[v.size()-1];
	v.pop_back();
	// recursive intuition
	insert(v,temp);
	// self work
	v.push_back(val);
}

void sort(vector<int> &v){
	// base case
	if(v.size()==1)
		return;
	// self work
	int temp = v[v.size()-1];
	v.pop_back();
	// recursive intuition
	sort(v);
	// self work
	insert(v,temp);
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];

	sort(v);

	for(int ele : v)
		cout<<ele<<" ";

	return 0;
}