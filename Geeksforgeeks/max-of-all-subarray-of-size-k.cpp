#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr,int n,int k){
	vector<int> ans;
	list<int> l;
	int i=0,j=0;

	if(k>n){
		ans.push_back(*max_element(arr.begin(),arr.end()));
		return ans;
	}

	while(j<n){
		while(l.size()>0 && l.back()<arr[j])
			l.pop_back();
		l.push_back(arr[j]);

		if(j-i+1<k)
			j++;
		else if(j-i+1==k){
			ans.push_back(l.front());
			if(l.front()==arr[i])
				l.pop_back();
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