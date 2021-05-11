#include<bits/stdc++.h>
using namespace std;
 
int fact(int n){
	// base case
	if(n<=1) return 1;
	// recursive assumption
	int subproblem = fact(n-1);
	// self work
	return n*subproblem;
}
 
int fib(int n){
	// base case
	if(n==0 or n==1) return n;
	// resursive assumption
	int sp1 = fib(n-1);
	int sp2 = fib(n-2);
	// self work
	return sp1+sp2;
}
 
void printinc(int n){
	// base case
	if(n<=0) return;
	// recursive assumption
	printinc(n-1);
	// self work
	cout<<n<<" "; 
}
 
void printdec(int n){
	// base case
	if(n<=0) return;
	// self work
	cout<<n<<" ";
	// recursive assumption
	printdec(n-1);
}
 
void printdecinc(int n){
	// base case
	if(n==1){
		cout<<1<<" ";
		return;
	}
	// self work
	cout<<n<<" ";
	// recursive assumption
	printdecinc(n-1);
	// self work
	cout<<n<<" ";
}
 
// count number of binary strings with no consecutive one of length n
int count(int n){
	// base case
	if(n==1) return 2;
	else if(n==2) return 3;
	// recursive assumption
	int sp1 = count(n-1);
	int sp2 = count(n-2);
	// self work
	return sp1+sp2;
}
 
int main(){
	cout<<count(4);
 
	return 0;
}