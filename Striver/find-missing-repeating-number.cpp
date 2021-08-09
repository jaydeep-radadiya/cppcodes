#include<bits/stdc++.h>
using namespace std;

pair<int,int> solve(vector<int> &arr,int n){
	int val = 0;
	for(int i=0;i<n;i++)
		val = val^arr[i]^(i+1);
	
	// find the last set bit
	int i = 0;
	int temp = val;
	while(temp>0){
		if(temp&1)
			break;
		i++;
		temp = temp>>1;
	}

	int mask = 1<<i;

	int bkt1 = 0;
	int bkt2 = 0;
	for(int ele : arr){
		if(ele&mask)
			bkt1 = bkt1^ele;
		else
			bkt2 = bkt2^ele;
	}

	for(int i=1;i<=n;i++){
		if(i&mask)
			bkt1 = bkt1^i;
		else
			bkt2 = bkt2^i;
	}

	bool flag = false;
	int miss = 0;
	int repeat = 0;
	for(int ele : arr){
		if(ele==bkt1){
			repeat = bkt1;
			miss = bkt2;
			flag = true;
			break;
		}
	}

	if(flag==false){
		miss = bkt1;
		repeat = bkt2;
	}

	return pair<int,int> {miss, repeat};
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	pair<int,int> p = solve(arr,n);

	cout<<"missing : "<<p.first<<"\n";
	cout<<"repeating : "<<p.second<<"\n";

	return 0;
}