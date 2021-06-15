#include<bits/stdc++.h>
using namespace std;

stack<int> s; // normal satck
stack<int> ss; // supporting stack containg min value

int getMin(){
	if(s.size==0)
		return -1;
	else
		return ss.top();
}

int pop(){
	if(s.size()==0)
		return -1;
	int ans = s.top();
	s.pop();
	if(ss.top()==ans)
		ss.pop();
	return ans;
}

void push(int a){
	s.push(a);
	if(ss.size()==0 || a<=ss.top())
		ss.push(a);
}

int main(){


	return 0;
}