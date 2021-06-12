#include<bits/stdc++.h>
using namespace std;

int MAH(vector<int> arr,int n){
	vector<int> left;
	vector<int> right;
	stack<pair<int,int>> s;
	vector<int> width(n);

	// fill left using NSL
	for(int i=0;i<n;i++){
		if(s.size()==0)
			left.push_back(-1);
		else if(s.size()>0 && s.top().first<arr[i])
			left.push_back(s.top().second);
		else if(s.size()>0 && s.top().first>=arr[i]){
			while(s.size()>0 && s.top().first>=arr[i])
				s.pop();
			if(s.size()==0)
				left.push_back(-1);
			else
				left.push_back(s.top().second);
		}
		s.push({arr[i],i});
	}

	// clear tha stack
	while(s.size()>0)
		s.pop();

	// fill right using NSR
	for(int i=n-1;i>=0;i--){
		if(s.size()==0)
			right.push_back(n);
		else if(s.size()>0 && s.top().first<arr[i])
			right.push_back(s.top().second);
		else if(s.size()>0 && s.top().first>=arr[i]){
			while(s.size()>0 && s.top().first>=arr[i])
				s.pop();
			if(s.size()==0)
				right.push_back(n);
			else
				right.push_back(s.top().second);
		}
		s.push({arr[i],i});
	}
	reverse(right.begin(),right.end());

	// find the width
	int mx_area = INT_MIN;
	for(int i=0;i<n;i++){
		width[i] = right[i]-left[i]-1;
		mx_area = max(mx_area,width[i]*arr[i]);
	}
	return mx_area;
}

int main(){
	int r,c;
	cin>>r>>c;
	vector<vector<int>> mat(r,vector<int>(c,0));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>mat[i][j];
		}
	}

	vector<int> v(c);
	for(int j=0;j<c;j++)
		v[j] = mat[0][j];

	int mx_area = MAH(v,c);

	for(int i=1;i<r;i++){
		for(int j=0;j<c;j++){
			if(mat[i][j]==0)
				v[j] = 0;
			else
				v[j] = v[j]+mat[i][j];
		}

		int temp = MAH(v,c);
		mx_area = max(mx_area,temp);
	}

	cout<<mx_area;

	return 0;
}