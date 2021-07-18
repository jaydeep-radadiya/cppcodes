#include<bits/stdc++.h>
using namespace std;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

// work for all positive values
void countingsort(vector<int> &arr){
	int mx = *max_element(arr.begin(),arr.end());
	vector<int> freq(mx+1,0);

	// frequency array
	for(int &ele : arr)
		freq[ele]++;

	// prefix array
	for(int i=1;i<=mx;i++)
		freq[i] += freq[i-1];

	vector<int> output(arr.size());
	for(int i=arr.size()-1;i>=0;i--){
		output[freq[arr[i]]-1] = arr[i];
		freq[arr[i]]--;
	}
	// final result is in output 
	arr = output;
}

int main(){
	fastIO();

	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}

	countingsort(arr);

	for(int ele : arr)
		cout<<ele<<" ";

	return 0;
}