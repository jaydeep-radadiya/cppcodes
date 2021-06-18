#include<bits/stdc++.h>
using namespace std;

string solve(string s,string t){
	if(t.size()>s.size())
		return "";

	unordered_map<char,int> ump;
	int n = s.size();
	int k = t.size();
	for(int i=0;i<k;i++)
		ump[t[i]]++;
	int cnt = ump.size();

	int mn = INT_MAX;
	int idx = 0;
	int i = 0;
	int j = 0;

	while(j<n){
		if(ump.find(s[j])!=ump.end()){
			ump[s[j]]--;
			if(ump[s[j]]==0)
				cnt--;
		}

		if(cnt>0)
			j++;
		else if(cnt==0){
			while(cnt==0){
				if(j-i+1<mn){
					mn = j-i+1;
					idx = i;
				}

				if(ump.find(s[i])==ump.end())
					i++;
				else{
					ump[s[i]]++;
					if(ump[s[i]]==1)
						cnt++;
					i++;
				}
			}
			j++;
		}
	}

	if(mn==INT_MAX)
		return "";
	else
		return s.substr(idx,mn);
}

int main(){
	string s,t;
	cin>>s>>t;
	cout<<solve(s,t);
	return 0;
}