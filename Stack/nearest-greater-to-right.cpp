#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	vector<int> ans;
	stack<int> s;

	for(int i=n-1;i>=0;i--){
		if(s.size()==0)
			ans.push_back(-1);
		else if(s.size()>0 and s.top()>arr[i])
			ans.push_back(s.top());
		else if(s.size()>0 and s.top()<=arr[i]){
			while(s.size()>0 and s.top()<=arr[i])
				s.pop();
			if(s.size()==0)
				ans.push_back(-1);
			else
				ans.push_back(s.top());
		}
		s.push(arr[i]);
	}

	reverse(ans.begin(),ans.end());
	for(int ele : ans)
		cout<<ele<<" ";

	return 0;
}