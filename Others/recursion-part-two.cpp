#include<bits/stdc++.h>
using namespace std;
 
int totalWays(int n){
	// base case
	if(n==1 or n==2)
		return n;
	// recursive assumption and self work
	return totalWays(n-1)+(n-1)*totalWays(n-2);
}
 
int findPower(int a,int b){
	// base case
	if(b==0)
		return 1;
	// recursive assumption
	int temp = findPower(a,b/2);
	// self work
	if(b%2==0)
		return temp*temp;
	else
		return temp*a*temp;
}
 
void pattern(int n,int i){
	if(n==0) return;
	if(i<n){
		// print column
		cout<<"* ";
		pattern(n,i+1);
	}
	else{
		// change the row
		cout<<"\n";
		pattern(n-1,0);
	}
}
 
void homework(int n,int i,int y){
	if(n>y) return;
	if(i<n){
		// print column
		cout<<"* ";
		homework(n,i+1,y);
	}
	else{
		// change the row
		cout<<"\n";
		homework(n+1,0,y);
	}
}
 
void printSubset(int *arr,int i,int n,string osf){
	// base case
	if(i==n){
		cout<<"["<<osf<<"]"<<"\n";
		return;
	}
 
	// when we choose element to be included
	printSubset(arr,i+1,n,osf+to_string(arr[i]) + ",");
	// when we choose element not to be included
	printSubset(arr,i+1,n,osf);
}
 
void printString(int i,int n,string str){
	// base case
	if(i==n){
		str.erase(0,1);
		cout<<str<<"\n";
		return;
	}
 
	// self work and recursive assumption
	if(str[str.length()-1]=='1')
		printString(i+1,n,str+"0");
	else{
		printString(i+1,n,str+"0");
		printString(i+1,n,str+"1");
	}
}
 
bool isSorted(int arr[],int n){
	// base case
	if(n==1) return true;
	// recursive assumption and self work
	return arr[n-1]>arr[n-2] && isSorted(arr,n-1);
}
 
int main(){
	int arr[] = {1,2,3};
	int n = sizeof(arr)/sizeof(int);
	cout<<isSorted(arr,n);
 
	return 0;
}