#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)

bool ts(vector<int> &arr,int target){
	int n = arr.size();
	int left = 0;
	int right = n-1;

	while(left<=right){
		int delta = (right-left)/3;
		int mid1 = left+delta;
		int mid2 = right-delta;

		if(arr[mid1]==target)
			return true;
		else if(arr[mid2]==target)
			return true;

		if(arr[mid1]>target)
			right = mid1-1;
		else if(arr[mid2]<target)
			left = mid2+1;
		else{
			left = mid1+1;
			right = mid2-1;
		}
	}
	return false;
}

int main(){
	fastIO();

	int n,target;
	cin>>n>>target;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	bool ans = ts(arr,target);
	if(ans==true)
		cout<<"Found"<<"\n";
	else
		cout<<"Not Found"<<"\n";

	return 0;
}