#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr,int n,int k){
	vector<int> ans;
	vector<int> temp;
	int i = 0;
	int j = 0;

	while(j<n){
		if(arr[j]<0)
			temp.push_back(arr[j]);
		if(j-i+1<k)
			j++;
		else if(j-i+1==k){
			if(temp.size()==0)
				ans.push_back(0);
			else if(temp.size()>0)
				ans.push_back(temp.front());
			if(temp.size()>0 && temp.front()==arr[i])
				temp.erase(temp.begin());
			i++;
			j++;
		}
	}
	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	vector<int> ans = solve(arr,n,k);

	for(int ele : ans)
		cout<<ele<<" ";

	return 0;
}