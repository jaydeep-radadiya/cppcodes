#include<bits/stdc++.h>
using namespace std;

// consecutive smaller or equal before it

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	stack<pair<int,int>> s;
	vector<int> ans; // store index of NGL

	for(int i=0;i<n;i++){
		if(s.size()==0)
			ans.push_back(-1);
		else if(s.size()>0 && s.top().first>arr[i])
			ans.push_back(s.top().second);
		else if(s.size()>0 && s.top().first<=arr[i]){
			while(s.size()>0 && s.top().first<=arr[i])
				s.pop();
			if(s.size()==0)
				ans.push_back(-1);
			else
				ans.push_back(s.top().second);
		}
		s.push({arr[i],i});
	}

	for(int i=0;i<n;i++){
		ans[i] = i-ans[i];
	}

	for(int ele : ans)
		cout<<ele<<" ";

	return 0;
}