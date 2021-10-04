#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    if(intervals.size()==0){
        return ans;
    }
    
    sort(intervals.begin(),intervals.end());
    vector<int> temp = intervals[0];
    
    for(auto it : intervals){
        if(it[0]<=temp[1]){
            temp[1] = max(temp[1],it[1]);
        }
        else{
            ans.push_back(temp);
            temp = it;
        }
    }
    ans.push_back(temp);
    return ans;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> intervals(n, vector<int> (2,0));

	for(int i=0;i<n;i++){
		cin>>intervals[i][0]>>intervals[i][1];
	}

	vector<vector<int>> ans = merge(intervals);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
	}

	return 0;
}