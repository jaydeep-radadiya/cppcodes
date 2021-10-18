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
#define PI 3.141592653589793

double f(double x, double b,double c){
	return (x*x+b*x+c)/sin(x);
}

double ts(double b,double c){
	double left = 0.0;
	double right = PI/2;

	/*
	while(right-left>1e-7){
		...
	}
	*/

	for(int i=0;i<30;i++){
		double delta = (right-left)/3;
		double mid1 = left+delta;
		double mid2 = right-delta;

		double val1 = f(mid1,b,c);
		double val2 = f(mid2,b,c);

		if(val1>val2)
			left = mid1;
		else
			right = mid2;
	}
	return f(left,b,c);
}

int main(){
	fastIO();

	int t;
	cin>>t;
	while(t--){
		double b,c;
		cin>>b>>c;
		cout<<fixed<<setprecision(10)<<ts(b,c)<<"\n";
	}

	return 0;
}