#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s,int temp){
	if(s.size()==0){
		s.push(temp);
		return;
	}
	int val = s.top();
	s.pop();
	insert(s,temp);
	s.push(val);
}

void solve(stack<int> &s){
	if(s.size()==1)
		return;
	int temp = s.top();
	s.pop();
	solve(s);
	insert(s,temp);
}

int main(){
	int n;
	cin>>n;
	stack<int> s;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		s.push(x);
	}

	solve(s);

	while(s.size()>0){
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}