#include<bits/stdc++.h>
using namespace std;

// O(b) --> O(log(b))
int recursive(int a,int b){
	if(b==0) return 1;
	int temp = recursive(a,b/2);
	if(b%2==0)
		return temp*temp;
	else
		return temp*a*temp;
}

int iterative(int a,int b){
	int res = 1;
	while(b>0){
		if(b%2==1) res = res*a;
		a = a*a;
		b = b/2;
	}
	return res;
}

int main(){
	cout<<recursive(3,5)<<"\n";
	cout<<iterative(3,5)<<"\n";

	return 0;
}