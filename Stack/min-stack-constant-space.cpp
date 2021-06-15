#include<bits/stdc++.h>
using namespace std;

stack<int> s;
int minele;

int getMin(){
	if(s.size()==0)
		return -1;
	else
		return minele;
}

void push(int a){
	if(s.size()==0){
		s.push(a);
		minele = a;
	}
	else{
		if(a>=minele){
			s.push(a);
		}
		else if(a<minele){
			s.push(2*a-minele)
			minele = a;
		}
	}
}

int top(){
	if(s.size()==0)
		return -1;
	else{
		if(s.top()>=minele)
			return s.top();
		else if(s.top()<minele) // remember
			return minele;
	}
}

void pop(){
	if(s.size()==0)
		return;
	else{
		if(s.top()>=minele){
			s.pop();
		}
		else if(s.top()<minele){
			minele = 2*minele-s.top();
			s.pop();
		}
	}
}

int main(){


	return 0;
}