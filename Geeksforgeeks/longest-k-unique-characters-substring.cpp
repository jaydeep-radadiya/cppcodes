#include<bits/stdc++.h>
using namespace std;

int solve(string s,int k){
	unordered_map<char,int> ump;
	int n = s.size();
	int mx = -1;
	int i = 0;
	int j = 0;

	while(j<n){
		ump[s[j]]++;
		if(ump.size()<k)
			j++;
		else if(ump.size()==k){
			mx = max(mx,j-i+1);
			j++;
		}
		else if(ump.size()>k){
			while(ump.size()>k){
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
	int k;
	cin>>k;

	cout<<solve(s,k);

	return 0;
}