#include<bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> &arr){
	int n = arr.size();
	vector<int> ans;

	int temp = 0;
	for(int i=0;i<n;i++){
		temp = temp^(i+1)^arr[i];
	}

	// find last set bit
	int i = 0;
	while(temp>0){
		if(temp&1)
			break;
		else{
			i++;
			temp = temp/2;
		}
	}

	int mask = 1<<i;

	int b1 = 0;
	int b2 = 0;
	for(int i=0;i<n;i++){
		if(mask&arr[i])
			b1 = b1^arr[i];
		else
			b2 = b2^arr[i];
	}

	for(int i=1;i<=n;i++){
		if(mask&i)
			b1 = b1^i;
		else
			b2 = b2^i;
	}

	int m = 0; // missing
	int r = 0; // repeating
	for(int i=0;i<n;i++){
		if(arr[i]==b1){
			r = b1;
			m = b2;
			break;
		}
	}

	if(m==0 && r==0){
		m = b1;
		r = b2;
	}

	ans.push_back(r);
	ans.push_back(m);
	return ans;
}

int main(){
	vector<int> arr {4,3,6,2,1,1};
	vector<int> ans = findTwoElement(arr);
	cout<<ans[0]<<"\n"<<ans[1];
	return 0;
}