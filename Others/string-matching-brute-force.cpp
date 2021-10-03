#include<bits/stdc++.h>
using namespace std;

// tc : O((n-m)*(m))
int bruteForce(string str,string pat){
	int n = str.size();
	int m = pat.size();
	for(int i=0;i<=n-m;i++){
		int j = 0;
		while(j<m and str[i+j]==pat[j]){
			j = j+1;
		}
		if(j==m){
			return i;
		}
	}
	return -1;
}

int main(){
	string str = "ababcabdabab";
	string pat = "abd";
	cout<<bruteForce(str,pat);
	return 0;
}