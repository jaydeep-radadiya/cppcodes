#include<bits/stdc++.h>
using namespace std;

int solve(string s,string t){
	unordered_map<char,int> ump;
	int mn = INT_MAX;
	int n = s.size();
	int k = t.size();
	int i = 0;
	int j = 0;

	for(int i=0;i<k;i++)
		ump[t[i]]++;
	int cnt = ump.size();

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
				mn = min(mn,j-i+1);
				if(ump.find(s[i])==ump.end()){
					i++;
				}
				else{ // present in map
					ump[s[i]]++;
					if(ump[s[i]]==1)
						cnt++;
					i++;
				}
			}
			j++;
		}
	}
	return mn;
}

int main(){
	string s,t;
	cin>>s>>t;
	cout<<solve(s,t);
	return 0;
}