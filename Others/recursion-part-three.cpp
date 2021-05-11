#include<bits/stdc++.h>
using namespace std;
 
int totalPath = 0;
void mazePath(int i,int j,int n,int m,string osf){
	// base case
	if(i==n-1 and j==m-1){
		totalPath++;
		cout<<osf<<"\n";
		return;
	}
	if(i>=n or j>=m)
		return;
 
	// recursive assumption and self work
	mazePath(i,j+1,n,m,osf+"R"); // right move
	mazePath(i+1,j,n,m,osf+"D"); // down move
	mazePath(i+1,j+1,n,m,osf+"X"); // diagonal move
}
 
void dicePath(int i,int n,string osf){
	if(i>n) return;
	if(i==n){
		totalPath++;
		cout<<osf<<"\n";
		return;
	}
 
	for(int x=1;x<=6;x++)
		dicePath(i+x,n,osf+to_string(x)+"->");
}
 
// i is current number
void lexico(int n,int i){
	// base case
	if(i>n) return;
	// self work
	cout<<i<<"\n";
	// recursive intuition
	for(int j=(i==0)?1:0;j<=9;j++){
		lexico(n,10*i+j);
	}
}
 
// input string contain no duplicate
void permutation(string str,string perm){
	if(str.size()==0){
		cout<<perm<<"\n";
		return;
	}
 
	for(int i=0;i<str.size();i++){
		char ch = str[i]; // current character
		// rest of remaining string after cutting out ch
		string ros = str.substr(0,i) + str.substr(i+1);
		permutation(ros,perm+ch);
	}
}
 
// input string contain duplicate character
void permutationduplicate(string str,string perm){
	if(str.size()==0){
		cout<<perm<<"\n";
		return;
	}
	unordered_set<char> s;
 
	for(int i=0;i<str.size();i++){
		char ch = str[i]; // current character
		if(s.count(ch)==0){
			// rest of remaining string after cutting out ch
			string ros = str.substr(0,i) + str.substr(i+1);
			s.insert(ch);
			permutationduplicate(ros,perm+ch);
		}
	}
}
 
int main(){
	permutationduplicate("AAB","");
 
	return 0;
}