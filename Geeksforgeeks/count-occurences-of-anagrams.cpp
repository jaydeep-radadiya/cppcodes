#include<bits/stdc++.h>
using namespace std;

int search(string str,string ptn){
	int n = str.size();
	int k = ptn.size();

	unordered_map<char,int> ptnmap;
	for(int i=0;i<k;i++)
		ptnmap[ptn[i]]++;

	int i=0,j=0;
	int cnt = ptnmap.size();
	int ans = 0;

	while(j<n){
		if(ptnmap.find(str[j])!=ptnmap.end()){
			ptnmap[str[j]]--;
			if(ptnmap[str[j]]==0)
				cnt--;
		}

		if(j-i+1<k)
			j++;
		else if(j-i+1==k){
			if(cnt==0)
				ans++;
			if(ptnmap.find(str[i])!=ptnmap.end()){
				ptnmap[str[i]]++;
				if(ptnmap[str[i]]==1)
					cnt++;
			}
			i++;
			j++;
		}
	}
	return ans;
}

int main(){
	string str,ptn;
	cin>>str>>ptn;

	int ans = search(str,ptn);
	cout<<ans<<"\n";

	return 0;
}