#include<bits/stdc++.h>
using namespace std;

int solve(string s){
	int n = s.size();
	unordered_map<char,int> ump;
	int mx = 0;
	int i = 0;
	int j = 0;

	while(j<n){
		ump[s[j]]++;
		if(ump.size()==j-i+1){
			mx = max(mx,j-i+1);
			j++;
		}
		else if(ump.size()<j-i+1){
			while(ump.size()<j-i+1){
				ump[s[i]]--;
				if(ump[s[i]]==0)
					ump.erase(s[i]);
				i++;
			}
			j++;
		}
	}
	return mx;
}

int main(){
	string s;
	cin>>s;
	cout<<solve(s);
	return 0;
}