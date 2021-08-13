#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline(cin,s);

	unordered_set<char> ss;
	for(int i=0;i<s.size();i++){
		if(s[i]>=97 && s[i]<=122){
			ss.insert(s[i]);
		}
	}

	cout<<ss.size()<<"\n";
	return 0;
}