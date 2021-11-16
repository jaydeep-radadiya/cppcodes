#include<bits/stdc++.h>
using namespace std;

// you also use long long
int powerRecursive(int a,int b) {
	if(b==0) return 1;
	int temp = powerRecursive(a,b/2);
	if(b%2==0)
		return temp*temp;
	else
		return temp*a*temp;
}

// also known as fast exponentiation
int powerIterative(int a,int b) {
	int result = 1;
	while(b>0){
		if(b%2==1) result = result*a;
		a = a*a;
		b = b/2;
	}
	return result;
}

int main(){
	cout<<powerIterative(3,5)<<"\n";
	cout<<powerRecursive(3,5)<<"\n";
	return 0;
}