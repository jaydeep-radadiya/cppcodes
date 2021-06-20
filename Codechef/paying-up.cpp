#include<bits/stdc++.h>
using namespace std;

int check(vector<int> note,int sum,int mask){
    int i = 0;
    int total = 0;
    while(mask>0){
        if(mask&1)
            total += note[i];
        i++;
        mask = mask>>1;
    }
    return total;
}

void solve(vector<int> note,int sum){
    int n = note.size();
    int range = (1<<n)-1;
    
    for(int mask=0;mask<=range;mask++){
        int sftm = check(note,sum,mask); // sfth -> sum for this mask
        
        if(sftm==sum){
            cout<<"Yes"<<"\n";
            return;
        }
    }
    cout<<"No"<<"\n";
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,sum;
        cin>>n>>sum;
        vector<int> note(n);
        for(int i=0;i<n;i++)
            cin>>note[i];
        solve(note,sum);
    }
    return 0;
}