#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;

	string ans = "";
	for(int i=0;i<s1.size();i++){
		if(s1[i]==s2[i])
			ans.push_back('0');
		else
			ans.push_back('1');
	}

	cout<<ans<<"\n";
	return 0;
}