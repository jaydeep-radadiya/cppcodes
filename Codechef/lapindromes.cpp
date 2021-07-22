#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)

int main(){
	fastIO();

	int t;
	cin>>t;

	while(t--){
		string s;
		cin>>s;

		int n = s.size();
		unordered_map<char,int> ump;
		for(int i=0;i<n/2;i++){
			ump[s[i]]++;
		}

		int j = -1;
		if(n%2==0)
			j = n/2;
		else
			j = n/2+1;

		int flag = true;
		for(int i=j;i<n;i++){
			if(ump.find(s[i])==ump.end()){
				flag = false;
				break;
			}
			ump[s[i]]--;
			if(ump[s[i]]==0)
				ump.erase(s[i]);
		}

		if(flag==false)
			cout<<"NO"<<"\n";
		else
			cout<<"YES"<<"\n";
	}

	return 0;
}