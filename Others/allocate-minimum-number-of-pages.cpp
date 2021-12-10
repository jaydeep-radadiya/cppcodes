#include<bits/stdc++.h>
using namespace std;
// tc : O(n*logn) sc : O(1)

bool is_valid(vector<int> &books,int students,int limit){
	int n = books.size();
	int cnt = 1;
	int sum = 0;

	for(int i=0;i<n;i++){
		if(books[i]>limit) return false;
		if(sum+books[i]>limit){
			cnt++;
			sum = 0;
		}
		sum += books[i];
	}
	if(cnt<=students) return true;
	else return false;
}

int findPages(vector<int> &books,int students){
	int left = *min_element(books.begin(),books.end());
	int right = accumulate(books.begin(),books.end(),0);
	int res = -1;

	while(left<=right){
		int mid = left+(right-left)/2;

		// check allocation is possible
		if(is_valid(books,students,mid)){
			res = mid;
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	return res;
}

int main(){
	vector<int> books = {12,34,67,90};
	int students = 2;
	cout<<findPages(books,students);
	return 0;
}