#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr,int cow,int dist){ // O(n)
	int cnt = 1;
	int lastPos = arr[0];
	for(int i=1;i<arr.size();i++){
		if(arr[i]-lastPos>=dist){
			// place here
			lastPos = arr[i];
			cnt++;
		}
		if(cnt==cow){
			return true;
		}
	}
	return false;
}

// bs on distance
int solve(vector<int> &arr,int cow){
	sort(arr.begin(),arr.end()); // O(nlogn)
	int lo = 1;
	int hi = arr.back();
	int result = 0;

	while(lo<=hi){ // O(nlogn)
		int mid = lo+(hi-lo)/2; // candidate distance
		// we will try to arrange all cows mid distance apart
		if(isValid(arr,cow,mid)){ // O(n)
			lo = mid+1;
			result = mid;
		}
		else{
			hi = mid-1;
		}
	}
	return result;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,c;
		cin>>n>>c;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<solve(arr,c)<<"\n";
	}

	return 0;
}