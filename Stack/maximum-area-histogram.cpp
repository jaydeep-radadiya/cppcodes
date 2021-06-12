#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];

		vector<int> left; // store index of NGL
		vector<int> right; // store index of NGR
		stack<pair<int,int>> s;
		vector<int> width(n); // store max width for element

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

		// clear the stack
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

		int mx_area = INT_MIN;
		for(int i=0;i<n;i++){
			width[i] = right[i]-left[i]-1;
			mx_area = max(mx_area,width[i]*arr[i]);
		}

		cout<<mx_area<<"\n";
	}

	return 0;
}