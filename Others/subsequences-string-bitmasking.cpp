#include<iostream>
#include<cstring>
using namespace std;

void filterChars(string s,int n){
	int i = 0;
	while(n>0){
		if(n&1)
			cout<<s[i];
		else
			cout<<"";
		n = n>>1;
		i++;
	}
	cout<<"\n";
}

void generateSubsets(string s){
	int n = s.size();
	int range = 1<<n;
	for(int i=0;i<range;i++){
		filterChars(s,i);
	}
}

int main(){
	generateSubsets("abc");
	return 0;
}