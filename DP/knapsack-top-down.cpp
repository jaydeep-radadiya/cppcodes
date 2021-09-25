#include<bits/stdc++.h>
using namespace std;
int t[101][101];

int knapsack(int wt[],int val[],int W,int n){
	if(n==0 || W==0)
		return 0;
	if(t[n][W]!=-1)
		return t[n][W];
	if(wt[n-1]<=W)
		return t[n][W] = max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
	else
		return t[n][W] = knapsack(wt,val,W,n-1);
}

int main(){
	int wt[] = {10,20,30};
	int val[] = {60,100,120};
	int W = 50;
	int n = sizeof(wt)/sizeof(int);
	memset(t,-1,sizeof(t));
	cout<<knapsack(wt,val,W,n);
	return 0;
}