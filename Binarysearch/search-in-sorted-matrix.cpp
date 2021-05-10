#include<bits/stdc++.h>
using namespace std;
#define row 4
#define col 4

pair<int,int> findIndex(int arr[row][col],int val){
	int i = 0;
	int j = col-1;
	pair<int,int> p;

	while(i<row and j>=0){
		if(arr[i][j]==val){
			p = make_pair(i,j);
			return p;
		}
		else if(arr[i][j]<val)
			i++;
		else if(arr[i][j]>val)
			j--;
	}
	p = make_pair(-1,-1);
	return p;
}

int main(){
	int arr[row][col] = {
		{10,20,30,40},
		{15,25,35,45},
		{27,29,37,48},
		{32,33,39,50}
	};
	int val = 29;
	pair<int,int> output = findIndex(arr,val);
	cout<<output.first<<" "<<output.second<<"\n";
	return 0;
}

