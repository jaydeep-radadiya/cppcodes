#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int mnval = *min_element(arr.begin(),arr.end());
	int mxval = *max_element(arr.begin(),arr.end());
	// cout<<mnval<<" "<<mxval<<"\n";
	
	int mnidx = find(arr.rbegin(),arr.rend(),mnval)-arr.rbegin();
	mnidx = n-1-mnidx;
	int mxidx = find(arr.begin(),arr.end(),mxval)-arr.begin();
	// cout<<mnidx<<" "<<mxidx<<"\n";
	
	if(mnidx>mxidx)
		cout<<n-1-mnidx+mxidx<<"\n";
	else
		cout<<n-2-mnidx+mxidx<<"\n";
	
	return 0;
}