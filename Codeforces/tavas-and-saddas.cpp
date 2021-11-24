#include<iostream>
using namespace std;

int main(){
	string s;
	cin>>s;
	int len = s.size();
	int ans = (1<<len)-2;
	
	for(int i=len-1,j=0;i>=0;i--,j++){
		if(s[i]=='7'){
			ans += 1<<j;
		}
	}
	cout<<ans+1;
	return 0;
}