#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s,int i,int k){
	if(i==k){
		s.pop();
		return;
	}
	int temp = s.top();
	s.pop();
	solve(s,i+1,k);
	s.push(temp);
}

int main(){
	int n,i=0;
	cin>>n;
	stack<int> s;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		s.push(x);
	}
	int k = (n/2)+1;
	solve(s,i,k);

	while(s.size()>0){
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}